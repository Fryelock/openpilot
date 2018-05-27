#define LOG_TAG "android.hardware.media.omx@1.0::OmxStore"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/media/omx/1.0/BpHwOmxStore.h>
#include <android/hardware/media/omx/1.0/BnHwOmxStore.h>
#include <android/hardware/media/omx/1.0/BsOmxStore.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace media {
namespace omx {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const IOmxStore::IOmxStore::Attribute &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.key),
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::Attribute, key));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.value),
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::Attribute, value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IOmxStore::IOmxStore::Attribute &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.key,
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::Attribute, key));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.value,
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::Attribute, value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

std::string toString(const IOmxStore::Attribute& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".key = ";
    os += ::android::hardware::toString(o.key);
    os += ", .value = ";
    os += ::android::hardware::toString(o.value);
    os += "}"; return os;
}

bool operator==(const IOmxStore::Attribute& lhs, const IOmxStore::Attribute& rhs) {
    if (lhs.key != rhs.key) {
        return false;
    }
    if (lhs.value != rhs.value) {
        return false;
    }
    return true;
}

bool operator!=(const IOmxStore::Attribute& lhs,const IOmxStore::Attribute& rhs){
    return !(lhs == rhs);
}

::android::status_t readEmbeddedFromParcel(
        const IOmxStore::IOmxStore::NodeInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::NodeInfo, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.owner),
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::NodeInfo, owner));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_attributes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<IOmxStore::Attribute> &>(obj.attributes),
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::NodeInfo, attributes), &_hidl_attributes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.attributes.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<IOmxStore::Attribute &>(obj.attributes[_hidl_index_0]),
                parcel,
                _hidl_attributes_child,
                _hidl_index_0 * sizeof(IOmxStore::Attribute));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IOmxStore::IOmxStore::NodeInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::NodeInfo, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.owner,
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::NodeInfo, owner));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_attributes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.attributes,
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::NodeInfo, attributes), &_hidl_attributes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.attributes.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.attributes[_hidl_index_0],
                parcel,
                _hidl_attributes_child,
                _hidl_index_0 * sizeof(IOmxStore::Attribute));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

std::string toString(const IOmxStore::NodeInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".name = ";
    os += ::android::hardware::toString(o.name);
    os += ", .owner = ";
    os += ::android::hardware::toString(o.owner);
    os += ", .attributes = ";
    os += ::android::hardware::toString(o.attributes);
    os += "}"; return os;
}

bool operator==(const IOmxStore::NodeInfo& lhs, const IOmxStore::NodeInfo& rhs) {
    if (lhs.name != rhs.name) {
        return false;
    }
    if (lhs.owner != rhs.owner) {
        return false;
    }
    if (lhs.attributes != rhs.attributes) {
        return false;
    }
    return true;
}

bool operator!=(const IOmxStore::NodeInfo& lhs,const IOmxStore::NodeInfo& rhs){
    return !(lhs == rhs);
}

::android::status_t readEmbeddedFromParcel(
        const IOmxStore::IOmxStore::RoleInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.role),
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::RoleInfo, role));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.type),
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::RoleInfo, type));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_nodes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<IOmxStore::NodeInfo> &>(obj.nodes),
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::RoleInfo, nodes), &_hidl_nodes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.nodes.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<IOmxStore::NodeInfo &>(obj.nodes[_hidl_index_0]),
                parcel,
                _hidl_nodes_child,
                _hidl_index_0 * sizeof(IOmxStore::NodeInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IOmxStore::IOmxStore::RoleInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.role,
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::RoleInfo, role));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.type,
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::RoleInfo, type));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_nodes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.nodes,
            parcel,
            parentHandle,
            parentOffset + offsetof(IOmxStore::RoleInfo, nodes), &_hidl_nodes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.nodes.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.nodes[_hidl_index_0],
                parcel,
                _hidl_nodes_child,
                _hidl_index_0 * sizeof(IOmxStore::NodeInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

std::string toString(const IOmxStore::RoleInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".role = ";
    os += ::android::hardware::toString(o.role);
    os += ", .type = ";
    os += ::android::hardware::toString(o.type);
    os += ", .isEncoder = ";
    os += ::android::hardware::toString(o.isEncoder);
    os += ", .preferPlatformNodes = ";
    os += ::android::hardware::toString(o.preferPlatformNodes);
    os += ", .nodes = ";
    os += ::android::hardware::toString(o.nodes);
    os += "}"; return os;
}

bool operator==(const IOmxStore::RoleInfo& lhs, const IOmxStore::RoleInfo& rhs) {
    if (lhs.role != rhs.role) {
        return false;
    }
    if (lhs.type != rhs.type) {
        return false;
    }
    if (lhs.isEncoder != rhs.isEncoder) {
        return false;
    }
    if (lhs.preferPlatformNodes != rhs.preferPlatformNodes) {
        return false;
    }
    if (lhs.nodes != rhs.nodes) {
        return false;
    }
    return true;
}

bool operator!=(const IOmxStore::RoleInfo& lhs,const IOmxStore::RoleInfo& rhs){
    return !(lhs == rhs);
}

std::string toString(const ::android::sp<IOmxStore>& o) {
    std::string os = "[class or subclass of ";
    os += IOmxStore::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}

const char* IOmxStore::descriptor("android.hardware.media.omx@1.0::IOmxStore");

__attribute__((constructor))static void static_constructor() {
    ::android::hardware::details::gBnConstructorMap.set(IOmxStore::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwOmxStore(static_cast<IOmxStore *>(iIntf));
            });
    ::android::hardware::details::gBsConstructorMap.set(IOmxStore::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsOmxStore(static_cast<IOmxStore *>(iIntf));
            });
};

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::gBnConstructorMap.erase(IOmxStore::descriptor);
    ::android::hardware::details::gBsConstructorMap.erase(IOmxStore::descriptor);
};

// Methods from IOmxStore follow.
// no default implementation for: ::android::hardware::Return<void> IOmxStore::listServiceAttributes(listServiceAttributes_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IOmxStore::getNodePrefix(getNodePrefix_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IOmxStore::listRoles(listRoles_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::sp<IOmx>> IOmxStore::getOmx(const ::android::hardware::hidl_string& name)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IOmxStore::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        IOmxStore::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IOmxStore::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();}

::android::hardware::Return<void> IOmxStore::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(IOmxStore::descriptor);
    return ::android::hardware::Void();}

::android::hardware::Return<void> IOmxStore::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){9,52,32,65,225,124,66,159,206,0,52,185,9,109,23,132,145,34,17,20,54,165,240,5,62,126,89,80,14,28,184,156} /* 09342041e17c429fce0034b9096d17849122111436a5f0053e7e59500e1cb89c */,
        (uint8_t[32]){189,218,182,24,77,122,52,109,166,160,125,192,130,140,241,154,105,111,76,170,54,17,197,31,46,20,86,90,20,180,15,217} /* bddab6184d7a346da6a07dc0828cf19a696f4caa3611c51f2e14565a14b40fd9 */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IOmxStore::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IOmxStore::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IOmxStore::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IOmxStore::getDebugInfo(getDebugInfo_cb _hidl_cb){
    _hidl_cb({ -1 /* pid */, 0 /* ptr */, 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IOmxStore::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();}

::android::hardware::Return<bool> IOmxStore::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


// static 
::android::hardware::Return<::android::sp<IOmxStore>> IOmxStore::castFrom(const ::android::sp<IOmxStore>& parent, bool /* emitError */) {
    return parent;
}

// static 
::android::hardware::Return<::android::sp<IOmxStore>> IOmxStore::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IOmxStore, ::android::hidl::base::V1_0::IBase, BpHwOmxStore>(
            parent, "android.hardware.media.omx@1.0::IOmxStore", emitError);
}

BpHwOmxStore::BpHwOmxStore(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IOmxStore>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.media.omx@1.0", "IOmxStore") {
}

// Methods from IOmxStore follow.
::android::hardware::Return<void> BpHwOmxStore::_hidl_listServiceAttributes(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, listServiceAttributes_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxStore::listServiceAttributes::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxStore", "listServiceAttributes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Status _hidl_out_status;
    const ::android::hardware::hidl_vec<IOmxStore::Attribute>* _hidl_out_attributes;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxStore::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* listServiceAttributes */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_attributes_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_attributes), &_hidl__hidl_out_attributes_parent,  reinterpret_cast<const void **>(&_hidl_out_attributes));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_attributes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<IOmxStore::Attribute> &>(*_hidl_out_attributes),
            _hidl_reply,
            _hidl__hidl_out_attributes_parent,
            0 /* parentOffset */, &_hidl__hidl_out_attributes_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_attributes->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<IOmxStore::Attribute &>((*_hidl_out_attributes)[_hidl_index_0]),
                _hidl_reply,
                _hidl__hidl_out_attributes_child,
                _hidl_index_0 * sizeof(IOmxStore::Attribute));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_cb(_hidl_out_status, *_hidl_out_attributes);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        _hidl_args.push_back((void *)_hidl_out_attributes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxStore", "listServiceAttributes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxStore::_hidl_getNodePrefix(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getNodePrefix_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxStore::getNodePrefix::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxStore", "getNodePrefix", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    const ::android::hardware::hidl_string* _hidl_out_prefix;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxStore::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getNodePrefix */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    size_t _hidl__hidl_out_prefix_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_prefix), &_hidl__hidl_out_prefix_parent,  reinterpret_cast<const void **>(&_hidl_out_prefix));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*_hidl_out_prefix),
            _hidl_reply,
            _hidl__hidl_out_prefix_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(*_hidl_out_prefix);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)_hidl_out_prefix);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxStore", "getNodePrefix", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwOmxStore::_hidl_listRoles(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, listRoles_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxStore::listRoles::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxStore", "listRoles", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    const ::android::hardware::hidl_vec<IOmxStore::RoleInfo>* _hidl_out_roleList;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxStore::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* listRoles */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    size_t _hidl__hidl_out_roleList_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_roleList), &_hidl__hidl_out_roleList_parent,  reinterpret_cast<const void **>(&_hidl_out_roleList));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_roleList_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<IOmxStore::RoleInfo> &>(*_hidl_out_roleList),
            _hidl_reply,
            _hidl__hidl_out_roleList_parent,
            0 /* parentOffset */, &_hidl__hidl_out_roleList_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_roleList->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<IOmxStore::RoleInfo &>((*_hidl_out_roleList)[_hidl_index_0]),
                _hidl_reply,
                _hidl__hidl_out_roleList_child,
                _hidl_index_0 * sizeof(IOmxStore::RoleInfo));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_cb(*_hidl_out_roleList);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)_hidl_out_roleList);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxStore", "listRoles", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<::android::sp<IOmx>> BpHwOmxStore::_hidl_getOmx(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& name) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxStore::getOmx::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&name);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxStore", "getOmx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    ::android::sp<IOmx> _hidl_out_omx;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwOmxStore::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.writeBuffer(&name, sizeof(name), &_hidl_name_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            name,
            &_hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* getOmx */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl__hidl_out_omx_binder;
        _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl__hidl_out_omx_binder);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_out_omx = ::android::hardware::fromBinder<IOmx,BpHwOmx,BnHwOmx>(_hidl__hidl_out_omx_binder);
    }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_omx);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxStore", "getOmx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<IOmx>>(_hidl_out_omx);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::sp<IOmx>>(_hidl_status);
}


// Methods from IOmxStore follow.
::android::hardware::Return<void> BpHwOmxStore::listServiceAttributes(listServiceAttributes_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxStore::_hidl_listServiceAttributes(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxStore::getNodePrefix(getNodePrefix_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxStore::_hidl_getNodePrefix(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxStore::listRoles(listRoles_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxStore::_hidl_listRoles(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<IOmx>> BpHwOmxStore::getOmx(const ::android::hardware::hidl_string& name){
    ::android::hardware::Return<::android::sp<IOmx>>  _hidl_out = ::android::hardware::media::omx::V1_0::BpHwOmxStore::_hidl_getOmx(this, this, name);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwOmxStore::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxStore::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxStore::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxStore::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxStore::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwOmxStore::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwOmxStore::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxStore::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwOmxStore::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwOmxStore::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    for (auto it = _hidl_mDeathRecipients.begin();it != _hidl_mDeathRecipients.end();++it) {
        if ((*it)->getRecipient() == recipient) {
            ::android::status_t status = remote()->unlinkToDeath(*it);
            _hidl_mDeathRecipients.erase(it);
            return status == ::android::OK;
        }}
    return false;
}


BnHwOmxStore::BnHwOmxStore(const ::android::sp<IOmxStore> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.media.omx@1.0", "IOmxStore") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::details::gServicePrioMap.get(_hidl_impl, {SCHED_NORMAL, 0});
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
}

BnHwOmxStore::~BnHwOmxStore() {
    ::android::hardware::details::gBnMap.eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from IOmxStore follow.
::android::status_t BnHwOmxStore::_hidl_listServiceAttributes(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxStore::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxStore::listServiceAttributes::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxStore", "listServiceAttributes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxStore*>(_hidl_this)->_hidl_mImpl->listServiceAttributes([&](const auto &_hidl_out_status, const auto &_hidl_out_attributes) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("listServiceAttributes: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_attributes_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_attributes, sizeof(_hidl_out_attributes), &_hidl__hidl_out_attributes_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_attributes_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_attributes,
                _hidl_reply,
                _hidl__hidl_out_attributes_parent,
                0 /* parentOffset */, &_hidl__hidl_out_attributes_child);

        /* _hidl_err ignored! */

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_attributes.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_attributes[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_attributes_child,
                    _hidl_index_0 * sizeof(IOmxStore::Attribute));

            /* _hidl_err ignored! */

        }

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_attributes);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxStore", "listServiceAttributes", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("listServiceAttributes: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxStore::_hidl_getNodePrefix(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxStore::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxStore::getNodePrefix::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxStore", "getNodePrefix", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxStore*>(_hidl_this)->_hidl_mImpl->getNodePrefix([&](const auto &_hidl_out_prefix) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getNodePrefix: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_prefix_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_prefix, sizeof(_hidl_out_prefix), &_hidl__hidl_out_prefix_parent);
        /* _hidl_err ignored! */

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_prefix,
                _hidl_reply,
                _hidl__hidl_out_prefix_parent,
                0 /* parentOffset */);

        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_prefix);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxStore", "getNodePrefix", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getNodePrefix: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxStore::_hidl_listRoles(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxStore::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxStore::listRoles::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxStore", "listRoles", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwOmxStore*>(_hidl_this)->_hidl_mImpl->listRoles([&](const auto &_hidl_out_roleList) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("listRoles: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_roleList_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_roleList, sizeof(_hidl_out_roleList), &_hidl__hidl_out_roleList_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_roleList_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_roleList,
                _hidl_reply,
                _hidl__hidl_out_roleList_parent,
                0 /* parentOffset */, &_hidl__hidl_out_roleList_child);

        /* _hidl_err ignored! */

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_roleList.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_roleList[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_roleList_child,
                    _hidl_index_0 * sizeof(IOmxStore::RoleInfo));

            /* _hidl_err ignored! */

        }

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_roleList);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxStore", "listRoles", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("listRoles: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwOmxStore::_hidl_getOmx(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwOmxStore::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* name;

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*name), &_hidl_name_parent,  reinterpret_cast<const void **>(&name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*name),
            _hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IOmxStore::getOmx::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)name);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.omx", "1.0", "IOmxStore", "getOmx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::sp<IOmx> _hidl_out_omx = static_cast<BnHwOmxStore*>(_hidl_this)->_hidl_mImpl->getOmx(*name);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    if (_hidl_out_omx == nullptr) {
        _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::toBinder<
                IOmx>(_hidl_out_omx);
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_omx);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.omx", "1.0", "IOmxStore", "getOmx", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from IOmxStore follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwOmxStore::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwOmxStore::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwOmxStore::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* listServiceAttributes */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxStore::_hidl_listServiceAttributes(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getNodePrefix */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxStore::_hidl_getNodePrefix(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* listRoles */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxStore::_hidl_listRoles(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getOmx */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::media::omx::V1_0::BnHwOmxStore::_hidl_getOmx(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsOmxStore::BsOmxStore(const ::android::sp<IOmxStore> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.media.omx@1.0", "IOmxStore"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsOmxStore::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

// static
::android::sp<IOmxStore> IOmxStore::tryGetService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = ::android::hidl::manager::V1_0::IServiceManager::Transport;

    sp<IOmxStore> iface = nullptr;

    const sp<::android::hidl::manager::V1_0::IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IOmxStore::descriptor, serviceName);

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
                sm->get(IOmxStore::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IOmxStore: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IOmxStore: found null hwbinder interface");
            }break;
        }
        Return<sp<IOmxStore>> castRet = IOmxStore::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IOmxStore: found dead hwbinder service");
                break;
            } else {
                ALOGW("IOmxStore: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IOmxStore: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<::android::hidl::manager::V1_0::IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IOmxStore::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IOmxStore::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsOmxStore(iface);
                    }
                }
            }
        }
    }
    return iface;
}

// static
::android::sp<IOmxStore> IOmxStore::getService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = ::android::hidl::manager::V1_0::IServiceManager::Transport;

    sp<IOmxStore> iface = nullptr;

    const sp<::android::hidl::manager::V1_0::IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IOmxStore::descriptor, serviceName);

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
            ALOGI("getService: Will do try %d for %s/%s in 1s...", tries, IOmxStore::descriptor, serviceName.c_str());
            sleep(1);
        }
        if (vintfHwbinder && tries > 0) {
            waitForHwService(IOmxStore::descriptor, serviceName);
        }
        Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                sm->get(IOmxStore::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IOmxStore: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IOmxStore: found null hwbinder interface");
            }continue;
        }
        Return<sp<IOmxStore>> castRet = IOmxStore::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IOmxStore: found dead hwbinder service");
                continue;
            } else {
                ALOGW("IOmxStore: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IOmxStore: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<::android::hidl::manager::V1_0::IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IOmxStore::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IOmxStore::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsOmxStore(iface);
                    }
                }
            }
        }
    }
    return iface;
}

::android::status_t IOmxStore::registerAsService(const std::string &serviceName) {
    ::android::hardware::details::onRegistration("android.hardware.media.omx@1.0", "IOmxStore", serviceName);

    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return ::android::INVALID_OPERATION;
    }
    ::android::hardware::Return<bool> ret = sm->add(serviceName.c_str(), this);
    return ret.isOk() && ret ? ::android::OK : ::android::UNKNOWN_ERROR;
}

bool IOmxStore::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.media.omx@1.0::IOmxStore",
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
