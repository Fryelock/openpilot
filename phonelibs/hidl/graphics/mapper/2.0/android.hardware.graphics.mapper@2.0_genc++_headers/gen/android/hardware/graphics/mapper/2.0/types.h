#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace graphics {
namespace mapper {
namespace V2_0 {

enum class Error : int32_t {
    NONE = 0,
    BAD_DESCRIPTOR = 1,
    BAD_BUFFER = 2,
    BAD_VALUE = 3,
    NO_RESOURCES = 5,
    UNSUPPORTED = 7,
};

typedef ::android::hardware::hidl_vec<uint32_t> BufferDescriptor;

struct YCbCrLayout final {
    void* y;
    void* cb;
    void* cr;
    uint32_t yStride;
    uint32_t cStride;
    uint32_t chromaStep;
};

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

std::string toString(const YCbCrLayout&);

// operator== and operator!= are not generated for YCbCrLayout


}  // namespace V2_0
}  // namespace mapper
}  // namespace graphics
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_MAPPER_V2_0_TYPES_H
