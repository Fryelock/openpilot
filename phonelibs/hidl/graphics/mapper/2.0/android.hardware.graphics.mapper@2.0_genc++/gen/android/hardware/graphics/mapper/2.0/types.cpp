#define LOG_TAG "android.hardware.graphics.mapper@2.0::types"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hardware/graphics/mapper/2.0/types.h>
#include <android/hardware/graphics/mapper/2.0/hwtypes.h>

namespace android {
namespace hardware {
namespace graphics {
namespace mapper {
namespace V2_0 {

template<>
std::string toString<Error>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & Error::NONE) == static_cast<int32_t>(Error::NONE)) {
        os += (first ? "" : " | ");
        os += "NONE";
        first = false;
        flipped |= Error::NONE;
    }
    if ((o & Error::BAD_DESCRIPTOR) == static_cast<int32_t>(Error::BAD_DESCRIPTOR)) {
        os += (first ? "" : " | ");
        os += "BAD_DESCRIPTOR";
        first = false;
        flipped |= Error::BAD_DESCRIPTOR;
    }
    if ((o & Error::BAD_BUFFER) == static_cast<int32_t>(Error::BAD_BUFFER)) {
        os += (first ? "" : " | ");
        os += "BAD_BUFFER";
        first = false;
        flipped |= Error::BAD_BUFFER;
    }
    if ((o & Error::BAD_VALUE) == static_cast<int32_t>(Error::BAD_VALUE)) {
        os += (first ? "" : " | ");
        os += "BAD_VALUE";
        first = false;
        flipped |= Error::BAD_VALUE;
    }
    if ((o & Error::NO_RESOURCES) == static_cast<int32_t>(Error::NO_RESOURCES)) {
        os += (first ? "" : " | ");
        os += "NO_RESOURCES";
        first = false;
        flipped |= Error::NO_RESOURCES;
    }
    if ((o & Error::UNSUPPORTED) == static_cast<int32_t>(Error::UNSUPPORTED)) {
        os += (first ? "" : " | ");
        os += "UNSUPPORTED";
        first = false;
        flipped |= Error::UNSUPPORTED;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(Error o) {
    using ::android::hardware::details::toHexString;
    if (o == Error::NONE) {
        return "NONE";
    }
    if (o == Error::BAD_DESCRIPTOR) {
        return "BAD_DESCRIPTOR";
    }
    if (o == Error::BAD_BUFFER) {
        return "BAD_BUFFER";
    }
    if (o == Error::BAD_VALUE) {
        return "BAD_VALUE";
    }
    if (o == Error::NO_RESOURCES) {
        return "NO_RESOURCES";
    }
    if (o == Error::UNSUPPORTED) {
        return "UNSUPPORTED";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

std::string toString(const YCbCrLayout& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".y = ";
    os += ::android::hardware::toString(o.y);
    os += ", .cb = ";
    os += ::android::hardware::toString(o.cb);
    os += ", .cr = ";
    os += ::android::hardware::toString(o.cr);
    os += ", .yStride = ";
    os += ::android::hardware::toString(o.yStride);
    os += ", .cStride = ";
    os += ::android::hardware::toString(o.cStride);
    os += ", .chromaStep = ";
    os += ::android::hardware::toString(o.chromaStep);
    os += "}"; return os;
}

// operator== and operator!= are not generated for YCbCrLayout
static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace mapper
}  // namespace graphics
}  // namespace hardware
}  // namespace android
