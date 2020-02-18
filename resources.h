#pragma once

#include <cstddef>

#define ICON_RES_ID 1
#define IMAGES_RES_ID 5000
#define FONT_RES_ID 6000

struct ResourceData {
    ResourceData() = default;
    ResourceData(int resource_id);

    bool is_valid() const { return ptr != nullptr; }

    void* ptr = nullptr;
    std::size_t size = 0;
};
