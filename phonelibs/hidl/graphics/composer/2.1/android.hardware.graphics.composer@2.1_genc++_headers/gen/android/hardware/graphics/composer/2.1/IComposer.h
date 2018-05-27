#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_ICOMPOSER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_ICOMPOSER_H

#include <android/hardware/graphics/composer/2.1/IComposerClient.h>
#include <android/hardware/graphics/composer/2.1/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace graphics {
namespace composer {
namespace V2_1 {

struct IComposer : public ::android::hidl::base::V1_0::IBase {
    enum class Capability : int32_t {
        INVALID = 0,
        SIDEBAND_STREAM = 1,
        SKIP_CLIENT_COLOR_TRANSFORM = 2,
        PRESENT_FENCE_IS_NOT_RELIABLE = 3,
    };

    virtual bool isRemote() const override { return false; }


    using getCapabilities_cb = std::function<void(const ::android::hardware::hidl_vec<IComposer::Capability>& capabilities)>;
    // @entry @exit @callflow(next="*")
    virtual ::android::hardware::Return<void> getCapabilities(getCapabilities_cb _hidl_cb) = 0;

    using dumpDebugInfo_cb = std::function<void(const ::android::hardware::hidl_string& debugInfo)>;
    // @entry @exit @callflow(next="*")
    virtual ::android::hardware::Return<void> dumpDebugInfo(dumpDebugInfo_cb _hidl_cb) = 0;

    using createClient_cb = std::function<void(Error error, const ::android::sp<IComposerClient>& client)>;
    // @entry @callflow(next="*")
    virtual ::android::hardware::Return<void> createClient(createClient_cb _hidl_cb) = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    virtual ::android::hardware::Return<void> ping() override;

    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;
    // cast static functions
    static ::android::hardware::Return<::android::sp<IComposer>> castFrom(const ::android::sp<IComposer>& parent, bool emitError = false);
    static ::android::hardware::Return<::android::sp<IComposer>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    static const char* descriptor;

    static ::android::sp<IComposer> tryGetService(const std::string &serviceName="default", bool getStub=false);
    static ::android::sp<IComposer> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    static ::android::sp<IComposer> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    static ::android::sp<IComposer> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    static ::android::sp<IComposer> getService(const std::string &serviceName="default", bool getStub=false);
    static ::android::sp<IComposer> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    static ::android::sp<IComposer> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    static ::android::sp<IComposer> getService(bool getStub) { return getService("default", getStub); }
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

constexpr int32_t operator|(const IComposer::Capability lhs, const IComposer::Capability rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposer::Capability rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposer::Capability lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposer::Capability lhs, const IComposer::Capability rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposer::Capability rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposer::Capability lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposer::Capability e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposer::Capability e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposer::Capability>(int32_t o);

std::string toString(IComposer::Capability o);

std::string toString(const ::android::sp<IComposer>&);

}  // namespace V2_1
}  // namespace composer
}  // namespace graphics
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_ICOMPOSER_H
