#define LOG_TAG "android.hardware.media@1.0::types"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hardware/media/1.0/types.h>
#include <android/hardware/media/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace media {
namespace V1_0 {

std::string toString(const AnwBufferAttributes& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".width = ";
    os += ::android::hardware::toString(o.width);
    os += ", .height = ";
    os += ::android::hardware::toString(o.height);
    os += ", .stride = ";
    os += ::android::hardware::toString(o.stride);
    os += ", .format = ";
    os += ::android::hardware::graphics::common::V1_0::toString(o.format);
    os += ", .usage = ";
    os += ::android::hardware::toString(o.usage);
    os += ", .generationNumber = ";
    os += ::android::hardware::toString(o.generationNumber);
    os += ", .layerCount = ";
    os += ::android::hardware::toString(o.layerCount);
    os += ", .id = ";
    os += ::android::hardware::toString(o.id);
    os += "}"; return os;
}

bool operator==(const AnwBufferAttributes& lhs, const AnwBufferAttributes& rhs) {
    if (lhs.width != rhs.width) {
        return false;
    }
    if (lhs.height != rhs.height) {
        return false;
    }
    if (lhs.stride != rhs.stride) {
        return false;
    }
    if (lhs.format != rhs.format) {
        return false;
    }
    if (lhs.usage != rhs.usage) {
        return false;
    }
    if (lhs.generationNumber != rhs.generationNumber) {
        return false;
    }
    if (lhs.layerCount != rhs.layerCount) {
        return false;
    }
    if (lhs.id != rhs.id) {
        return false;
    }
    return true;
}

bool operator!=(const AnwBufferAttributes& lhs,const AnwBufferAttributes& rhs){
    return !(lhs == rhs);
}

::android::status_t readEmbeddedFromParcel(
        const AnwBuffer &/* obj */,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    const native_handle_t *_hidl_nativeHandle_ptr;
    _hidl_err = parcel.readNullableEmbeddedNativeHandle(
            parentHandle,
            parentOffset + offsetof(AnwBuffer, nativeHandle),
            &_hidl_nativeHandle_ptr
            );

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AnwBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = parcel->writeEmbeddedNativeHandle(
            obj.nativeHandle,
            parentHandle,
            parentOffset + offsetof(AnwBuffer, nativeHandle));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

std::string toString(const AnwBuffer& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".nativeHandle = ";
    os += ::android::hardware::toString(o.nativeHandle);
    os += ", .attr = ";
    os += toString(o.attr);
    os += "}"; return os;
}

// operator== and operator!= are not generated for AnwBuffer
std::string toString(const Rect& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".left = ";
    os += ::android::hardware::toString(o.left);
    os += ", .top = ";
    os += ::android::hardware::toString(o.top);
    os += ", .right = ";
    os += ::android::hardware::toString(o.right);
    os += ", .bottom = ";
    os += ::android::hardware::toString(o.bottom);
    os += "}"; return os;
}

bool operator==(const Rect& lhs, const Rect& rhs) {
    if (lhs.left != rhs.left) {
        return false;
    }
    if (lhs.top != rhs.top) {
        return false;
    }
    if (lhs.right != rhs.right) {
        return false;
    }
    if (lhs.bottom != rhs.bottom) {
        return false;
    }
    return true;
}

bool operator!=(const Rect& lhs,const Rect& rhs){
    return !(lhs == rhs);
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace media
}  // namespace hardware
}  // namespace android
