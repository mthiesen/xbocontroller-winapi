#pragma once

#include "winrt/Windows.Gaming.Input.h"
#include <optional>

struct GamepadVibrationFloat {
    float left_trigger = 0.0f;
    float left_motor = 0.0f;
    float right_trigger = 0.0f;
    float right_motor = 0.0f;
};

class Gamepad {
public:
    static std::optional<winrt::Windows::Gaming::Input::GamepadReading> get_reading();
    static void set_vibration(const GamepadVibrationFloat& desired_vibration);
};
