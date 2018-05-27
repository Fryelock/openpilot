#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_BPHWMAPPER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_BPHWMAPPER_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/graphics/mapper/2.0/IHwMapper.h>

namespace android {
namespace hardware {
namespace graphics {
namespace mapper {
namespace V2_0 {

struct BpHwMapper : public ::android::hardware::BpInterface<IMapper>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwMapper(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    typedef IMapper Pure;

    virtual bool isRemote() const override { return true; }

    // Methods from IMapper follow.
    static ::android::hardware::Return<void>  _hidl_createDescriptor(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const IMapper::BufferDescriptorInfo& descriptorInfo, createDescriptor_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_importBuffer(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb);
    static ::android::hardware::Return<Error>  _hidl_freeBuffer(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer);
    static ::android::hardware::Return<void>  _hidl_lock(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, uint64_t cpuUsage, const IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_lockYCbCr(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, uint64_t cpuUsage, const IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_unlock(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, void* buffer, unlock_cb _hidl_cb);

    // Methods from IMapper follow.
    ::android::hardware::Return<void> createDescriptor(const IMapper::BufferDescriptorInfo& descriptorInfo, createDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> importBuffer(const ::android::hardware::hidl_handle& rawHandle, importBuffer_cb _hidl_cb) override;
    ::android::hardware::Return<Error> freeBuffer(void* buffer) override;
    ::android::hardware::Return<void> lock(void* buffer, uint64_t cpuUsage, const IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lock_cb _hidl_cb) override;
    ::android::hardware::Return<void> lockYCbCr(void* buffer, uint64_t cpuUsage, const IMapper::Rect& accessRegion, const ::android::hardware::hidl_handle& acquireFence, lockYCbCr_cb _hidl_cb) override;
    ::android::hardware::Return<void> unlock(void* buffer, unlock_cb _hidl_cb) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V2_0
}  // namespace mapper
}  // namespace graphics
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_BPHWMAPPER_H
