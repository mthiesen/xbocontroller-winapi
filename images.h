#pragma once

#include "imgui.h"

struct Image
{
    ImVec2 uv0;
    ImVec2 uv1;
    ImVec2 size;
    ImVec2 source_pos;
    ImVec2 source_size;
};

static const Image img_a{
    ImVec2(0.0049504950495049506f, 0.8132387706855791f),
    ImVec2(0.16336633663366337f, 0.9621749408983451f),
    ImVec2(64.0f, 63.0f),
    ImVec2(291.0f, 107.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_b{
    ImVec2(0.0049504950495049506f, 0.6524822695035462f),
    ImVec2(0.1608910891089109f, 0.8037825059101655f),
    ImVec2(63.0f, 64.0f),
    ImVec2(319.0f, 79.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_base{
    ImVec2(0.0049504950495049506f, 0.004728132387706856f),
    ImVec2(0.995049504950495f, 0.6430260047281324f),
    ImVec2(400.0f, 270.0f),
    ImVec2(25.0f, 28.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_dpad_down{
    ImVec2(0.7722772277227723f, 0.6524822695035462f),
    ImVec2(0.8737623762376238f, 0.75177304964539f),
    ImVec2(41.0f, 42.0f),
    ImVec2(155.0f, 170.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_left_shoulder{
    ImVec2(0.49504950495049505f, 0.7848699763593381f),
    ImVec2(0.7599009900990099f, 0.9078014184397163f),
    ImVec2(107.0f, 52.0f),
    ImVec2(76.0f, 22.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_dpad_left{
    ImVec2(0.7698019801980198f, 0.8983451536643026f),
    ImVec2(0.8737623762376238f, 0.9952718676122931f),
    ImVec2(42.0f, 41.0f),
    ImVec2(138.0f, 154.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_left_thumbstick{
    ImVec2(0.33910891089108913f, 0.8014184397163121f),
    ImVec2(0.48514851485148514f, 0.9385342789598109f),
    ImVec2(59.0f, 58.0f),
    ImVec2(98.0f, 84.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_menu{
    ImVec2(0.7698019801980198f, 0.7848699763593381f),
    ImVec2(0.8762376237623762f, 0.8888888888888888f),
    ImVec2(43.0f, 44.0f),
    ImVec2(230.0f, 89.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_right_shoulder{
    ImVec2(0.49504950495049505f, 0.6524822695035462f),
    ImVec2(0.7623762376237624f, 0.7754137115839244f),
    ImVec2(108.0f, 52.0f),
    ImVec2(264.0f, 22.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_dpad_right{
    ImVec2(0.8836633663366337f, 0.8983451536643026f),
    ImVec2(0.9876237623762376f, 0.9952718676122931f),
    ImVec2(42.0f, 41.0f),
    ImVec2(171.0f, 154.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_right_thumbstick{
    ImVec2(0.33910891089108913f, 0.6524822695035462f),
    ImVec2(0.48514851485148514f, 0.7919621749408984f),
    ImVec2(59.0f, 59.0f),
    ImVec2(248.0f, 142.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_dpad_up{
    ImVec2(0.8861386138613861f, 0.7659574468085106f),
    ImVec2(0.9876237623762376f, 0.8652482269503546f),
    ImVec2(41.0f, 42.0f),
    ImVec2(155.0f, 137.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_view{
    ImVec2(0.8861386138613861f, 0.6524822695035462f),
    ImVec2(0.9925742574257426f, 0.7565011820330969f),
    ImVec2(43.0f, 44.0f),
    ImVec2(177.0f, 89.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_x{
    ImVec2(0.17326732673267325f, 0.8108747044917257f),
    ImVec2(0.3292079207920792f, 0.9598108747044918f),
    ImVec2(63.0f, 63.0f),
    ImVec2(264.0f, 80.0f),
    ImVec2(450.0f, 326.0f),
};

static const Image img_y{
    ImVec2(0.1707920792079208f, 0.6524822695035462f),
    ImVec2(0.3292079207920792f, 0.8014184397163121f),
    ImVec2(64.0f, 63.0f),
    ImVec2(291.0f, 53.0f),
    ImVec2(450.0f, 326.0f),
};

ID3D11ShaderResourceView* load_images(ID3D11Device* device);
