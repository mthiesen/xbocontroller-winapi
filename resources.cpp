#include "resources.h"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

ResourceData::ResourceData(int resource_id) {
    HRSRC res = ::FindResource(::GetModuleHandle(nullptr), MAKEINTRESOURCE(resource_id), RT_RCDATA);
    if (!res) {
        return;
    }

    HGLOBAL res_handle = ::LoadResource(nullptr, res);
    if (!res_handle) {
        return;
    }
    ptr = ::LockResource(res_handle);
    size = ::SizeofResource(nullptr, res);

    if (ptr == nullptr || size == 0) {
        ptr = nullptr;
        size = 0;
    }
}
