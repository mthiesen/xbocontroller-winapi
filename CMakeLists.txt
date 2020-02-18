cmake_minimum_required(VERSION 3.15)
project(XboxOneControllerTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(XboxOneControllerTest
        WIN32
        main.cpp
        font.cpp
        images.cpp
        gamepad.cpp
        resources.cpp
        resources.rc
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_widgets.cpp
        imgui/examples/imgui_impl_dx11.cpp
        imgui/examples/imgui_impl_win32.cpp)
set_property(TARGET XboxOneControllerTest PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
add_compile_definitions(IMGUI_IMPL_WIN32_DISABLE_GAMEPAD)
target_include_directories(XboxOneControllerTest PRIVATE imgui)
target_include_directories(XboxOneControllerTest PRIVATE imgui/examples)
target_link_libraries(XboxOneControllerTest D3D11.lib)
