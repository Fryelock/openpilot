#define LOG_TAG "android.hardware.media.omx@1.0::OmxNode"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/media/omx/1.0/BpHwOmxNode.h>
#include <android/hardware/media/omx/1.0/BnHwOmxNode.h>
#include <android/hardware/media/omx/1.0/BsOmxNode.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace media {
namespace omx {
namespace V1_0 {

std::string toString(const ::android::sp<IOmxNode>& o) {
    std::string os = "[class or subclass of ";
    os += IOmxNode::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}

const char* IOmxNode::descriptor("android.hardware.media.omx@1.0::IOmxNode");

__attribute__((constructor))static void static_constructor() {
    ::android::hardware::details::gBnConstructorMap.set(IOmxNode::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwOmxNode(static_cast<IOmxNode *>(iIntf));
            });
    ::android::hardware::details::gBsConstructorMap.set(IOmxNode::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsOmxNode(static_cast<IOmxNode *>(iIntf));
            });
};

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::gBnConstructorMap.erase(IOmxNode::descriptor);
    ::android::hardware::details::gBsConstructorMap.erase(IOmxNode::descriptor);
};

// Methods from IOmxNode follow.
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::freeNode()
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::sendCommand(uint32_t cmd, int32_t param)
// no default implementation for: ::android::hardware::Return<void> IOmxNode::getParameter(uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& inParams, getParameter_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::setParameter(uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& params)
// no default implementation for: ::android::hardware::Return<void> IOmxNode::getConfig(uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& inConfig, getConfig_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::setConfig(uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& config)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::setPortMode(uint32_t portIndex, PortMode mode)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::prepareForAdaptivePlayback(uint32_t portIndex, bool enable, uint32_t maxFrameWidth, uint32_t maxFrameHeight)
// no default implementation for: ::android::hardware::Return<void> IOmxNode::configureVideoTunnelMode(uint32_t portIndex, bool tunneled, uint32_t audioHwSync, configureVideoTunnelMode_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IOmxNode::getGraphicBufferUsage(uint32_t portIndex, getGraphicBufferUsage_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::setInputSurface(const ::android::sp<IOmxBufferSource>& bufferSource)
// no default implementation for: ::android::hardware::Return<void> IOmxNode::allocateSecureBuffer(uint32_t portIndex, uint64_t size, allocateSecureBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IOmxNode::useBuffer(uint32_t portIndex, const CodecBuffer& omxBuffer, useBuffer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::freeBuffer(uint32_t portIndex, uint32_t buffer)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::fillBuffer(uint32_t buffer, const CodecBuffer& omxBuffer, const ::android::hardware::hidl_handle& fence)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::emptyBuffer(uint32_t buffer, const CodecBuffer& omxBuffer, uint32_t flags, uint64_t timestampUs, const ::android::hardware::hidl_handle& fence)
// no default implementation for: ::android::hardware::Return<void> IOmxNode::getExtensionIndex(const ::android::hardware::hidl_string& parameterName, getExtensionIndex_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Status> IOmxNode::dispatchMessage(const Message& msg)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IOmxNode::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        IOmxNode::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IOmxNode::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();}

::android::hardware::Return<void> IOmxNode::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(IOmxNode::descriptor);
    return ::android::hardware::Void();}

::android::hardware::Return<void> IOmxNode::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){129,173,141,139,177,207,111,65,146,60,241,29,211,147,84,168,254,67,61,178,132,162,52,204,103,93,231,231,90,130,34,76} /* 81ad8d8bb1cf6f41923cf11dd39354a8fe433db284a234cc675de7e75a82224c */,
        (uint8_t[32]){189,218,182,24,77,122,52,109,166,160,125,192,130,140,241,154,105,111,76,170,54,17,197,31,46,20,86,90,20,180,15,217} /* bddab6184d7a346da6a07dc0828cf19a696f4caa3611c51f2e14565a14b40fd9 */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IOmxNode::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IOmxNode::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IOmxNode::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IOmxNode::getDebugInfo(getDebugInfo_cb _hidl_cb){
    _hidl_cb({ -1 /* pid */, 0 /* ptr */, 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IOmxNode::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();}

::android::hardware::Return<bool> IOmxNode::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


// static 
::android::hardware::Return<::android::sp<IOmxNode>> IOmxNode::castFrom(const ::android::sp<IOmxNode>& parent, bool /* emitError */) {
    return parent;
}

// static 
::android::hardware::Return<::android::sp<IOmxNode>> IOmxNode::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IOmxNode, ::android::hidl::base::V1_0::IBase, BpHwOmxNode>(
            parent, "android.hardware.media.omx@1.0::IOmxNode", emitError);
}

BpHwOmxNode::BpHwOmxNode(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IOmxNode>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.media.omx@1.0", "IOmxNode") {
}

// Methods from IOmxNode follow.
::android::hardware::Return<Status> BpHwOmxNode::_hidl_freeNode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::freeNode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "freeNode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* freeNode */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "freeNode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_sendCommand(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t cmd, int32_t param) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::sendCommand::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmd);
        _hidl_args.push_back((void *)&param);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "sendCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(cmd);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(param);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* sendCommand */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "sendCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxNode::_hidl_getParameter(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& inParams, getParameter_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::getParameter::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)&inParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "getParameter", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;
    const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_outParams;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(index);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&inParams, sizeof(inParams), &_hidl_inParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inParams,
            &_hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* getParameter */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_outParams_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outParams), &_hidl__hidl_out_outParams_parent,  reinterpret_cast<const void **>(&_hidl_out_outParams));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_outParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_outParams),
            _hidl_reply,
            _hidl__hidl_out_outParams_parent,
            0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_status, *_hidl_out_outParams);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        _hidl_args.push_back((void *)_hidl_out_outParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "getParameter", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_setParameter(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& params) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::setParameter::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)&params);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "setParameter", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(index);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_params_parent;

    _hidl_err = _hidl_data.writeBuffer(&params, sizeof(params), &_hidl_params_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_params_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            params,
            &_hidl_data,
            _hidl_params_parent,
            0 /* parentOffset */, &_hidl_params_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* setParameter */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "setParameter", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxNode::_hidl_getConfig(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& inConfig, getConfig_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::getConfig::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)&inConfig);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "getConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;
    const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_outConfig;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(index);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inConfig_parent;

    _hidl_err = _hidl_data.writeBuffer(&inConfig, sizeof(inConfig), &_hidl_inConfig_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inConfig_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inConfig,
            &_hidl_data,
            _hidl_inConfig_parent,
            0 /* parentOffset */, &_hidl_inConfig_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* getConfig */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_outConfig_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outConfig), &_hidl__hidl_out_outConfig_parent,  reinterpret_cast<const void **>(&_hidl_out_outConfig));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_outConfig_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_outConfig),
            _hidl_reply,
            _hidl__hidl_out_outConfig_parent,
            0 /* parentOffset */, &_hidl__hidl_out_outConfig_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_status, *_hidl_out_outConfig);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        _hidl_args.push_back((void *)_hidl_out_outConfig);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "getConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_setConfig(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& config) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::setConfig::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)&config);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "setConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(index);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_config_parent;

    _hidl_err = _hidl_data.writeBuffer(&config, sizeof(config), &_hidl_config_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_config_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            config,
            &_hidl_data,
            _hidl_config_parent,
            0 /* parentOffset */, &_hidl_config_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* setConfig */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "setConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_setPortMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t portIndex, PortMode mode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::setPortMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "setPortMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(portIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* setPortMode */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "setPortMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_prepareForAdaptivePlayback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t portIndex, bool enable, uint32_t maxFrameWidth, uint32_t maxFrameHeight) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::prepareForAdaptivePlayback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&enable);
        _hidl_args.push_back((void *)&maxFrameWidth);
        _hidl_args.push_back((void *)&maxFrameHeight);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "prepareForAdaptivePlayback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(portIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enable);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(maxFrameWidth);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(maxFrameHeight);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* prepareForAdaptivePlayback */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "prepareForAdaptivePlayback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxNode::_hidl_configureVideoTunnelMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t portIndex, bool tunneled, uint32_t audioHwSync, configureVideoTunnelMode_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::configureVideoTunnelMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&tunneled);
        _hidl_args.push_back((void *)&audioHwSync);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "configureVideoTunnelMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;
    ::android::hardware::hidl_handle _hidl_out_sidebandHandle;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(portIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(tunneled);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(audioHwSync);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* configureVideoTunnelMode */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    const native_handle_t *_hidl_out_sidebandHandle_ptr;

    _hidl_err = _hidl_reply.readNullableNativeHandleNoDup(&_hidl_out_sidebandHandle_ptr);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_out_sidebandHandle = _hidl_out_sidebandHandle_ptr;
    _hidl_cb(_hidl_out_status, _hidl_out_sidebandHandle);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        _hidl_args.push_back((void *)&_hidl_out_sidebandHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "configureVideoTunnelMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxNode::_hidl_getGraphicBufferUsage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t portIndex, getGraphicBufferUsage_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::getGraphicBufferUsage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "getGraphicBufferUsage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;
    uint32_t _hidl_out_usage;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(portIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* getGraphicBufferUsage */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_usage);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_status, _hidl_out_usage);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        _hidl_args.push_back((void *)&_hidl_out_usage);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "getGraphicBufferUsage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_setInputSurface(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<IOmxBufferSource>& bufferSource) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::setInputSurface::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&bufferSource);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "setInputSurface", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (bufferSource == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::toBinder<
                IOmxBufferSource>(bufferSource);
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* setInputSurface */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "setInputSurface", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxNode::_hidl_allocateSecureBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t portIndex, uint64_t size, allocateSecureBuffer_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::allocateSecureBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "allocateSecureBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;
    uint32_t _hidl_out_buffer;
    ::android::hardware::hidl_handle _hidl_out_nativeHandle;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(portIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(size);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* allocateSecureBuffer */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_buffer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    const native_handle_t *_hidl_out_nativeHandle_ptr;

    _hidl_err = _hidl_reply.readNullableNativeHandleNoDup(&_hidl_out_nativeHandle_ptr);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_out_nativeHandle = _hidl_out_nativeHandle_ptr;
    _hidl_cb(_hidl_out_status, _hidl_out_buffer, _hidl_out_nativeHandle);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        _hidl_args.push_back((void *)&_hidl_out_buffer);
        _hidl_args.push_back((void *)&_hidl_out_nativeHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "allocateSecureBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxNode::_hidl_useBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t portIndex, const CodecBuffer& omxBuffer, useBuffer_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::useBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&omxBuffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "useBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;
    uint32_t _hidl_out_buffer;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(portIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_omxBuffer_parent;

    _hidl_err = _hidl_data.writeBuffer(&omxBuffer, sizeof(omxBuffer), &_hidl_omxBuffer_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            omxBuffer,
            &_hidl_data,
            _hidl_omxBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* useBuffer */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_buffer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_status, _hidl_out_buffer);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        _hidl_args.push_back((void *)&_hidl_out_buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "useBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_freeBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t portIndex, uint32_t buffer) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::freeBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "freeBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(portIndex);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(buffer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* freeBuffer */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "freeBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_fillBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t buffer, const CodecBuffer& omxBuffer, const ::android::hardware::hidl_handle& fence) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::fillBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&omxBuffer);
        _hidl_args.push_back((void *)&fence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "fillBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(buffer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_omxBuffer_parent;

    _hidl_err = _hidl_data.writeBuffer(&omxBuffer, sizeof(omxBuffer), &_hidl_omxBuffer_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            omxBuffer,
            &_hidl_data,
            _hidl_omxBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(fence);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* fillBuffer */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "fillBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_emptyBuffer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t buffer, const CodecBuffer& omxBuffer, uint32_t flags, uint64_t timestampUs, const ::android::hardware::hidl_handle& fence) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::emptyBuffer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&omxBuffer);
        _hidl_args.push_back((void *)&flags);
        _hidl_args.push_back((void *)&timestampUs);
        _hidl_args.push_back((void *)&fence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "emptyBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(buffer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_omxBuffer_parent;

    _hidl_err = _hidl_data.writeBuffer(&omxBuffer, sizeof(omxBuffer), &_hidl_omxBuffer_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            omxBuffer,
            &_hidl_data,
            _hidl_omxBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(flags);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(timestampUs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(fence);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* emptyBuffer */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "emptyBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxNode::_hidl_getExtensionIndex(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& parameterName, getExtensionIndex_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::getExtensionIndex::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&parameterName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "getExtensionIndex", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;
    uint32_t _hidl_out_index;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_parameterName_parent;

    _hidl_err = _hidl_data.writeBuffer(&parameterName, sizeof(parameterName), &_hidl_parameterName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            parameterName,
            &_hidl_data,
            _hidl_parameterName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* getExtensionIndex */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_index);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_status, _hidl_out_index);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        _hidl_args.push_back((void *)&_hidl_out_index);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "getExtensionIndex", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Status> BpHwOmxNode::_hidl_dispatchMessage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const Message& msg) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::dispatchMessage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "dispatchMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxNode::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.writeBuffer(&msg, sizeof(msg), &_hidl_msg_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            msg,
            &_hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* dispatchMessage */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "dispatchMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Status>(_hidl_status);
}


// Methods from IOmxNode follow.
::android::hardware::Return<Status> BpHwOmxNode::freeNode(){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_freeNode(this, this);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::sendCommand(uint32_t cmd, int32_t param){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_sendCommand(this, this, cmd, param);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::getParameter(uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& inParams, getParameter_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_getParameter(this, this, index, inParams, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::setParameter(uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& params){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_setParameter(this, this, index, params);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::getConfig(uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& inConfig, getConfig_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_getConfig(this, this, index, inConfig, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::setConfig(uint32_t index, const ::android::hardware::hidl_vec<uint8_t>& config){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_setConfig(this, this, index, config);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::setPortMode(uint32_t portIndex, PortMode mode){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_setPortMode(this, this, portIndex, mode);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::prepareForAdaptivePlayback(uint32_t portIndex, bool enable, uint32_t maxFrameWidth, uint32_t maxFrameHeight){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_prepareForAdaptivePlayback(this, this, portIndex, enable, maxFrameWidth, maxFrameHeight);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::configureVideoTunnelMode(uint32_t portIndex, bool tunneled, uint32_t audioHwSync, configureVideoTunnelMode_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_configureVideoTunnelMode(this, this, portIndex, tunneled, audioHwSync, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::getGraphicBufferUsage(uint32_t portIndex, getGraphicBufferUsage_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_getGraphicBufferUsage(this, this, portIndex, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::setInputSurface(const ::android::sp<IOmxBufferSource>& bufferSource){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_setInputSurface(this, this, bufferSource);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::allocateSecureBuffer(uint32_t portIndex, uint64_t size, allocateSecureBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_allocateSecureBuffer(this, this, portIndex, size, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::useBuffer(uint32_t portIndex, const CodecBuffer& omxBuffer, useBuffer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_useBuffer(this, this, portIndex, omxBuffer, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::freeBuffer(uint32_t portIndex, uint32_t buffer){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_freeBuffer(this, this, portIndex, buffer);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::fillBuffer(uint32_t buffer, const CodecBuffer& omxBuffer, const ::android::hardware::hidl_handle& fence){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_fillBuffer(this, this, buffer, omxBuffer, fence);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::emptyBuffer(uint32_t buffer, const CodecBuffer& omxBuffer, uint32_t flags, uint64_t timestampUs, const ::android::hardware::hidl_handle& fence){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_emptyBuffer(this, this, buffer, omxBuffer, flags, timestampUs, fence);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::getExtensionIndex(const ::android::hardware::hidl_string& parameterName, getExtensionIndex_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_getExtensionIndex(this, this, parameterName, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Status> BpHwOmxNode::dispatchMessage(const Message& msg){
    ::android::hardware::Return<Status>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxNode::_hidl_dispatchMessage(this, this, msg);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwOmxNode::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwOmxNode::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwOmxNode::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxNode::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwOmxNode::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    for (auto it = _hidl_mDeathRecipients.begin();it != _hidl_mDeathRecipients.end();++it) {
        if ((*it)->getRecipient() == recipient) {
            ::android::status_t status = remote()->unlinkToDeath(*it);
            _hidl_mDeathRecipients.erase(it);
            return status == ::android::OK;
        }}
    return false;
}


BnHwOmxNode::BnHwOmxNode(const ::android::sp<IOmxNode> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.media.omx@1.0", "IOmxNode") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::details::gServicePrioMap.get(_hidl_impl, {SCHED_NORMAL, 0});
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
}

BnHwOmxNode::~BnHwOmxNode() {
    ::android::hardware::details::gBnMap.eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from IOmxNode follow.
::android::status_t BnHwOmxNode::_hidl_freeNode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::freeNode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "freeNode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->freeNode();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "freeNode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_sendCommand(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t cmd;
    int32_t param;

    _hidl_err = _hidl_data.readUint32(&cmd);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&param);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::sendCommand::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&cmd);
        _hidl_args.push_back((void *)&param);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "sendCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->sendCommand(cmd, param);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "sendCommand", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_getParameter(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t index;
    const ::android::hardware::hidl_vec<uint8_t>* inParams;

    _hidl_err = _hidl_data.readUint32(&index);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inParams), &_hidl_inParams_parent,  reinterpret_cast<const void **>(&inParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*inParams),
            _hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::getParameter::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)inParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "getParameter", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->getParameter(index, *inParams, [&](const auto &_hidl_out_status, const auto &_hidl_out_outParams) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getParameter: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outParams, sizeof(_hidl_out_outParams), &_hidl__hidl_out_outParams_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outParams,
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_outParams);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "getParameter", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getParameter: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_setParameter(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t index;
    const ::android::hardware::hidl_vec<uint8_t>* params;

    _hidl_err = _hidl_data.readUint32(&index);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_params_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*params), &_hidl_params_parent,  reinterpret_cast<const void **>(&params));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_params_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*params),
            _hidl_data,
            _hidl_params_parent,
            0 /* parentOffset */, &_hidl_params_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::setParameter::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)params);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "setParameter", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->setParameter(index, *params);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "setParameter", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_getConfig(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t index;
    const ::android::hardware::hidl_vec<uint8_t>* inConfig;

    _hidl_err = _hidl_data.readUint32(&index);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inConfig_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inConfig), &_hidl_inConfig_parent,  reinterpret_cast<const void **>(&inConfig));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inConfig_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*inConfig),
            _hidl_data,
            _hidl_inConfig_parent,
            0 /* parentOffset */, &_hidl_inConfig_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::getConfig::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)inConfig);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "getConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->getConfig(index, *inConfig, [&](const auto &_hidl_out_status, const auto &_hidl_out_outConfig) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getConfig: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_outConfig_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outConfig, sizeof(_hidl_out_outConfig), &_hidl__hidl_out_outConfig_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_outConfig_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outConfig,
                _hidl_reply,
                _hidl__hidl_out_outConfig_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outConfig_child);

        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_outConfig);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "getConfig", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getConfig: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_setConfig(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t index;
    const ::android::hardware::hidl_vec<uint8_t>* config;

    _hidl_err = _hidl_data.readUint32(&index);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_config_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*config), &_hidl_config_parent,  reinterpret_cast<const void **>(&config));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_config_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*config),
            _hidl_data,
            _hidl_config_parent,
            0 /* parentOffset */, &_hidl_config_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::setConfig::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&index);
        _hidl_args.push_back((void *)config);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "setConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->setConfig(index, *config);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "setConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_setPortMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t portIndex;
    PortMode mode;

    _hidl_err = _hidl_data.readUint32(&portIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::setPortMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "setPortMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->setPortMode(portIndex, mode);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "setPortMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_prepareForAdaptivePlayback(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t portIndex;
    bool enable;
    uint32_t maxFrameWidth;
    uint32_t maxFrameHeight;

    _hidl_err = _hidl_data.readUint32(&portIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&enable);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&maxFrameWidth);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&maxFrameHeight);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::prepareForAdaptivePlayback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&enable);
        _hidl_args.push_back((void *)&maxFrameWidth);
        _hidl_args.push_back((void *)&maxFrameHeight);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "prepareForAdaptivePlayback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->prepareForAdaptivePlayback(portIndex, enable, maxFrameWidth, maxFrameHeight);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "prepareForAdaptivePlayback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_configureVideoTunnelMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t portIndex;
    bool tunneled;
    uint32_t audioHwSync;

    _hidl_err = _hidl_data.readUint32(&portIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&tunneled);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&audioHwSync);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::configureVideoTunnelMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&tunneled);
        _hidl_args.push_back((void *)&audioHwSync);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "configureVideoTunnelMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->configureVideoTunnelMode(portIndex, tunneled, audioHwSync, [&](const auto &_hidl_out_status, const auto &_hidl_out_sidebandHandle) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("configureVideoTunnelMode: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeNativeHandleNoDup(_hidl_out_sidebandHandle);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_sidebandHandle);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "configureVideoTunnelMode", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("configureVideoTunnelMode: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_getGraphicBufferUsage(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t portIndex;

    _hidl_err = _hidl_data.readUint32(&portIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::getGraphicBufferUsage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "getGraphicBufferUsage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->getGraphicBufferUsage(portIndex, [&](const auto &_hidl_out_status, const auto &_hidl_out_usage) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getGraphicBufferUsage: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_usage);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_usage);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "getGraphicBufferUsage", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getGraphicBufferUsage: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_setInputSurface(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<IOmxBufferSource> bufferSource;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_bufferSource_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_bufferSource_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        bufferSource = ::android::hardware::fromBinder<IOmxBufferSource,BpHwOmxBufferSource,BnHwOmxBufferSource>(_hidl_bufferSource_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::setInputSurface::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&bufferSource);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "setInputSurface", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->setInputSurface(bufferSource);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "setInputSurface", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_allocateSecureBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t portIndex;
    uint64_t size;

    _hidl_err = _hidl_data.readUint32(&portIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&size);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::allocateSecureBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "allocateSecureBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->allocateSecureBuffer(portIndex, size, [&](const auto &_hidl_out_status, const auto &_hidl_out_buffer, const auto &_hidl_out_nativeHandle) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("allocateSecureBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_buffer);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeNativeHandleNoDup(_hidl_out_nativeHandle);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_buffer);
            _hidl_args.push_back((void *)&_hidl_out_nativeHandle);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "allocateSecureBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("allocateSecureBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_useBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t portIndex;
    const CodecBuffer* omxBuffer;

    _hidl_err = _hidl_data.readUint32(&portIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_omxBuffer_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*omxBuffer), &_hidl_omxBuffer_parent,  reinterpret_cast<const void **>(&omxBuffer));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<CodecBuffer &>(*omxBuffer),
            _hidl_data,
            _hidl_omxBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::useBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)omxBuffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "useBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->useBuffer(portIndex, *omxBuffer, [&](const auto &_hidl_out_status, const auto &_hidl_out_buffer) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("useBuffer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_buffer);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_buffer);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "useBuffer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("useBuffer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_freeBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t portIndex;
    uint32_t buffer;

    _hidl_err = _hidl_data.readUint32(&portIndex);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&buffer);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::freeBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&portIndex);
        _hidl_args.push_back((void *)&buffer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "freeBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->freeBuffer(portIndex, buffer);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "freeBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_fillBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t buffer;
    const CodecBuffer* omxBuffer;
    ::android::hardware::hidl_handle fence;

    _hidl_err = _hidl_data.readUint32(&buffer);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_omxBuffer_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*omxBuffer), &_hidl_omxBuffer_parent,  reinterpret_cast<const void **>(&omxBuffer));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<CodecBuffer &>(*omxBuffer),
            _hidl_data,
            _hidl_omxBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    const native_handle_t *fence_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&fence_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    fence = fence_ptr;
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::fillBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)omxBuffer);
        _hidl_args.push_back((void *)&fence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "fillBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->fillBuffer(buffer, *omxBuffer, fence);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "fillBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_emptyBuffer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t buffer;
    const CodecBuffer* omxBuffer;
    uint32_t flags;
    uint64_t timestampUs;
    ::android::hardware::hidl_handle fence;

    _hidl_err = _hidl_data.readUint32(&buffer);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_omxBuffer_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*omxBuffer), &_hidl_omxBuffer_parent,  reinterpret_cast<const void **>(&omxBuffer));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<CodecBuffer &>(*omxBuffer),
            _hidl_data,
            _hidl_omxBuffer_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&flags);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&timestampUs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    const native_handle_t *fence_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&fence_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    fence = fence_ptr;
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::emptyBuffer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)omxBuffer);
        _hidl_args.push_back((void *)&flags);
        _hidl_args.push_back((void *)&timestampUs);
        _hidl_args.push_back((void *)&fence);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "emptyBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->emptyBuffer(buffer, *omxBuffer, flags, timestampUs, fence);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "emptyBuffer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_getExtensionIndex(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* parameterName;

    size_t _hidl_parameterName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*parameterName), &_hidl_parameterName_parent,  reinterpret_cast<const void **>(&parameterName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*parameterName),
            _hidl_data,
            _hidl_parameterName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::getExtensionIndex::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)parameterName);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "getExtensionIndex", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->getExtensionIndex(*parameterName, [&](const auto &_hidl_out_status, const auto &_hidl_out_index) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getExtensionIndex: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_index);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_index);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "getExtensionIndex", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getExtensionIndex: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxNode::_hidl_dispatchMessage(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxNode::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const Message* msg;

    size_t _hidl_msg_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*msg), &_hidl_msg_parent,  reinterpret_cast<const void **>(&msg));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<Message &>(*msg),
            _hidl_data,
            _hidl_msg_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxNode::dispatchMessage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)msg);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxNode", "dispatchMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Status _hidl_out_status = static_cast<BnHwOmxNode*>(_hidl_this)->_hidl_mImpl->dispatchMessage(*msg);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxNode", "dispatchMessage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from IOmxNode follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwOmxNode::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwOmxNode::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwOmxNode::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* freeNode */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_freeNode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* sendCommand */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_sendCommand(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* getParameter */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_getParameter(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* setParameter */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_setParameter(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getConfig */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_getConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* setConfig */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_setConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* setPortMode */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_setPortMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* prepareForAdaptivePlayback */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_prepareForAdaptivePlayback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* configureVideoTunnelMode */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_configureVideoTunnelMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* getGraphicBufferUsage */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_getGraphicBufferUsage(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* setInputSurface */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_setInputSurface(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* allocateSecureBuffer */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_allocateSecureBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* useBuffer */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_useBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* freeBuffer */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_freeBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* fillBuffer */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_fillBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* emptyBuffer */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_emptyBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* getExtensionIndex */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_getExtensionIndex(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* dispatchMessage */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxNode::_hidl_dispatchMessage(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsOmxNode::BsOmxNode(const ::android::sp<IOmxNode> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.media.omx@1.0", "IOmxNode"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsOmxNode::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

// static
::android::sp<IOmxNode> IOmxNode::tryGetService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = ::android::hidl::manager::V1_0::IServiceManager::Transport;

    sp<IOmxNode> iface = nullptr;

    const sp<::android::hidl::manager::V1_0::IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IOmxNode::descriptor, serviceName);

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
                sm->get(IOmxNode::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IOmxNode: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IOmxNode: found null hwbinder interface");
            }break;
        }
        Return<sp<IOmxNode>> castRet = IOmxNode::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IOmxNode: found dead hwbinder service");
                break;
            } else {
                ALOGW("IOmxNode: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IOmxNode: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<::android::hidl::manager::V1_0::IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IOmxNode::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IOmxNode::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsOmxNode(iface);
                    }
                }
            }
        }
    }
    return iface;
}

// static
::android::sp<IOmxNode> IOmxNode::getService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = ::android::hidl::manager::V1_0::IServiceManager::Transport;

    sp<IOmxNode> iface = nullptr;

    const sp<::android::hidl::manager::V1_0::IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IOmxNode::descriptor, serviceName);

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
            ALOGI("getService: Will do try %d for %s/%s in 1s...", tries, IOmxNode::descriptor, serviceName.c_str());
            sleep(1);
        }
        if (vintfHwbinder && tries > 0) {
            waitForHwService(IOmxNode::descriptor, serviceName);
        }
        Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                sm->get(IOmxNode::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IOmxNode: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IOmxNode: found null hwbinder interface");
            }continue;
        }
        Return<sp<IOmxNode>> castRet = IOmxNode::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IOmxNode: found dead hwbinder service");
                continue;
            } else {
                ALOGW("IOmxNode: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IOmxNode: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<::android::hidl::manager::V1_0::IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IOmxNode::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IOmxNode::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsOmxNode(iface);
                    }
                }
            }
        }
    }
    return iface;
}

::android::status_t IOmxNode::registerAsService(const std::string &serviceName) {
    ::android::hardware::details::onRegistration("android.hardware.media.omx@1.0", "IOmxNode", serviceName);

    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return ::android::INVALID_OPERATION;
    }
    ::android::hardware::Return<bool> ret = sm->add(serviceName.c_str(), this);
    return ret.isOk() && ret ? ::android::OK : ::android::UNKNOWN_ERROR;
}

bool IOmxNode::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.media.omx@1.0::IOmxNode",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace omx
}  // namespace media
}  // namespace hardware
}  // namespace android
