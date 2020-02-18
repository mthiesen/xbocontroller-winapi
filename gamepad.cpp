#include "gamepad.h"
#include "winrt/Windows.Foundation.Collections.h"

namespace GamingInput = winrt::Windows::Gaming::Input;

static GamingInput::Gamepad get_connected_gamepad() {
    static bool init_apartment_called = false;
    if (!init_apartment_called) {
        winrt::init_apartment();
        init_apartment_called = true;
    }

    for (auto raw_game_controller : GamingInput::RawGameController::RawGameControllers()) {
        const auto vendor_id = raw_game_controller.HardwareVendorId();
        const auto product_id = raw_game_controller.HardwareProductId();
        if (vendor_id == 1118 && product_id == 721) {
            if (GamingInput::Gamepad gamepad = GamingInput::Gamepad::FromGameController(raw_game_controller)) {
                return gamepad;
            }
        }
    }

    return nullptr;
}

std::optional<GamingInput::GamepadReading> Gamepad::get_reading() {
    auto gamepad = get_connected_gamepad();
    if (gamepad) {
        return std::optional<GamingInput::GamepadReading>(gamepad.GetCurrentReading());
    }
    else {
        return std::optional<GamingInput::GamepadReading>();
    }
}

void Gamepad::set_vibration(const GamepadVibrationFloat& desired_vibration) {
    auto gamepad = get_connected_gamepad();
    if (gamepad) {
        const GamingInput::GamepadVibration vibration = {
            desired_vibration.left_motor / 100.0f,
            desired_vibration.right_motor / 100.0f,
            desired_vibration.left_trigger / 100.0f,
            desired_vibration.right_trigger / 100.0f
        };
        gamepad.Vibration(vibration);
    }
}
