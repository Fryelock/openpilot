#define LOG_TAG "android.hidl.manager@1.0::ServiceNotification"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hidl/manager/1.0/BpHwServiceNotification.h>
#include <android/hidl/manager/1.0/BnHwServiceNotification.h>
#include <android/hidl/manager/1.0/BsServiceNotification.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hidl {
namespace manager {
namespace V1_0 {

std::string toString(const ::android::sp<IServiceNotification>& o) {
    std::string os = "[class or subclass of ";
    os += IServiceNotification::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}

const char* IServiceNotification::descriptor("android.hidl.manager@1.0::IServiceNotification");

__attribute__((constructor))static void static_constructor() {
    ::android::hardware::details::gBnConstructorMap.set(IServiceNotification::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwServiceNotification(static_cast<IServiceNotification *>(iIntf));
            });
    ::android::hardware::details::gBsConstructorMap.set(IServiceNotification::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsServiceNotification(static_cast<IServiceNotification *>(iIntf));
            });
};

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::gBnConstructorMap.erase(IServiceNotification::descriptor);
    ::android::hardware::details::gBsConstructorMap.erase(IServiceNotification::descriptor);
};

// Methods from IServiceNotification follow.
// no default implementation for: ::android::hardware::Return<void> IServiceNotification::onRegistration(const ::android::hardware::hidl_string& fqName, const ::android::hardware::hidl_string& name, bool preexisting)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IServiceNotification::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        IServiceNotification::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IServiceNotification::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();}

::android::hardware::Return<void> IServiceNotification::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(IServiceNotification::descriptor);
    return ::android::hardware::Void();}

::android::hardware::Return<void> IServiceNotification::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){80,85,43,112,14,246,124,126,216,200,215,118,211,35,248,198,41,169,180,59,150,94,16,169,22,166,111,60,148,108,80,251} /* 50552b700ef67c7ed8c8d776d323f8c629a9b43b965e10a916a66f3c946c50fb */,
        (uint8_t[32]){189,218,182,24,77,122,52,109,166,160,125,192,130,140,241,154,105,111,76,170,54,17,197,31,46,20,86,90,20,180,15,217} /* bddab6184d7a346da6a07dc0828cf19a696f4caa3611c51f2e14565a14b40fd9 */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IServiceNotification::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IServiceNotification::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IServiceNotification::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IServiceNotification::getDebugInfo(getDebugInfo_cb _hidl_cb){
    _hidl_cb({ -1 /* pid */, 0 /* ptr */, 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IServiceNotification::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();}

::android::hardware::Return<bool> IServiceNotification::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


// static 
::android::hardware::Return<::android::sp<IServiceNotification>> IServiceNotification::castFrom(const ::android::sp<IServiceNotification>& parent, bool /* emitError */) {
    return parent;
}

// static 
::android::hardware::Return<::android::sp<IServiceNotification>> IServiceNotification::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IServiceNotification, ::android::hidl::base::V1_0::IBase, BpHwServiceNotification>(
            parent, "android.hidl.manager@1.0::IServiceNotification", emitError);
}

BpHwServiceNotification::BpHwServiceNotification(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IServiceNotification>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hidl.manager@1.0", "IServiceNotification") {
}

// Methods from IServiceNotification follow.
::android::hardware::Return<void> BpHwServiceNotification::_hidl_onRegistration(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& fqName, const ::android::hardware::hidl_string& name, bool preexisting) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IServiceNotification::onRegistration::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&fqName);
        _hidl_args.push_back((void *)&name);
        _hidl_args.push_back((void *)&preexisting);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hidl.manager", "1.0", "IServiceNotification", "onRegistration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwServiceNotification::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_fqName_parent;

    _hidl_err = _hidl_data.writeBuffer(&fqName, sizeof(fqName), &_hidl_fqName_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            fqName,
            &_hidl_data,
            _hidl_fqName_parent,
            0 /* parentOffset */);

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

    _hidl_err = _hidl_data.writeBool(preexisting);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* onRegistration */, _hidl_data, &_hidl_reply, ::android::hardware::IBinder::FLAG_ONEWAY);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hidl.manager", "1.0", "IServiceNotification", "onRegistration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from IServiceNotification follow.
::android::hardware::Return<void> BpHwServiceNotification::onRegistration(const ::android::hardware::hidl_string& fqName, const ::android::hardware::hidl_string& name, bool preexisting){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::manager::V1_0::BpHwServiceNotification::_hidl_onRegistration(this, this, fqName, name, preexisting);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwServiceNotification::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwServiceNotification::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwServiceNotification::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwServiceNotification::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwServiceNotification::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwServiceNotification::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwServiceNotification::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwServiceNotification::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwServiceNotification::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwServiceNotification::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    for (auto it = _hidl_mDeathRecipients.begin();it != _hidl_mDeathRecipients.end();++it) {
        if ((*it)->getRecipient() == recipient) {
            ::android::status_t status = remote()->unlinkToDeath(*it);
            _hidl_mDeathRecipients.erase(it);
            return status == ::android::OK;
        }}
    return false;
}


BnHwServiceNotification::BnHwServiceNotification(const ::android::sp<IServiceNotification> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hidl.manager@1.0", "IServiceNotification") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::details::gServicePrioMap.get(_hidl_impl, {SCHED_NORMAL, 0});
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
}

BnHwServiceNotification::~BnHwServiceNotification() {
    ::android::hardware::details::gBnMap.eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from IServiceNotification follow.
::android::status_t BnHwServiceNotification::_hidl_onRegistration(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwServiceNotification::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* fqName;
    const ::android::hardware::hidl_string* name;
    bool preexisting;

    size_t _hidl_fqName_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*fqName), &_hidl_fqName_parent,  reinterpret_cast<const void **>(&fqName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*fqName),
            _hidl_data,
            _hidl_fqName_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*name), &_hidl_name_parent,  reinterpret_cast<const void **>(&name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*name),
            _hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readBool(&preexisting);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IServiceNotification::onRegistration::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)fqName);
        _hidl_args.push_back((void *)name);
        _hidl_args.push_back((void *)&preexisting);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hidl.manager", "1.0", "IServiceNotification", "onRegistration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    static_cast<BnHwServiceNotification*>(_hidl_this)->_hidl_mImpl->onRegistration(*fqName, *name, preexisting);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hidl.manager", "1.0", "IServiceNotification", "onRegistration", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from IServiceNotification follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwServiceNotification::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwServiceNotification::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwServiceNotification::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* onRegistration */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != true) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hidl::manager::V1_0::BnHwServiceNotification::_hidl_onRegistration(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsServiceNotification::BsServiceNotification(const ::android::sp<IServiceNotification> impl) : ::android::hardware::details::HidlInstrumentor("android.hidl.manager@1.0", "IServiceNotification"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsServiceNotification::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

// static
::android::sp<IServiceNotification> IServiceNotification::tryGetService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = IServiceManager::Transport;

    sp<IServiceNotification> iface = nullptr;

    const sp<IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IServiceNotification::descriptor, serviceName);

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
                sm->get(IServiceNotification::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IServiceNotification: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IServiceNotification: found null hwbinder interface");
            }break;
        }
        Return<sp<IServiceNotification>> castRet = IServiceNotification::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IServiceNotification: found dead hwbinder service");
                break;
            } else {
                ALOGW("IServiceNotification: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IServiceNotification: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IServiceNotification::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IServiceNotification::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsServiceNotification(iface);
                    }
                }
            }
        }
    }
    return iface;
}

// static
::android::sp<IServiceNotification> IServiceNotification::getService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = IServiceManager::Transport;

    sp<IServiceNotification> iface = nullptr;

    const sp<IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IServiceNotification::descriptor, serviceName);

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
            ALOGI("getService: Will do try %d for %s/%s in 1s...", tries, IServiceNotification::descriptor, serviceName.c_str());
            sleep(1);
        }
        if (vintfHwbinder && tries > 0) {
            waitForHwService(IServiceNotification::descriptor, serviceName);
        }
        Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                sm->get(IServiceNotification::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IServiceNotification: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IServiceNotification: found null hwbinder interface");
            }continue;
        }
        Return<sp<IServiceNotification>> castRet = IServiceNotification::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IServiceNotification: found dead hwbinder service");
                continue;
            } else {
                ALOGW("IServiceNotification: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IServiceNotification: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IServiceNotification::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IServiceNotification::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsServiceNotification(iface);
                    }
                }
            }
        }
    }
    return iface;
}

::android::status_t IServiceNotification::registerAsService(const std::string &serviceName) {
    ::android::hardware::details::onRegistration("android.hidl.manager@1.0", "IServiceNotification", serviceName);

    const ::android::sp<IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return ::android::INVALID_OPERATION;
    }
    ::android::hardware::Return<bool> ret = sm->add(serviceName.c_str(), this);
    return ret.isOk() && ret ? ::android::OK : ::android::UNKNOWN_ERROR;
}

bool IServiceNotification::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<IServiceNotification> &notification) {
    const ::android::sp<IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hidl.manager@1.0::IServiceNotification",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace manager
}  // namespace hidl
}  // namespace android
