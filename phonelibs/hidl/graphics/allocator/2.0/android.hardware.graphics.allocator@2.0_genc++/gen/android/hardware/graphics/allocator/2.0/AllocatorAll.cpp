#define LOG_TAG "android.hardware.graphics.allocator@2.0::Allocator"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/graphics/allocator/2.0/BpHwAllocator.h>
#include <android/hardware/graphics/allocator/2.0/BnHwAllocator.h>
#include <android/hardware/graphics/allocator/2.0/BsAllocator.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace graphics {
namespace allocator {
namespace V2_0 {

std::string toString(const ::android::sp<IAllocator>& o) {
    std::string os = "[class or subclass of ";
    os += IAllocator::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}

const char* IAllocator::descriptor("android.hardware.graphics.allocator@2.0::IAllocator");

__attribute__((constructor))static void static_constructor() {
    ::android::hardware::details::gBnConstructorMap.set(IAllocator::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwAllocator(static_cast<IAllocator *>(iIntf));
            });
    ::android::hardware::details::gBsConstructorMap.set(IAllocator::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsAllocator(static_cast<IAllocator *>(iIntf));
            });
};

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::gBnConstructorMap.erase(IAllocator::descriptor);
    ::android::hardware::details::gBsConstructorMap.erase(IAllocator::descriptor);
};

// Methods from IAllocator follow.
// no default implementation for: ::android::hardware::Return<void> IAllocator::dumpDebugInfo(dumpDebugInfo_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IAllocator::allocate(const ::android::hardware::hidl_vec<uint32_t>& descriptor, uint32_t count, allocate_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IAllocator::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        IAllocator::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IAllocator::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();}

::android::hardware::Return<void> IAllocator::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(IAllocator::descriptor);
    return ::android::hardware::Void();}

::android::hardware::Return<void> IAllocator::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){23,151,30,184,164,130,137,61,173,207,193,110,5,131,244,146,212,42,3,78,249,93,155,11,112,148,23,175,48,131,131,150} /* 17971eb8a482893dadcfc16e0583f492d42a034ef95d9b0b709417af30838396 */,
        (uint8_t[32]){189,218,182,24,77,122,52,109,166,160,125,192,130,140,241,154,105,111,76,170,54,17,197,31,46,20,86,90,20,180,15,217} /* bddab6184d7a346da6a07dc0828cf19a696f4caa3611c51f2e14565a14b40fd9 */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IAllocator::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IAllocator::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IAllocator::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IAllocator::getDebugInfo(getDebugInfo_cb _hidl_cb){
    _hidl_cb({ -1 /* pid */, 0 /* ptr */, 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IAllocator::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();}

::android::hardware::Return<bool> IAllocator::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


// static 
::android::hardware::Return<::android::sp<IAllocator>> IAllocator::castFrom(const ::android::sp<IAllocator>& parent, bool /* emitError */) {
    return parent;
}

// static 
::android::hardware::Return<::android::sp<IAllocator>> IAllocator::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IAllocator, ::android::hidl::base::V1_0::IBase, BpHwAllocator>(
            parent, "android.hardware.graphics.allocator@2.0::IAllocator", emitError);
}

BpHwAllocator::BpHwAllocator(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IAllocator>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.allocator@2.0", "IAllocator") {
}

// Methods from IAllocator follow.
::android::hardware::Return<void> BpHwAllocator::_hidl_dumpDebugInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, dumpDebugInfo_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    if (_hidl_cb == nullptr) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_ILLEGAL_ARGUMENT,
                "Null synchronous callback passed.");
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IAllocator::dumpDebugInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.allocator", "2.0", "IAllocator", "dumpDebugInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    const ::android::hardware::hidl_string* _hidl_out_debugInfo;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwAllocator::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* dumpDebugInfo */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    size_t _hidl__hidl_out_debugInfo_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_debugInfo), &_hidl__hidl_out_debugInfo_parent,  reinterpret_cast<const void **>(&_hidl_out_debugInfo));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*_hidl_out_debugInfo),
            _hidl_reply,
            _hidl__hidl_out_debugInfo_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(*_hidl_out_debugInfo);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)_hidl_out_debugInfo);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.allocator", "2.0", "IAllocator", "dumpDebugInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwAllocator::_hidl_allocate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint32_t>& descriptor, uint32_t count, allocate_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    if (_hidl_cb == nullptr) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_ILLEGAL_ARGUMENT,
                "Null synchronous callback passed.");
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IAllocator::allocate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&descriptor);
        _hidl_args.push_back((void *)&count);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.allocator", "2.0", "IAllocator", "allocate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::graphics::mapper::V2_0::Error _hidl_out_error;
    uint32_t _hidl_out_stride;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>* _hidl_out_buffers;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwAllocator::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_descriptor_parent;

    _hidl_err = _hidl_data.writeBuffer(&descriptor, sizeof(descriptor), &_hidl_descriptor_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_descriptor_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            descriptor,
            &_hidl_data,
            _hidl_descriptor_parent,
            0 /* parentOffset */, &_hidl_descriptor_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(count);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* allocate */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_stride);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_buffers_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_buffers), &_hidl__hidl_out_buffers_parent,  reinterpret_cast<const void **>(&_hidl_out_buffers));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_buffers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(*_hidl_out_buffers),
            _hidl_reply,
            _hidl__hidl_out_buffers_parent,
            0 /* parentOffset */, &_hidl__hidl_out_buffers_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_buffers->size(); ++_hidl_index_0) {
        const native_handle_t *_hidl__hidl_out_buffers_deref_indexed_ptr;
        _hidl_err = _hidl_reply.readNullableEmbeddedNativeHandle(
                _hidl__hidl_out_buffers_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle),
                &_hidl__hidl_out_buffers_deref_indexed_ptr
                );

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_cb(_hidl_out_error, _hidl_out_stride, *_hidl_out_buffers);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)&_hidl_out_stride);
        _hidl_args.push_back((void *)_hidl_out_buffers);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.allocator", "2.0", "IAllocator", "allocate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from IAllocator follow.
::android::hardware::Return<void> BpHwAllocator::dumpDebugInfo(dumpDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::allocator::V2_0::BpHwAllocator::_hidl_dumpDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAllocator::allocate(const ::android::hardware::hidl_vec<uint32_t>& descriptor, uint32_t count, allocate_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::allocator::V2_0::BpHwAllocator::_hidl_allocate(this, this, descriptor, count, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwAllocator::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAllocator::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAllocator::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAllocator::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAllocator::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwAllocator::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwAllocator::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAllocator::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwAllocator::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwAllocator::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    for (auto it = _hidl_mDeathRecipients.begin();it != _hidl_mDeathRecipients.end();++it) {
        if ((*it)->getRecipient() == recipient) {
            ::android::status_t status = remote()->unlinkToDeath(*it);
            _hidl_mDeathRecipients.erase(it);
            return status == ::android::OK;
        }}
    return false;
}


BnHwAllocator::BnHwAllocator(const ::android::sp<IAllocator> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.graphics.allocator@2.0", "IAllocator") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::details::gServicePrioMap.get(_hidl_impl, {SCHED_NORMAL, 0});
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
}

BnHwAllocator::~BnHwAllocator() {
    ::android::hardware::details::gBnMap.eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from IAllocator follow.
::android::status_t BnHwAllocator::_hidl_dumpDebugInfo(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwAllocator::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IAllocator::dumpDebugInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.allocator", "2.0", "IAllocator", "dumpDebugInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwAllocator*>(_hidl_this)->_hidl_mImpl->dumpDebugInfo([&](const auto &_hidl_out_debugInfo) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("dumpDebugInfo: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_debugInfo_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_debugInfo, sizeof(_hidl_out_debugInfo), &_hidl__hidl_out_debugInfo_parent);
        /* _hidl_err ignored! */

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_debugInfo,
                _hidl_reply,
                _hidl__hidl_out_debugInfo_parent,
                0 /* parentOffset */);

        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_debugInfo);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.allocator", "2.0", "IAllocator", "dumpDebugInfo", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("dumpDebugInfo: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwAllocator::_hidl_allocate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwAllocator::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint32_t>* descriptor;
    uint32_t count;

    size_t _hidl_descriptor_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*descriptor), &_hidl_descriptor_parent,  reinterpret_cast<const void **>(&descriptor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_descriptor_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*descriptor),
            _hidl_data,
            _hidl_descriptor_parent,
            0 /* parentOffset */, &_hidl_descriptor_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&count);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IAllocator::allocate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)descriptor);
        _hidl_args.push_back((void *)&count);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.allocator", "2.0", "IAllocator", "allocate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwAllocator*>(_hidl_this)->_hidl_mImpl->allocate(*descriptor, count, [&](const auto &_hidl_out_error, const auto &_hidl_out_stride, const auto &_hidl_out_buffers) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("allocate: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_stride);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_buffers_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_buffers, sizeof(_hidl_out_buffers), &_hidl__hidl_out_buffers_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_buffers_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_buffers,
                _hidl_reply,
                _hidl__hidl_out_buffers_parent,
                0 /* parentOffset */, &_hidl__hidl_out_buffers_child);

        /* _hidl_err ignored! */

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_buffers.size(); ++_hidl_index_0) {
            _hidl_err = _hidl_reply->writeEmbeddedNativeHandle(
                    _hidl_out_buffers[_hidl_index_0],
                    _hidl__hidl_out_buffers_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

            /* _hidl_err ignored! */

        }

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_stride);
            _hidl_args.push_back((void *)&_hidl_out_buffers);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.allocator", "2.0", "IAllocator", "allocate", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("allocate: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from IAllocator follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwAllocator::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwAllocator::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    _hidl_cb({
        ::android::hardware::details::debuggable()? getpid() : -1 /* pid */,
        ::android::hardware::details::debuggable()? reinterpret_cast<uint64_t>(this) : 0 /* ptr */,
        #if defined(__LP64__)
        ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
        #else
        ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
        #endif

    });
    return ::android::hardware::Void();}

::android::status_t BnHwAllocator::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* dumpDebugInfo */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::allocator::V2_0::BnHwAllocator::_hidl_dumpDebugInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* allocate */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::allocator::V2_0::BnHwAllocator::_hidl_allocate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 256067662 /* interfaceChain */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hidl::base::V1_0::BnHwBase::_hidl_interfaceChain(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 256131655 /* debug */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hidl::base::V1_0::BnHwBase::_hidl_debug(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 256136003 /* interfaceDescriptor */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hidl::base::V1_0::BnHwBase::_hidl_interfaceDescriptor(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 256398152 /* getHashChain */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hidl::base::V1_0::BnHwBase::_hidl_getHashChain(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 256462420 /* setHALInstrumentation */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != true) {
                return ::android::UNKNOWN_ERROR;
            }

            configureInstrumentation();
            break;
        }

        case 256660548 /* linkToDeath */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            break;
        }

        case 256921159 /* ping */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hidl::base::V1_0::BnHwBase::_hidl_ping(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 257049926 /* getDebugInfo */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hidl::base::V1_0::BnHwBase::_hidl_getDebugInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 257120595 /* notifySyspropsChanged */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != true) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hidl::base::V1_0::BnHwBase::_hidl_notifySyspropsChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 257250372 /* unlinkToDeath */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            break;
        }

        default:
        {
            return ::android::hidl::base::V1_0::BnHwBase::onTransact(
                    _hidl_code, _hidl_data, _hidl_reply, _hidl_flags, _hidl_cb);
        }
    }

    if (_hidl_err == ::android::UNEXPECTED_NULL) {
        _hidl_err = ::android::hardware::writeToParcel(
                ::android::hardware::Status::fromExceptionCode(::android::hardware::Status::EX_NULL_POINTER),
                _hidl_reply);
    }return _hidl_err;
}

BsAllocator::BsAllocator(const ::android::sp<IAllocator> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.allocator@2.0", "IAllocator"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsAllocator::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

// static
::android::sp<IAllocator> IAllocator::tryGetService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = ::android::hidl::manager::V1_0::IServiceManager::Transport;

    sp<IAllocator> iface = nullptr;

    const sp<::android::hidl::manager::V1_0::IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IAllocator::descriptor, serviceName);

    if (!transportRet.isOk()) {
        ALOGE("getService: defaultServiceManager()->getTransport returns %s", transportRet.description().c_str());
        return nullptr;
    }
    Transport transport = transportRet;
    const bool vintfHwbinder = (transport == Transport::HWBINDER);
    const bool vintfPassthru = (transport == Transport::PASSTHROUGH);

    #ifdef __ANDROID_TREBLE__

    #ifdef __ANDROID_DEBUGGABLE__
    const char* env = std::getenv("TREBLE_TESTING_OVERRIDE");
    const bool trebleTestingOverride =  env && !strcmp(env, "true");
    const bool vintfLegacy = (transport == Transport::EMPTY) && trebleTestingOverride;
    #else // __ANDROID_TREBLE__ but not __ANDROID_DEBUGGABLE__
    const bool trebleTestingOverride = false;
    const bool vintfLegacy = false;
    #endif // __ANDROID_DEBUGGABLE__

    #else // not __ANDROID_TREBLE__
    const char* env = std::getenv("TREBLE_TESTING_OVERRIDE");
    const bool trebleTestingOverride =  env && !strcmp(env, "true");
    const bool vintfLegacy = (transport == Transport::EMPTY);

    #endif // __ANDROID_TREBLE__

    for (int tries = 0; !getStub && (vintfHwbinder || (vintfLegacy && tries == 0)); tries++) {
        Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                sm->get(IAllocator::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IAllocator: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IAllocator: found null hwbinder interface");
            }break;
        }
        Return<sp<IAllocator>> castRet = IAllocator::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IAllocator: found dead hwbinder service");
                break;
            } else {
                ALOGW("IAllocator: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IAllocator: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<::android::hidl::manager::V1_0::IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IAllocator::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IAllocator::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsAllocator(iface);
                    }
                }
            }
        }
    }
    return iface;
}

// static
::android::sp<IAllocator> IAllocator::getService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = ::android::hidl::manager::V1_0::IServiceManager::Transport;

    sp<IAllocator> iface = nullptr;

    const sp<::android::hidl::manager::V1_0::IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IAllocator::descriptor, serviceName);

    if (!transportRet.isOk()) {
        ALOGE("getService: defaultServiceManager()->getTransport returns %s", transportRet.description().c_str());
        return nullptr;
    }
    Transport transport = transportRet;
    const bool vintfHwbinder = (transport == Transport::HWBINDER);
    const bool vintfPassthru = (transport == Transport::PASSTHROUGH);

    #ifdef __ANDROID_TREBLE__

    #ifdef __ANDROID_DEBUGGABLE__
    const char* env = std::getenv("TREBLE_TESTING_OVERRIDE");
    const bool trebleTestingOverride =  env && !strcmp(env, "true");
    const bool vintfLegacy = (transport == Transport::EMPTY) && trebleTestingOverride;
    #else // __ANDROID_TREBLE__ but not __ANDROID_DEBUGGABLE__
    const bool trebleTestingOverride = false;
    const bool vintfLegacy = false;
    #endif // __ANDROID_DEBUGGABLE__

    #else // not __ANDROID_TREBLE__
    const char* env = std::getenv("TREBLE_TESTING_OVERRIDE");
    const bool trebleTestingOverride =  env && !strcmp(env, "true");
    const bool vintfLegacy = (transport == Transport::EMPTY);

    #endif // __ANDROID_TREBLE__

    for (int tries = 0; !getStub && (vintfHwbinder || (vintfLegacy && tries == 0)); tries++) {
        if (tries > 1) {
            ALOGI("getService: Will do try %d for %s/%s in 1s...", tries, IAllocator::descriptor, serviceName.c_str());
            sleep(1);
        }
        if (vintfHwbinder && tries > 0) {
            waitForHwService(IAllocator::descriptor, serviceName);
        }
        Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                sm->get(IAllocator::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IAllocator: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IAllocator: found null hwbinder interface");
            }continue;
        }
        Return<sp<IAllocator>> castRet = IAllocator::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IAllocator: found dead hwbinder service");
                continue;
            } else {
                ALOGW("IAllocator: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IAllocator: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<::android::hidl::manager::V1_0::IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IAllocator::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IAllocator::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsAllocator(iface);
                    }
                }
            }
        }
    }
    return iface;
}

::android::status_t IAllocator::registerAsService(const std::string &serviceName) {
    ::android::hardware::details::onRegistration("android.hardware.graphics.allocator@2.0", "IAllocator", serviceName);

    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return ::android::INVALID_OPERATION;
    }
    ::android::hardware::Return<bool> ret = sm->add(serviceName.c_str(), this);
    return ret.isOk() && ret ? ::android::OK : ::android::UNKNOWN_ERROR;
}

bool IAllocator::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.graphics.allocator@2.0::IAllocator",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace allocator
}  // namespace graphics
}  // namespace hardware
}  // namespace android
