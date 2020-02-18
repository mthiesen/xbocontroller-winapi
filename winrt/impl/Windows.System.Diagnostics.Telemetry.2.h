// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.3.4.5

#ifndef WINRT_Windows_System_Diagnostics_Telemetry_2_H
#define WINRT_Windows_System_Diagnostics_Telemetry_2_H
#include "winrt/impl/Windows.System.Diagnostics.Telemetry.1.h"
WINRT_EXPORT namespace winrt::Windows::System::Diagnostics::Telemetry
{
    struct PlatformTelemetryClient
    {
        PlatformTelemetryClient() = delete;
        static auto Register(param::hstring const& id);
        static auto Register(param::hstring const& id, Windows::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings const& settings);
    };
    struct __declspec(empty_bases) PlatformTelemetryRegistrationResult : Windows::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult
    {
        PlatformTelemetryRegistrationResult(std::nullptr_t) noexcept {}
        PlatformTelemetryRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : Windows::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlatformTelemetryRegistrationSettings : Windows::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings
    {
        PlatformTelemetryRegistrationSettings(std::nullptr_t) noexcept {}
        PlatformTelemetryRegistrationSettings(void* ptr, take_ownership_from_abi_t) noexcept : Windows::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings(ptr, take_ownership_from_abi) {}
        PlatformTelemetryRegistrationSettings();
    };
}
#endif