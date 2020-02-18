#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#include <d3d11.h>
#include <tchar.h>

#include <algorithm>
#include <cstdint>

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include "resources.h"
#include "images.h"
#include "font.h"
#include "gamepad.h"

// -----------------------------------------------------------------------------

using winrt::Windows::Gaming::Input::GamepadReading;
using winrt::Windows::Gaming::Input::GamepadButtons;

// -----------------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------------

const TCHAR WINDOW_CLASS_NAME[] = _T("WinAPIXboxOneController");
const TCHAR WINDOW_TITLE[] = _T("WinAPI Xbox One Controller");
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 534;
const ImVec4 CLEAR_COLOR = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

// -----------------------------------------------------------------------------

static void waiting_for_controller_msg()
{
    const ImVec2 display_size = ImGui::GetIO().DisplaySize;
    ImGui::SetNextWindowPos(ImVec2(display_size.x * 0.5f, display_size.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowBgAlpha(0.35f);
    if (ImGui::Begin(
            "WaitingForControllerMsg",
            nullptr,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoFocusOnAppearing |
            ImGuiWindowFlags_NoNav)) {
        ImGui::Text("Waiting for Xbox One Controller to connect ...");
    }
    ImGui::End();
}

static void draw_image_centered(ID3D11ShaderResourceView* images, const Image &image)
{
    // Center image in content region of current window
    const ImVec2 content_region_min = ImGui::GetWindowContentRegionMin();
    const ImVec2 content_region_max = ImGui::GetWindowContentRegionMax();
    const ImVec2 content_region_size = ImVec2(
        content_region_max.x - content_region_min.x,
        content_region_max.y - content_region_min.y);
    const ImVec2 image_cursor_pos = ImVec2(
        content_region_min.x + (content_region_size.x - image.source_size.x) * 0.5f + image.source_pos.x,
        content_region_min.y + (content_region_size.y - image.source_size.y) * 0.5f + image.source_pos.y);
    ImGui::SetCursorPos(image_cursor_pos);

    ImGui::Image(
        images,
        image.size,
        image.uv0,
        image.uv1);
}

static void draw_image_for_button(ID3D11ShaderResourceView* images, GamepadButtons button)
{
    switch (button)
    {
    case GamepadButtons::Menu:
        draw_image_centered(images, img_menu);
        break;
    case GamepadButtons::View:
        draw_image_centered(images, img_view);
        break;
    case GamepadButtons::A:
        draw_image_centered(images, img_a);
        break;
    case GamepadButtons::B:
        draw_image_centered(images, img_b);
        break;
    case GamepadButtons::X:
        draw_image_centered(images, img_x);
        break;
    case GamepadButtons::Y:
        draw_image_centered(images, img_y);
        break;
    case GamepadButtons::DPadUp:
        draw_image_centered(images, img_dpad_up);
        break;
    case GamepadButtons::DPadDown:
        draw_image_centered(images, img_dpad_down);
        break;
    case GamepadButtons::DPadLeft:
        draw_image_centered(images, img_dpad_left);
        break;
    case GamepadButtons::DPadRight:
        draw_image_centered(images, img_dpad_right);
        break;
    case GamepadButtons::LeftShoulder:
        draw_image_centered(images, img_left_shoulder);
        break;
    case GamepadButtons::RightShoulder:
        draw_image_centered(images, img_right_shoulder);
        break;
    case GamepadButtons::LeftThumbstick:
        draw_image_centered(images, img_left_thumbstick);
        break;
    case GamepadButtons::RightThumbstick:
        draw_image_centered(images, img_right_thumbstick);
        break;
    }
}

static void analog_state(float trigger, ImVec2 stick) {
    ImGui::Text("Trigger");
    ImGui::ProgressBar(trigger);
    ImGui::Text("Thumbstick");

    ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    if (draw_list) {
        const ImVec2 content_region_avail = ImGui::GetContentRegionAvail();
        const float size = std::min(content_region_avail.x, content_region_avail.y);

        const ImVec2 bg_top_left = ImGui::GetCursorScreenPos();
        const ImVec2 bg_bottom_right = ImVec2(bg_top_left.x + size, bg_top_left.y + size);
        draw_list->AddRectFilled(bg_top_left, bg_bottom_right, ImGui::GetColorU32(ImGuiCol_FrameBg), 5.0f);

        const float MARKER_RADIUS = 10.0f;
        const float circle_radius = (size - (std::max(ImGui::GetStyle().FramePadding.x, ImGui::GetStyle().FramePadding.y) + MARKER_RADIUS) * 2.0f) * 0.5f;
        const ImVec2 center = ImVec2(bg_top_left.x + size * 0.5f, bg_top_left.y + size * 0.5f);
        
        draw_list->AddCircle(center, circle_radius, 0xffffffff, 64);
        draw_list->AddLine(center, ImVec2(center.x + circle_radius, center.y), 0xffffffff);
        draw_list->AddLine(center, ImVec2(center.x - circle_radius, center.y), 0xffffffff);
        draw_list->AddLine(center, ImVec2(center.x, center.y + circle_radius), 0xffffffff);
        draw_list->AddLine(center, ImVec2(center.x, center.y - circle_radius), 0xffffffff);

        const ImVec2 marker_pos = ImVec2(center.x + circle_radius * stick.x, center.y + circle_radius * -stick.y);
        draw_list->AddCircleFilled(marker_pos, 10.0f, ImGui::GetColorU32(ImGuiCol_SliderGrabActive), 0);
    }
}

static void controller_state(ID3D11ShaderResourceView* images, const GamepadReading& gamepad_reading, GamepadVibrationFloat& desired_vibration)
{
    const ImVec2 display_size = ImGui::GetIO().DisplaySize;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);

    const ImGuiWindowFlags flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;

    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(display_size.x * 0.5f, display_size.y));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    if (ImGui::Begin("Button States", nullptr, flags)) {
        draw_image_centered(images, img_base);

        std::uint32_t button_flags = static_cast<std::uint32_t>(gamepad_reading.Buttons);
        std::uint32_t current_mask = 1;
        while (button_flags != 0) {
            if ((button_flags & current_mask) != 0) {
                draw_image_for_button(images, static_cast<GamepadButtons>(current_mask));
                button_flags &= ~current_mask;
            }
            current_mask <<= 1;
        }
    }
    ImGui::End();
    ImGui::PopStyleVar();

    ImGui::SetNextWindowPos(ImVec2(display_size.x * 0.5f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(display_size.x * 0.25f, display_size.y * 0.68f));
    if (ImGui::Begin("Analog Left", nullptr, flags)) {
        analog_state(gamepad_reading.LeftTrigger, ImVec2(gamepad_reading.LeftThumbstickX, gamepad_reading.LeftThumbstickY));
    }
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(display_size.x * 0.75f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(display_size.x * 0.25f, display_size.y * 0.68f));
    if (ImGui::Begin("Analog Right", nullptr, flags)) {
        analog_state(gamepad_reading.RightTrigger, ImVec2(gamepad_reading.RightThumbstickX, gamepad_reading.RightThumbstickY));
    }
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(display_size.x * 0.5f, display_size.y * 0.68f));
    ImGui::SetNextWindowSize(ImVec2(display_size.x * 0.5f, display_size.y - (display_size.y * 0.68f) + 1.0f));
    if (ImGui::Begin("Vibration", nullptr, flags)) {
        ImGui::SliderFloat("Left Trigger", &desired_vibration.left_trigger, 0.0f, 100.0f, "%.f%%");
        ImGui::SliderFloat("Left Motor", &desired_vibration.left_motor, 0.0f, 100.0f, "%.f%%");
        ImGui::SliderFloat("Right Trigger", &desired_vibration.right_trigger, 0.0f, 100.0f, "%.f%%");
        ImGui::SliderFloat("Right Motor", &desired_vibration.right_motor, 0.0f, 100.0f, "%.f%%");
    }
    ImGui::End();

    ImGui::PopStyleVar();
}

// -----------------------------------------------------------------------------
// Context - RAII wrapper for ImGui Context
// -----------------------------------------------------------------------------

class Context {
public:
    Context() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
    }

    ~Context() {
        ImGui::DestroyContext();
    }
};

// -----------------------------------------------------------------------------
// Window - RAII wrapper for the WinAPI window
// -----------------------------------------------------------------------------

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Window
{
public:
    Window() {
        const WNDCLASSEX wc = {
            sizeof(WNDCLASSEX),
            CS_CLASSDC, WndProc,
            0,
            0,
            ::GetModuleHandle(nullptr),
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            WINDOW_CLASS_NAME,
            nullptr
        };
        atom = ::RegisterClassEx(&wc);
        if (!atom) {
            return;
        }

        hwnd = ::CreateWindow(
            MAKEINTATOM(atom),
            WINDOW_TITLE,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            WINDOW_WIDTH, WINDOW_HEIGHT,
            NULL,
            NULL,
            ::GetModuleHandle(nullptr),
            NULL);
        if (!hwnd) {
            return;
        }

        // The window cannot be resized or minimized.
        ::SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~(WS_SIZEBOX | WS_MAXIMIZEBOX | WS_MINIMIZEBOX));

        const HICON icon = ::LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(ICON_RES_ID));
        if (icon) {
            ::SendMessage(hwnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(icon));
            ::SendMessage(hwnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(icon));
        }

        valid = ImGui_ImplWin32_Init(hwnd);
    }

    ~Window() {
        if (atom) {
            ::UnregisterClass(MAKEINTATOM(atom), ::GetModuleHandle(nullptr));
        }

        if (hwnd) {
            ::DestroyWindow(hwnd);
        }

        if (valid) {
            ImGui_ImplWin32_Shutdown();
        }
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    operator HWND() const { return hwnd; }
    bool is_valid() const { return valid; }

private:
    HWND hwnd = 0;
    ATOM atom = 0;
    bool valid = false;
};

// -----------------------------------------------------------------------------
// D3D - RAII wrapper for the D3D device
// -----------------------------------------------------------------------------

class D3D
{
public:
    D3D(HWND hwnd) {
        DXGI_SWAP_CHAIN_DESC sd;
        ZeroMemory(&sd, sizeof(sd));
        sd.BufferCount = 2;
        sd.BufferDesc.Width = 0;
        sd.BufferDesc.Height = 0;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 60;
        sd.BufferDesc.RefreshRate.Denominator = 1;
        sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.OutputWindow = hwnd;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

        UINT create_device_flags = 0;
        const D3D_FEATURE_LEVEL feature_level_array[2] = {
            D3D_FEATURE_LEVEL_11_0,
            D3D_FEATURE_LEVEL_10_0,
        };

        if (D3D11CreateDeviceAndSwapChain(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            create_device_flags,
            feature_level_array,
            2,
            D3D11_SDK_VERSION,
            &sd,
            &swap_chain,
            &device,
            nullptr,
            &device_context) != S_OK) {
            return;
        }

        ID3D11Texture2D* back_buffer = nullptr;
        swap_chain->GetBuffer(0, IID_PPV_ARGS(&back_buffer));
        if (!back_buffer) {
            return;
        }

        device->CreateRenderTargetView(back_buffer, NULL, &render_target_view);
        back_buffer->Release();

        valid = ImGui_ImplDX11_Init(device, device_context);
    }

    ~D3D() {
        if (render_target_view) {
            render_target_view->Release();
        }

        if (swap_chain) {
            swap_chain->Release();
        }

        if (device_context) {
            device_context->Release();
        }

        if (device) {
            device->Release();
        }

        if (valid) {
            ImGui_ImplDX11_Shutdown();
        }
    }

    D3D(const D3D&) = delete;
    D3D& operator=(const D3D&) = delete;

    bool is_valid() const { return valid; }

    ID3D11Device* get_device() const { return device; }
    IDXGISwapChain* get_swap_chain() { return swap_chain; }

    void resize_render_target(unsigned int width, unsigned int height) {
        if (render_target_view) {
            render_target_view->Release();
        }

        swap_chain->ResizeBuffers(0, width, height, DXGI_FORMAT_UNKNOWN, 0);

        ID3D11Texture2D* back_buffer;
        swap_chain->GetBuffer(0, IID_PPV_ARGS(&back_buffer));
        if (back_buffer) {
            device->CreateRenderTargetView(back_buffer, NULL, &render_target_view);
            back_buffer->Release();
        }
    }

    void prepare_frame(ImVec4 clear_color) {
        device_context->OMSetRenderTargets(1, &render_target_view, nullptr);
        device_context->ClearRenderTargetView(
            render_target_view,
            reinterpret_cast<float*>(&clear_color));
    }

    void present() {
        // Present with vsync
        swap_chain->Present(1, 0);
    }

private:
    ID3D11Device* device = nullptr;
    ID3D11DeviceContext* device_context = nullptr;
    IDXGISwapChain* swap_chain = nullptr;
    ID3D11RenderTargetView* render_target_view = nullptr;
    bool valid = false;
};

// -----------------------------------------------------------------------------
// WndProc - The WinAPI window procedure
// -----------------------------------------------------------------------------

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) {
        return true;
    }

    switch (msg) {
    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED) {
            D3D* d3d = reinterpret_cast<D3D*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
            if (d3d) {
                d3d->resize_render_target(LOWORD(lParam), HIWORD(lParam));
            }
        }
        return 0;
    case WM_SYSCOMMAND:
        // Disable ALT application menu
        if ((wParam & 0xfff0) == SC_KEYMENU) {
            return 0;
        }
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }

    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

// -----------------------------------------------------------------------------

int WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
    Context context;

    // Don't save any state
    ImGui::GetIO().IniFilename = nullptr;

    // We want active windows to look the same as inactive ones
    ImGui::StyleColorsDark();
    ImGui::GetStyle().Colors[ImGuiCol_TitleBg] = ImGui::GetStyle().Colors[ImGuiCol_TitleBgActive];

    Window window;
    if (!window.is_valid()) {
        return 1;
    }

    D3D d3d(window);
    if (!d3d.is_valid()) {
        return 1;
    }

    ::SetWindowLongPtr(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&d3d));
    ::ShowWindow(window, SW_SHOWDEFAULT);
    ::UpdateWindow(window);

    if (!load_font(20.0f)) {
        return 1;
    }

    ID3D11ShaderResourceView* images = load_images(d3d.get_device());
    if (!images) {
        return 1;
    }

    GamepadVibrationFloat desired_vibration;

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT) {
        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        const auto gamepad_reading = Gamepad::get_reading();
        if (gamepad_reading.has_value())
        {
            controller_state(images, *gamepad_reading, desired_vibration);
            Gamepad::set_vibration(desired_vibration);
        }
        else
        {
            waiting_for_controller_msg();
        }

        ImGui::Render();
        d3d.prepare_frame(CLEAR_COLOR);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        d3d.present();
    }

    return 0;
}
