// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.3.4.5

#ifndef WINRT_Windows_Security_Credentials_0_H
#define WINRT_Windows_Security_Credentials_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct IAsyncAction;
    template <typename TResult> struct IAsyncOperation;
    struct Uri;
}
WINRT_EXPORT namespace winrt::Windows::Foundation::Collections
{
    template <typename K, typename V> struct IMapView;
    struct IPropertySet;
    template <typename T> struct IVectorView;
}
WINRT_EXPORT namespace winrt::Windows::Security::Cryptography::Core
{
    enum class CryptographicPublicKeyBlobType : int32_t;
}
WINRT_EXPORT namespace winrt::Windows::Storage::Streams
{
    struct IBuffer;
    struct IRandomAccessStream;
}
WINRT_EXPORT namespace winrt::Windows::System
{
    struct User;
}
WINRT_EXPORT namespace winrt::Windows::Security::Credentials
{
    enum class KeyCredentialAttestationStatus : int32_t
    {
        Success = 0,
        UnknownError = 1,
        NotSupported = 2,
        TemporaryFailure = 3,
    };
    enum class KeyCredentialCreationOption : int32_t
    {
        ReplaceExisting = 0,
        FailIfExists = 1,
    };
    enum class KeyCredentialStatus : int32_t
    {
        Success = 0,
        UnknownError = 1,
        NotFound = 2,
        UserCanceled = 3,
        UserPrefersPassword = 4,
        CredentialAlreadyExists = 5,
        SecurityDeviceLocked = 6,
    };
    enum class WebAccountPictureSize : int32_t
    {
        Size64x64 = 64,
        Size208x208 = 208,
        Size424x424 = 424,
        Size1080x1080 = 1080,
    };
    enum class WebAccountState : int32_t
    {
        None = 0,
        Connected = 1,
        Error = 2,
    };
    struct ICredentialFactory;
    struct IKeyCredential;
    struct IKeyCredentialAttestationResult;
    struct IKeyCredentialManagerStatics;
    struct IKeyCredentialOperationResult;
    struct IKeyCredentialRetrievalResult;
    struct IPasswordCredential;
    struct IPasswordVault;
    struct IWebAccount;
    struct IWebAccount2;
    struct IWebAccountFactory;
    struct IWebAccountProvider;
    struct IWebAccountProvider2;
    struct IWebAccountProvider3;
    struct IWebAccountProvider4;
    struct IWebAccountProviderFactory;
    struct KeyCredential;
    struct KeyCredentialAttestationResult;
    struct KeyCredentialManager;
    struct KeyCredentialOperationResult;
    struct KeyCredentialRetrievalResult;
    struct PasswordCredential;
    struct PasswordCredentialPropertyStore;
    struct PasswordVault;
    struct WebAccount;
    struct WebAccountProvider;
}
namespace winrt::impl
{
    template <> struct category<Windows::Security::Credentials::ICredentialFactory>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IKeyCredential>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IKeyCredentialAttestationResult>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IKeyCredentialManagerStatics>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IKeyCredentialOperationResult>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IKeyCredentialRetrievalResult>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IPasswordCredential>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IPasswordVault>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IWebAccount>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IWebAccount2>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IWebAccountFactory>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IWebAccountProvider>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IWebAccountProvider2>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IWebAccountProvider3>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IWebAccountProvider4>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::IWebAccountProviderFactory>{ using type = interface_category; };
    template <> struct category<Windows::Security::Credentials::KeyCredential>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::KeyCredentialAttestationResult>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::KeyCredentialManager>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::KeyCredentialOperationResult>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::KeyCredentialRetrievalResult>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::PasswordCredential>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::PasswordCredentialPropertyStore>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::PasswordVault>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::WebAccount>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::WebAccountProvider>{ using type = class_category; };
    template <> struct category<Windows::Security::Credentials::KeyCredentialAttestationStatus>{ using type = enum_category; };
    template <> struct category<Windows::Security::Credentials::KeyCredentialCreationOption>{ using type = enum_category; };
    template <> struct category<Windows::Security::Credentials::KeyCredentialStatus>{ using type = enum_category; };
    template <> struct category<Windows::Security::Credentials::WebAccountPictureSize>{ using type = enum_category; };
    template <> struct category<Windows::Security::Credentials::WebAccountState>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::KeyCredential> = L"Windows.Security.Credentials.KeyCredential";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::KeyCredentialAttestationResult> = L"Windows.Security.Credentials.KeyCredentialAttestationResult";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::KeyCredentialManager> = L"Windows.Security.Credentials.KeyCredentialManager";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::KeyCredentialOperationResult> = L"Windows.Security.Credentials.KeyCredentialOperationResult";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::KeyCredentialRetrievalResult> = L"Windows.Security.Credentials.KeyCredentialRetrievalResult";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::PasswordCredential> = L"Windows.Security.Credentials.PasswordCredential";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::PasswordCredentialPropertyStore> = L"Windows.Security.Credentials.PasswordCredentialPropertyStore";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::PasswordVault> = L"Windows.Security.Credentials.PasswordVault";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::WebAccount> = L"Windows.Security.Credentials.WebAccount";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::WebAccountProvider> = L"Windows.Security.Credentials.WebAccountProvider";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::KeyCredentialAttestationStatus> = L"Windows.Security.Credentials.KeyCredentialAttestationStatus";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::KeyCredentialCreationOption> = L"Windows.Security.Credentials.KeyCredentialCreationOption";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::KeyCredentialStatus> = L"Windows.Security.Credentials.KeyCredentialStatus";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::WebAccountPictureSize> = L"Windows.Security.Credentials.WebAccountPictureSize";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::WebAccountState> = L"Windows.Security.Credentials.WebAccountState";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::ICredentialFactory> = L"Windows.Security.Credentials.ICredentialFactory";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IKeyCredential> = L"Windows.Security.Credentials.IKeyCredential";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IKeyCredentialAttestationResult> = L"Windows.Security.Credentials.IKeyCredentialAttestationResult";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IKeyCredentialManagerStatics> = L"Windows.Security.Credentials.IKeyCredentialManagerStatics";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IKeyCredentialOperationResult> = L"Windows.Security.Credentials.IKeyCredentialOperationResult";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IKeyCredentialRetrievalResult> = L"Windows.Security.Credentials.IKeyCredentialRetrievalResult";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IPasswordCredential> = L"Windows.Security.Credentials.IPasswordCredential";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IPasswordVault> = L"Windows.Security.Credentials.IPasswordVault";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IWebAccount> = L"Windows.Security.Credentials.IWebAccount";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IWebAccount2> = L"Windows.Security.Credentials.IWebAccount2";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IWebAccountFactory> = L"Windows.Security.Credentials.IWebAccountFactory";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IWebAccountProvider> = L"Windows.Security.Credentials.IWebAccountProvider";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IWebAccountProvider2> = L"Windows.Security.Credentials.IWebAccountProvider2";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IWebAccountProvider3> = L"Windows.Security.Credentials.IWebAccountProvider3";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IWebAccountProvider4> = L"Windows.Security.Credentials.IWebAccountProvider4";
    template <> inline constexpr auto& name_v<Windows::Security::Credentials::IWebAccountProviderFactory> = L"Windows.Security.Credentials.IWebAccountProviderFactory";
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::ICredentialFactory>{ 0x54EF13A1,0xBF26,0x47B5,{ 0x97,0xDD,0xDE,0x77,0x9B,0x7C,0xAD,0x58 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IKeyCredential>{ 0x9585EF8D,0x457B,0x4847,{ 0xB1,0x1A,0xFA,0x96,0x0B,0xBD,0xB1,0x38 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IKeyCredentialAttestationResult>{ 0x78AAB3A1,0xA3C1,0x4103,{ 0xB6,0xCC,0x47,0x2C,0x44,0x17,0x1C,0xBB } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IKeyCredentialManagerStatics>{ 0x6AAC468B,0x0EF1,0x4CE0,{ 0x82,0x90,0x41,0x06,0xDA,0x6A,0x63,0xB5 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IKeyCredentialOperationResult>{ 0xF53786C1,0x5261,0x4CDD,{ 0x97,0x6D,0xCC,0x90,0x9A,0xC7,0x16,0x20 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IKeyCredentialRetrievalResult>{ 0x58CD7703,0x8D87,0x4249,{ 0x9B,0x58,0xF6,0x59,0x8C,0xC9,0x64,0x4E } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IPasswordCredential>{ 0x6AB18989,0xC720,0x41A7,{ 0xA6,0xC1,0xFE,0xAD,0xB3,0x63,0x29,0xA0 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IPasswordVault>{ 0x61FD2C0B,0xC8D4,0x48C1,{ 0xA5,0x4F,0xBC,0x5A,0x64,0x20,0x5A,0xF2 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IWebAccount>{ 0x69473EB2,0x8031,0x49BE,{ 0x80,0xBB,0x96,0xCB,0x46,0xD9,0x9A,0xBA } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IWebAccount2>{ 0x7B56D6F8,0x990B,0x4EB5,{ 0x94,0xA7,0x56,0x21,0xF3,0xA8,0xB8,0x24 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IWebAccountFactory>{ 0xAC9AFB39,0x1DE9,0x4E92,{ 0xB7,0x8F,0x05,0x81,0xA8,0x7F,0x6E,0x5C } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IWebAccountProvider>{ 0x29DCC8C3,0x7AB9,0x4A7C,{ 0xA3,0x36,0xB9,0x42,0xF9,0xDB,0xF7,0xC7 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IWebAccountProvider2>{ 0x4A01EB05,0x4E42,0x41D4,{ 0xB5,0x18,0xE0,0x08,0xA5,0x16,0x36,0x14 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IWebAccountProvider3>{ 0xDA1C518B,0x970D,0x4D49,{ 0x82,0x5C,0xF2,0x70,0x6F,0x8C,0xA7,0xFE } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IWebAccountProvider4>{ 0x718FD8DB,0xE796,0x4210,{ 0xB7,0x4E,0x84,0xD2,0x98,0x94,0xB0,0x80 } };
    template <> inline constexpr guid guid_v<Windows::Security::Credentials::IWebAccountProviderFactory>{ 0x1D767DF1,0xE1E1,0x4B9A,{ 0xA7,0x74,0x5C,0x7C,0x7E,0x3B,0xF3,0x71 } };
    template <> struct default_interface<Windows::Security::Credentials::KeyCredential>{ using type = Windows::Security::Credentials::IKeyCredential; };
    template <> struct default_interface<Windows::Security::Credentials::KeyCredentialAttestationResult>{ using type = Windows::Security::Credentials::IKeyCredentialAttestationResult; };
    template <> struct default_interface<Windows::Security::Credentials::KeyCredentialOperationResult>{ using type = Windows::Security::Credentials::IKeyCredentialOperationResult; };
    template <> struct default_interface<Windows::Security::Credentials::KeyCredentialRetrievalResult>{ using type = Windows::Security::Credentials::IKeyCredentialRetrievalResult; };
    template <> struct default_interface<Windows::Security::Credentials::PasswordCredential>{ using type = Windows::Security::Credentials::IPasswordCredential; };
    template <> struct default_interface<Windows::Security::Credentials::PasswordCredentialPropertyStore>{ using type = Windows::Foundation::Collections::IPropertySet; };
    template <> struct default_interface<Windows::Security::Credentials::PasswordVault>{ using type = Windows::Security::Credentials::IPasswordVault; };
    template <> struct default_interface<Windows::Security::Credentials::WebAccount>{ using type = Windows::Security::Credentials::IWebAccount; };
    template <> struct default_interface<Windows::Security::Credentials::WebAccountProvider>{ using type = Windows::Security::Credentials::IWebAccountProvider; };
    template <> struct abi<Windows::Security::Credentials::ICredentialFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreatePasswordCredential(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IKeyCredential>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall RetrievePublicKeyWithDefaultBlobType(void**) noexcept = 0;
            virtual int32_t __stdcall RetrievePublicKeyWithBlobType(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestSignAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAttestationAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IKeyCredentialAttestationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CertificateChainBuffer(void**) noexcept = 0;
            virtual int32_t __stdcall get_AttestationBuffer(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IKeyCredentialManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupportedAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RenewAttestationAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestCreateAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall OpenAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IKeyCredentialOperationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Result(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IKeyCredentialRetrievalResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Credential(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IPasswordCredential>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Resource(void**) noexcept = 0;
            virtual int32_t __stdcall put_Resource(void*) noexcept = 0;
            virtual int32_t __stdcall get_UserName(void**) noexcept = 0;
            virtual int32_t __stdcall put_UserName(void*) noexcept = 0;
            virtual int32_t __stdcall get_Password(void**) noexcept = 0;
            virtual int32_t __stdcall put_Password(void*) noexcept = 0;
            virtual int32_t __stdcall RetrievePassword() noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IPasswordVault>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Add(void*) noexcept = 0;
            virtual int32_t __stdcall Remove(void*) noexcept = 0;
            virtual int32_t __stdcall Retrieve(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAllByResource(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAllByUserName(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RetrieveAll(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IWebAccount>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_WebAccountProvider(void**) noexcept = 0;
            virtual int32_t __stdcall get_UserName(void**) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IWebAccount2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
            virtual int32_t __stdcall GetPictureAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SignOutAsync(void**) noexcept = 0;
            virtual int32_t __stdcall SignOutWithClientIdAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IWebAccountFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWebAccount(void*, void*, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IWebAccountProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_IconUri(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IWebAccountProvider2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayPurpose(void**) noexcept = 0;
            virtual int32_t __stdcall get_Authority(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IWebAccountProvider3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IWebAccountProvider4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSystemProvider(bool*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Security::Credentials::IWebAccountProviderFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWebAccountProvider(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_ICredentialFactory
    {
        WINRT_IMPL_AUTO(Windows::Security::Credentials::PasswordCredential) CreatePasswordCredential(param::hstring const& resource, param::hstring const& userName, param::hstring const& password) const;
    };
    template <> struct consume<Windows::Security::Credentials::ICredentialFactory>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_ICredentialFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IKeyCredential
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Name() const;
        WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) RetrievePublicKey() const;
        WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) RetrievePublicKey(Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType const& blobType) const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialOperationResult>) RequestSignAsync(Windows::Storage::Streams::IBuffer const& data) const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialAttestationResult>) GetAttestationAsync() const;
    };
    template <> struct consume<Windows::Security::Credentials::IKeyCredential>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IKeyCredential<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IKeyCredentialAttestationResult
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) CertificateChainBuffer() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) AttestationBuffer() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Security::Credentials::KeyCredentialAttestationStatus) Status() const;
    };
    template <> struct consume<Windows::Security::Credentials::IKeyCredentialAttestationResult>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IKeyCredentialAttestationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IKeyCredentialManagerStatics
    {
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<bool>) IsSupportedAsync() const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncAction) RenewAttestationAsync() const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult>) RequestCreateAsync(param::hstring const& name, Windows::Security::Credentials::KeyCredentialCreationOption const& option) const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult>) OpenAsync(param::hstring const& name) const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncAction) DeleteAsync(param::hstring const& name) const;
    };
    template <> struct consume<Windows::Security::Credentials::IKeyCredentialManagerStatics>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IKeyCredentialManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IKeyCredentialOperationResult
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) Result() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Security::Credentials::KeyCredentialStatus) Status() const;
    };
    template <> struct consume<Windows::Security::Credentials::IKeyCredentialOperationResult>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IKeyCredentialOperationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IKeyCredentialRetrievalResult
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Security::Credentials::KeyCredential) Credential() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Security::Credentials::KeyCredentialStatus) Status() const;
    };
    template <> struct consume<Windows::Security::Credentials::IKeyCredentialRetrievalResult>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IKeyCredentialRetrievalResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IPasswordCredential
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Resource() const;
        WINRT_IMPL_AUTO(void) Resource(param::hstring const& resource) const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) UserName() const;
        WINRT_IMPL_AUTO(void) UserName(param::hstring const& userName) const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Password() const;
        WINRT_IMPL_AUTO(void) Password(param::hstring const& password) const;
        WINRT_IMPL_AUTO(void) RetrievePassword() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Foundation::Collections::IPropertySet) Properties() const;
    };
    template <> struct consume<Windows::Security::Credentials::IPasswordCredential>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IPasswordCredential<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IPasswordVault
    {
        WINRT_IMPL_AUTO(void) Add(Windows::Security::Credentials::PasswordCredential const& credential) const;
        WINRT_IMPL_AUTO(void) Remove(Windows::Security::Credentials::PasswordCredential const& credential) const;
        WINRT_IMPL_AUTO(Windows::Security::Credentials::PasswordCredential) Retrieve(param::hstring const& resource, param::hstring const& userName) const;
        WINRT_IMPL_AUTO(Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential>) FindAllByResource(param::hstring const& resource) const;
        WINRT_IMPL_AUTO(Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential>) FindAllByUserName(param::hstring const& userName) const;
        WINRT_IMPL_AUTO(Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential>) RetrieveAll() const;
    };
    template <> struct consume<Windows::Security::Credentials::IPasswordVault>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IPasswordVault<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IWebAccount
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Security::Credentials::WebAccountProvider) WebAccountProvider() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) UserName() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Security::Credentials::WebAccountState) State() const;
    };
    template <> struct consume<Windows::Security::Credentials::IWebAccount>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IWebAccount<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IWebAccount2
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Foundation::Collections::IMapView<hstring, hstring>) Properties() const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>) GetPictureAsync(Windows::Security::Credentials::WebAccountPictureSize const& desizedSize) const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncAction) SignOutAsync() const;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncAction) SignOutAsync(param::hstring const& clientId) const;
    };
    template <> struct consume<Windows::Security::Credentials::IWebAccount2>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IWebAccount2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IWebAccountFactory
    {
        WINRT_IMPL_AUTO(Windows::Security::Credentials::WebAccount) CreateWebAccount(Windows::Security::Credentials::WebAccountProvider const& webAccountProvider, param::hstring const& userName, Windows::Security::Credentials::WebAccountState const& state) const;
    };
    template <> struct consume<Windows::Security::Credentials::IWebAccountFactory>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IWebAccountFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IWebAccountProvider
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Foundation::Uri) IconUri() const;
    };
    template <> struct consume<Windows::Security::Credentials::IWebAccountProvider>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IWebAccountProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IWebAccountProvider2
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) DisplayPurpose() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Authority() const;
    };
    template <> struct consume<Windows::Security::Credentials::IWebAccountProvider2>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IWebAccountProvider2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IWebAccountProvider3
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::System::User) User() const;
    };
    template <> struct consume<Windows::Security::Credentials::IWebAccountProvider3>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IWebAccountProvider3<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IWebAccountProvider4
    {
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsSystemProvider() const;
    };
    template <> struct consume<Windows::Security::Credentials::IWebAccountProvider4>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IWebAccountProvider4<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Credentials_IWebAccountProviderFactory
    {
        WINRT_IMPL_AUTO(Windows::Security::Credentials::WebAccountProvider) CreateWebAccountProvider(param::hstring const& id, param::hstring const& displayName, Windows::Foundation::Uri const& iconUri) const;
    };
    template <> struct consume<Windows::Security::Credentials::IWebAccountProviderFactory>
    {
        template <typename D> using type = consume_Windows_Security_Credentials_IWebAccountProviderFactory<D>;
    };
}
#endif
