#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_IMAPPER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_IMAPPER_H

#include <android/hardware/graphics/common/1.0/types.h>
#include <android/hardware/graphics/mapper/2.0/types.h>
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
namespace mapper {
namespace V2_0 {

struct IMapper : public ::android::hidl::base::V1_0::IBase {
    struct BufferDescriptorInfo final {
        uint32_t width __attribute__ ((aligned(4)));
        uint32_t height __attribute__ ((aligned(4)));
        uint32_t layerCount __attribute__ ((aligned(4)));
        ::android::hardware::graphics::common::V1_0::PixelFormat format __attribute__ ((aligned(4)));
        uint64_t usage __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(IMapper::BufferDescriptorInfo, width) == 0, "wrong offset");
    static_assert(offsetof(IMapper::BufferDescriptorInfo, height) == 4, "wrong offset");
    static_assert(offsetof(IMapper::BufferDescriptorInfo, layerCount) == 8, "wrong offset");
    static_assert(offsetof(IMapper::BufferDescriptorInfo, format) == 12, "wrong offset");
    static_assert(offsetof(IMapper::BufferDescriptorInfo, usage) == 16, "wrong offset");
    static_assert(sizeof(IMapper::BufferDescriptorInfo) == 24, "wrong size");
    static_assert(__alignof(IMapper::BufferDescriptorInfo) == 8, "wrong alignment");

    struct Rect final {
        int32_t left __attribute__ ((aligned(4)));
        int32_t top __attribute__ ((aligned(4)));
        int32_t width __attribute__ ((aligned(4)));
        int32_t height __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(IMapper::Rect, left) == 0, "wrong offset");
    static_assert(offsetof(IMapper::Rect, top) == 4, "wrong offset");
    static_assert(offsetof(IMapper::Rect, width) == 8, "wrong offset");
    static_assert(offsetof(IMapper::Rect, height) == 12, "wrong offset");
    static_assert(sizeof(IMapper::Rect) == 16, "wrong size");
    static_assert(__alignof(IMapper::Rect) == 4, "wrong alignment");

    virtual bool isRemote() const override { return false; }


    using createDescriptor_cb = std::function<void(Error error, const ::android::hardware::hidl_vec<uint32_t>& descriptor)>;
    // @entry @callflow(next="*")
    virtual ::android::hardware::Return<void> createDescriptor(const IMapper::BufferDescriptorInfo& descriptorInfo, createDescriptor_cb _hidl_cb) = 0;

    using importBuffer_cb = std::function<void(Error error, void* buffer)>;
    // @entry @callflow(next="*")
    virtual ::android::hardware::Return<void> importBuffer(const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb) = 0;

    // @exit @callflow(next="*")
    virtual ::android::hardware::Return<Error> freeBuffer(void* buffer) = 0;

    using lock_cb = std::function<void(Error error, void* data)>;
    // @callflow(next="unlock")
    virtual ::android::hardware::Return<void> lock(void* buffer, uint64_t cpuUsage, const IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb) = 0;

    using lockYCbCr_cb = std::function<void(Error error, const YCbCrLayout& layout)>;
    // @callflow(next="unlock")
    virtual ::android::hardware::Return<void> lockYCbCr(void* buffer, uint64_t cpuUsage, const IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb) = 0;

    using unlock_cb = std::function<void(Error error, const ::android::hardware::hidl_handle& releaseFence)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> unlock(void* buffer, unlock_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<IMapper>> castFrom(const ::android::sp<IMapper>& parent, bool emitError = false);
    static ::android::hardware::Return<::android::sp<IMapper>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    static const char* descriptor;

    static ::android::sp<IMapper> tryGetService(const std::string &serviceName="default", bool getStub=false);
    static ::android::sp<IMapper> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    static ::android::sp<IMapper> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    static ::android::sp<IMapper> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    static ::android::sp<IMapper> getService(const std::string &serviceName="default", bool getStub=false);
    static ::android::sp<IMapper> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    static ::android::sp<IMapper> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    static ::android::sp<IMapper> getService(bool getStub) { return getService("default", getStub); }
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

std::string toString(const IMapper::BufferDescriptorInfo&);

bool operator==(const IMapper::BufferDescriptorInfo&, const IMapper::BufferDescriptorInfo&);

bool operator!=(const IMapper::BufferDescriptorInfo&, const IMapper::BufferDescriptorInfo&);

std::string toString(const IMapper::Rect&);

bool operator==(const IMapper::Rect&, const IMapper::Rect&);

bool operator!=(const IMapper::Rect&, const IMapper::Rect&);

std::string toString(const ::android::sp<IMapper>&);

}  // namespace V2_0
}  // namespace mapper
}  // namespace graphics
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_IMAPPER_H
