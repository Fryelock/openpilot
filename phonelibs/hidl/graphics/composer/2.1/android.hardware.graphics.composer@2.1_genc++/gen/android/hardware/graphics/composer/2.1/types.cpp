#define LOG_TAG "android.hardware.graphics.composer@2.1::types"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hardware/graphics/composer/2.1/types.h>
#include <android/hardware/graphics/composer/2.1/hwtypes.h>

namespace android {
namespace hardware {
namespace graphics {
namespace composer {
namespace V2_1 {

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
    if ((o & Error::BAD_CONFIG) == static_cast<int32_t>(Error::BAD_CONFIG)) {
        os += (first ? "" : " | ");
        os += "BAD_CONFIG";
        first = false;
        flipped |= Error::BAD_CONFIG;
    }
    if ((o & Error::BAD_DISPLAY) == static_cast<int32_t>(Error::BAD_DISPLAY)) {
        os += (first ? "" : " | ");
        os += "BAD_DISPLAY";
        first = false;
        flipped |= Error::BAD_DISPLAY;
    }
    if ((o & Error::BAD_LAYER) == static_cast<int32_t>(Error::BAD_LAYER)) {
        os += (first ? "" : " | ");
        os += "BAD_LAYER";
        first = false;
        flipped |= Error::BAD_LAYER;
    }
    if ((o & Error::BAD_PARAMETER) == static_cast<int32_t>(Error::BAD_PARAMETER)) {
        os += (first ? "" : " | ");
        os += "BAD_PARAMETER";
        first = false;
        flipped |= Error::BAD_PARAMETER;
    }
    if ((o & Error::NO_RESOURCES) == static_cast<int32_t>(Error::NO_RESOURCES)) {
        os += (first ? "" : " | ");
        os += "NO_RESOURCES";
        first = false;
        flipped |= Error::NO_RESOURCES;
    }
    if ((o & Error::NOT_VALIDATED) == static_cast<int32_t>(Error::NOT_VALIDATED)) {
        os += (first ? "" : " | ");
        os += "NOT_VALIDATED";
        first = false;
        flipped |= Error::NOT_VALIDATED;
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
    if (o == Error::BAD_CONFIG) {
        return "BAD_CONFIG";
    }
    if (o == Error::BAD_DISPLAY) {
        return "BAD_DISPLAY";
    }
    if (o == Error::BAD_LAYER) {
        return "BAD_LAYER";
    }
    if (o == Error::BAD_PARAMETER) {
        return "BAD_PARAMETER";
    }
    if (o == Error::NO_RESOURCES) {
        return "NO_RESOURCES";
    }
    if (o == Error::NOT_VALIDATED) {
        return "NOT_VALIDATED";
    }
    if (o == Error::UNSUPPORTED) {
        return "UNSUPPORTED";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_1
}  // namespace composer
}  // namespace graphics
}  // namespace hardware
}  // namespace android
