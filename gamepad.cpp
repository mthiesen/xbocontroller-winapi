#include "gamepad.h"

#include "winrt/Windows.Foundation.Collections.h"

#include <array>
#include <algorithm>

namespace GamingInput = winrt::Windows::Gaming::Input;

static GamingInput::Gamepad get_connected_gamepad() {
    static bool init_apartment_called = false;
    if (!init_apartment_called) {
        winrt::init_apartment();
        init_apartment_called = true;
    }

    const std::uint16_t MICROSOFT_VENDOR_ID = 0x045E;
    const std::array<std::uint16_t, 5> XBOX_ONE_CONTROLLER_PRODUCT_IDS = {
        0x02D1, // Xbox One Controller
        0x02DD, // Xbox One Controller(Firmware 2015)
        0x02E3, // Xbox One Elite Controller
        0x02EA, // Xbox One S Controller
        0x02FD, // Xbox One S Controller[Bluetooth]
    };

    for (auto raw_game_controller : GamingInput::RawGameController::RawGameControllers()) {
        const auto vendor_id = raw_game_controller.HardwareVendorId();
        const auto product_id = raw_game_controller.HardwareProductId();
        if (vendor_id == 1118 &&
            std::find(XBOX_ONE_CONTROLLER_PRODUCT_IDS.begin(), XBOX_ONE_CONTROLLER_PRODUCT_IDS.end(), product_id) != XBOX_ONE_CONTROLLER_PRODUCT_IDS.end()) {
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
