#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#include "imgui.h"

#include "resources.h"

bool load_font(float pixel_size) {
    const ResourceData font_resource(FONT_RES_ID);
    if (!font_resource.is_valid()) {
        return false;
    }

    // We need to copy the data to a new buffer because ImGui is hellbent on freeing the font data buffer
    // once it is done with it.
    char* buffer = reinterpret_cast<char*>(IM_ALLOC(font_resource.size));
    if (!buffer) {
        return false;
    }
    memcpy(buffer, font_resource.ptr, font_resource.size);

    return ImGui::GetIO().Fonts->AddFontFromMemoryTTF(buffer, font_resource.size, pixel_size) != nullptr;
}
