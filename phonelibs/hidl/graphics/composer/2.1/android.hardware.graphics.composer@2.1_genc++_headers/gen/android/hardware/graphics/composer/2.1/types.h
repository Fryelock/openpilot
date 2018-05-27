#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace graphics {
namespace composer {
namespace V2_1 {

enum class Error : int32_t {
    NONE = 0,
    BAD_CONFIG = 1,
    BAD_DISPLAY = 2,
    BAD_LAYER = 3,
    BAD_PARAMETER = 4,
    NO_RESOURCES = 6,
    NOT_VALIDATED = 7,
    UNSUPPORTED = 8,
};

typedef uint32_t Config;

typedef uint64_t Display;

typedef uint64_t Layer;

constexpr int32_t operator|(const Error lhs, const Error rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const Error rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const Error lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const Error lhs, const Error rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const Error rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const Error lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const Error e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const Error e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<Error>(int32_t o);

std::string toString(Error o);


}  // namespace V2_1
}  // namespace composer
}  // namespace graphics
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_TYPES_H
