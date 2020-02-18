// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.3.4.5

#ifndef WINRT_Windows_ApplicationModel_ConversationalAgent_2_H
#define WINRT_Windows_ApplicationModel_ConversationalAgent_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.ApplicationModel.ConversationalAgent.1.h"
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::ConversationalAgent
{
    struct __declspec(empty_bases) ConversationalAgentSession : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSession,
        impl::require<ConversationalAgentSession, Windows::Foundation::IClosable>
    {
        ConversationalAgentSession(std::nullptr_t) noexcept {}
        ConversationalAgentSession(void* ptr, take_ownership_from_abi_t) noexcept : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSession(ptr, take_ownership_from_abi) {}
        static auto GetCurrentSessionAsync();
        static auto GetCurrentSessionSync();
    };
    struct __declspec(empty_bases) ConversationalAgentSessionInterruptedEventArgs : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs
    {
        ConversationalAgentSessionInterruptedEventArgs(std::nullptr_t) noexcept {}
        ConversationalAgentSessionInterruptedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConversationalAgentSignal : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSignal
    {
        ConversationalAgentSignal(std::nullptr_t) noexcept {}
        ConversationalAgentSignal(void* ptr, take_ownership_from_abi_t) noexcept : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSignal(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConversationalAgentSignalDetectedEventArgs : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs
    {
        ConversationalAgentSignalDetectedEventArgs(std::nullptr_t) noexcept {}
        ConversationalAgentSignalDetectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConversationalAgentSystemStateChangedEventArgs : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs
    {
        ConversationalAgentSystemStateChangedEventArgs(std::nullptr_t) noexcept {}
        ConversationalAgentSystemStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : Windows::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
