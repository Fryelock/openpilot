#define LOG_TAG "android.hidl.base@1.0::types"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hidl/base/1.0/types.h>
#include <android/hidl/base/1.0/hwtypes.h>

namespace android {
namespace hidl {
namespace base {
namespace V1_0 {

template<>
std::string toString<DebugInfo::Architecture>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & DebugInfo::Architecture::UNKNOWN) == static_cast<int32_t>(DebugInfo::Architecture::UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN";
        first = false;
        flipped |= DebugInfo::Architecture::UNKNOWN;
    }
    if ((o & DebugInfo::Architecture::IS_64BIT) == static_cast<int32_t>(DebugInfo::Architecture::IS_64BIT)) {
        os += (first ? "" : " | ");
        os += "IS_64BIT";
        first = false;
        flipped |= DebugInfo::Architecture::IS_64BIT;
    }
    if ((o & DebugInfo::Architecture::IS_32BIT) == static_cast<int32_t>(DebugInfo::Architecture::IS_32BIT)) {
        os += (first ? "" : " | ");
        os += "IS_32BIT";
        first = false;
        flipped |= DebugInfo::Architecture::IS_32BIT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(DebugInfo::Architecture o) {
    using ::android::hardware::details::toHexString;
    if (o == DebugInfo::Architecture::UNKNOWN) {
        return "UNKNOWN";
    }
    if (o == DebugInfo::Architecture::IS_64BIT) {
        return "IS_64BIT";
    }
    if (o == DebugInfo::Architecture::IS_32BIT) {
        return "IS_32BIT";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

std::string toString(const DebugInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".pid = ";
    os += ::android::hardware::toString(o.pid);
    os += ", .ptr = ";
    os += ::android::hardware::toString(o.ptr);
    os += ", .arch = ";
    os += toString(o.arch);
    os += "}"; return os;
}

bool operator==(const DebugInfo& lhs, const DebugInfo& rhs) {
    if (lhs.pid != rhs.pid) {
        return false;
    }
    if (lhs.ptr != rhs.ptr) {
        return false;
    }
    if (lhs.arch != rhs.arch) {
        return false;
    }
    return true;
}

bool operator!=(const DebugInfo& lhs,const DebugInfo& rhs){
    return !(lhs == rhs);
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace base
}  // namespace hidl
}  // namespace android
