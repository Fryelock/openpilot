#define LOG_TAG "android.hardware.graphics.composer@2.1::ComposerClient"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/graphics/composer/2.1/BpHwComposerClient.h>
#include <android/hardware/graphics/composer/2.1/BnHwComposerClient.h>
#include <android/hardware/graphics/composer/2.1/BsComposerClient.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace graphics {
namespace composer {
namespace V2_1 {

template<>
std::string toString<IComposerClient::Attribute>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::Attribute::INVALID) == static_cast<int32_t>(IComposerClient::Attribute::INVALID)) {
        os += (first ? "" : " | ");
        os += "INVALID";
        first = false;
        flipped |= IComposerClient::Attribute::INVALID;
    }
    if ((o & IComposerClient::Attribute::WIDTH) == static_cast<int32_t>(IComposerClient::Attribute::WIDTH)) {
        os += (first ? "" : " | ");
        os += "WIDTH";
        first = false;
        flipped |= IComposerClient::Attribute::WIDTH;
    }
    if ((o & IComposerClient::Attribute::HEIGHT) == static_cast<int32_t>(IComposerClient::Attribute::HEIGHT)) {
        os += (first ? "" : " | ");
        os += "HEIGHT";
        first = false;
        flipped |= IComposerClient::Attribute::HEIGHT;
    }
    if ((o & IComposerClient::Attribute::VSYNC_PERIOD) == static_cast<int32_t>(IComposerClient::Attribute::VSYNC_PERIOD)) {
        os += (first ? "" : " | ");
        os += "VSYNC_PERIOD";
        first = false;
        flipped |= IComposerClient::Attribute::VSYNC_PERIOD;
    }
    if ((o & IComposerClient::Attribute::DPI_X) == static_cast<int32_t>(IComposerClient::Attribute::DPI_X)) {
        os += (first ? "" : " | ");
        os += "DPI_X";
        first = false;
        flipped |= IComposerClient::Attribute::DPI_X;
    }
    if ((o & IComposerClient::Attribute::DPI_Y) == static_cast<int32_t>(IComposerClient::Attribute::DPI_Y)) {
        os += (first ? "" : " | ");
        os += "DPI_Y";
        first = false;
        flipped |= IComposerClient::Attribute::DPI_Y;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::Attribute o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::Attribute::INVALID) {
        return "INVALID";
    }
    if (o == IComposerClient::Attribute::WIDTH) {
        return "WIDTH";
    }
    if (o == IComposerClient::Attribute::HEIGHT) {
        return "HEIGHT";
    }
    if (o == IComposerClient::Attribute::VSYNC_PERIOD) {
        return "VSYNC_PERIOD";
    }
    if (o == IComposerClient::Attribute::DPI_X) {
        return "DPI_X";
    }
    if (o == IComposerClient::Attribute::DPI_Y) {
        return "DPI_Y";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<IComposerClient::DisplayRequest>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    uint32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::DisplayRequest::FLIP_CLIENT_TARGET) == static_cast<uint32_t>(IComposerClient::DisplayRequest::FLIP_CLIENT_TARGET)) {
        os += (first ? "" : " | ");
        os += "FLIP_CLIENT_TARGET";
        first = false;
        flipped |= IComposerClient::DisplayRequest::FLIP_CLIENT_TARGET;
    }
    if ((o & IComposerClient::DisplayRequest::WRITE_CLIENT_TARGET_TO_OUTPUT) == static_cast<uint32_t>(IComposerClient::DisplayRequest::WRITE_CLIENT_TARGET_TO_OUTPUT)) {
        os += (first ? "" : " | ");
        os += "WRITE_CLIENT_TARGET_TO_OUTPUT";
        first = false;
        flipped |= IComposerClient::DisplayRequest::WRITE_CLIENT_TARGET_TO_OUTPUT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::DisplayRequest o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::DisplayRequest::FLIP_CLIENT_TARGET) {
        return "FLIP_CLIENT_TARGET";
    }
    if (o == IComposerClient::DisplayRequest::WRITE_CLIENT_TARGET_TO_OUTPUT) {
        return "WRITE_CLIENT_TARGET_TO_OUTPUT";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
std::string toString<IComposerClient::LayerRequest>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    uint32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::LayerRequest::CLEAR_CLIENT_TARGET) == static_cast<uint32_t>(IComposerClient::LayerRequest::CLEAR_CLIENT_TARGET)) {
        os += (first ? "" : " | ");
        os += "CLEAR_CLIENT_TARGET";
        first = false;
        flipped |= IComposerClient::LayerRequest::CLEAR_CLIENT_TARGET;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::LayerRequest o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::LayerRequest::CLEAR_CLIENT_TARGET) {
        return "CLEAR_CLIENT_TARGET";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
std::string toString<IComposerClient::PowerMode>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::PowerMode::OFF) == static_cast<int32_t>(IComposerClient::PowerMode::OFF)) {
        os += (first ? "" : " | ");
        os += "OFF";
        first = false;
        flipped |= IComposerClient::PowerMode::OFF;
    }
    if ((o & IComposerClient::PowerMode::DOZE) == static_cast<int32_t>(IComposerClient::PowerMode::DOZE)) {
        os += (first ? "" : " | ");
        os += "DOZE";
        first = false;
        flipped |= IComposerClient::PowerMode::DOZE;
    }
    if ((o & IComposerClient::PowerMode::DOZE_SUSPEND) == static_cast<int32_t>(IComposerClient::PowerMode::DOZE_SUSPEND)) {
        os += (first ? "" : " | ");
        os += "DOZE_SUSPEND";
        first = false;
        flipped |= IComposerClient::PowerMode::DOZE_SUSPEND;
    }
    if ((o & IComposerClient::PowerMode::ON) == static_cast<int32_t>(IComposerClient::PowerMode::ON)) {
        os += (first ? "" : " | ");
        os += "ON";
        first = false;
        flipped |= IComposerClient::PowerMode::ON;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::PowerMode o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::PowerMode::OFF) {
        return "OFF";
    }
    if (o == IComposerClient::PowerMode::DOZE) {
        return "DOZE";
    }
    if (o == IComposerClient::PowerMode::DOZE_SUSPEND) {
        return "DOZE_SUSPEND";
    }
    if (o == IComposerClient::PowerMode::ON) {
        return "ON";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<IComposerClient::Vsync>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::Vsync::INVALID) == static_cast<int32_t>(IComposerClient::Vsync::INVALID)) {
        os += (first ? "" : " | ");
        os += "INVALID";
        first = false;
        flipped |= IComposerClient::Vsync::INVALID;
    }
    if ((o & IComposerClient::Vsync::ENABLE) == static_cast<int32_t>(IComposerClient::Vsync::ENABLE)) {
        os += (first ? "" : " | ");
        os += "ENABLE";
        first = false;
        flipped |= IComposerClient::Vsync::ENABLE;
    }
    if ((o & IComposerClient::Vsync::DISABLE) == static_cast<int32_t>(IComposerClient::Vsync::DISABLE)) {
        os += (first ? "" : " | ");
        os += "DISABLE";
        first = false;
        flipped |= IComposerClient::Vsync::DISABLE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::Vsync o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::Vsync::INVALID) {
        return "INVALID";
    }
    if (o == IComposerClient::Vsync::ENABLE) {
        return "ENABLE";
    }
    if (o == IComposerClient::Vsync::DISABLE) {
        return "DISABLE";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<IComposerClient::BlendMode>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::BlendMode::INVALID) == static_cast<int32_t>(IComposerClient::BlendMode::INVALID)) {
        os += (first ? "" : " | ");
        os += "INVALID";
        first = false;
        flipped |= IComposerClient::BlendMode::INVALID;
    }
    if ((o & IComposerClient::BlendMode::NONE) == static_cast<int32_t>(IComposerClient::BlendMode::NONE)) {
        os += (first ? "" : " | ");
        os += "NONE";
        first = false;
        flipped |= IComposerClient::BlendMode::NONE;
    }
    if ((o & IComposerClient::BlendMode::PREMULTIPLIED) == static_cast<int32_t>(IComposerClient::BlendMode::PREMULTIPLIED)) {
        os += (first ? "" : " | ");
        os += "PREMULTIPLIED";
        first = false;
        flipped |= IComposerClient::BlendMode::PREMULTIPLIED;
    }
    if ((o & IComposerClient::BlendMode::COVERAGE) == static_cast<int32_t>(IComposerClient::BlendMode::COVERAGE)) {
        os += (first ? "" : " | ");
        os += "COVERAGE";
        first = false;
        flipped |= IComposerClient::BlendMode::COVERAGE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::BlendMode o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::BlendMode::INVALID) {
        return "INVALID";
    }
    if (o == IComposerClient::BlendMode::NONE) {
        return "NONE";
    }
    if (o == IComposerClient::BlendMode::PREMULTIPLIED) {
        return "PREMULTIPLIED";
    }
    if (o == IComposerClient::BlendMode::COVERAGE) {
        return "COVERAGE";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<IComposerClient::Composition>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::Composition::INVALID) == static_cast<int32_t>(IComposerClient::Composition::INVALID)) {
        os += (first ? "" : " | ");
        os += "INVALID";
        first = false;
        flipped |= IComposerClient::Composition::INVALID;
    }
    if ((o & IComposerClient::Composition::CLIENT) == static_cast<int32_t>(IComposerClient::Composition::CLIENT)) {
        os += (first ? "" : " | ");
        os += "CLIENT";
        first = false;
        flipped |= IComposerClient::Composition::CLIENT;
    }
    if ((o & IComposerClient::Composition::DEVICE) == static_cast<int32_t>(IComposerClient::Composition::DEVICE)) {
        os += (first ? "" : " | ");
        os += "DEVICE";
        first = false;
        flipped |= IComposerClient::Composition::DEVICE;
    }
    if ((o & IComposerClient::Composition::SOLID_COLOR) == static_cast<int32_t>(IComposerClient::Composition::SOLID_COLOR)) {
        os += (first ? "" : " | ");
        os += "SOLID_COLOR";
        first = false;
        flipped |= IComposerClient::Composition::SOLID_COLOR;
    }
    if ((o & IComposerClient::Composition::CURSOR) == static_cast<int32_t>(IComposerClient::Composition::CURSOR)) {
        os += (first ? "" : " | ");
        os += "CURSOR";
        first = false;
        flipped |= IComposerClient::Composition::CURSOR;
    }
    if ((o & IComposerClient::Composition::SIDEBAND) == static_cast<int32_t>(IComposerClient::Composition::SIDEBAND)) {
        os += (first ? "" : " | ");
        os += "SIDEBAND";
        first = false;
        flipped |= IComposerClient::Composition::SIDEBAND;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::Composition o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::Composition::INVALID) {
        return "INVALID";
    }
    if (o == IComposerClient::Composition::CLIENT) {
        return "CLIENT";
    }
    if (o == IComposerClient::Composition::DEVICE) {
        return "DEVICE";
    }
    if (o == IComposerClient::Composition::SOLID_COLOR) {
        return "SOLID_COLOR";
    }
    if (o == IComposerClient::Composition::CURSOR) {
        return "CURSOR";
    }
    if (o == IComposerClient::Composition::SIDEBAND) {
        return "SIDEBAND";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<IComposerClient::DisplayType>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::DisplayType::INVALID) == static_cast<int32_t>(IComposerClient::DisplayType::INVALID)) {
        os += (first ? "" : " | ");
        os += "INVALID";
        first = false;
        flipped |= IComposerClient::DisplayType::INVALID;
    }
    if ((o & IComposerClient::DisplayType::PHYSICAL) == static_cast<int32_t>(IComposerClient::DisplayType::PHYSICAL)) {
        os += (first ? "" : " | ");
        os += "PHYSICAL";
        first = false;
        flipped |= IComposerClient::DisplayType::PHYSICAL;
    }
    if ((o & IComposerClient::DisplayType::VIRTUAL) == static_cast<int32_t>(IComposerClient::DisplayType::VIRTUAL)) {
        os += (first ? "" : " | ");
        os += "VIRTUAL";
        first = false;
        flipped |= IComposerClient::DisplayType::VIRTUAL;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::DisplayType o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::DisplayType::INVALID) {
        return "INVALID";
    }
    if (o == IComposerClient::DisplayType::PHYSICAL) {
        return "PHYSICAL";
    }
    if (o == IComposerClient::DisplayType::VIRTUAL) {
        return "VIRTUAL";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<IComposerClient::HandleIndex>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::HandleIndex::EMPTY) == static_cast<int32_t>(IComposerClient::HandleIndex::EMPTY)) {
        os += (first ? "" : " | ");
        os += "EMPTY";
        first = false;
        flipped |= IComposerClient::HandleIndex::EMPTY;
    }
    if ((o & IComposerClient::HandleIndex::CACHED) == static_cast<int32_t>(IComposerClient::HandleIndex::CACHED)) {
        os += (first ? "" : " | ");
        os += "CACHED";
        first = false;
        flipped |= IComposerClient::HandleIndex::CACHED;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::HandleIndex o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::HandleIndex::EMPTY) {
        return "EMPTY";
    }
    if (o == IComposerClient::HandleIndex::CACHED) {
        return "CACHED";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

std::string toString(const IComposerClient::Rect& o) {
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

bool operator==(const IComposerClient::Rect& lhs, const IComposerClient::Rect& rhs) {
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

bool operator!=(const IComposerClient::Rect& lhs,const IComposerClient::Rect& rhs){
    return !(lhs == rhs);
}

std::string toString(const IComposerClient::FRect& o) {
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

bool operator==(const IComposerClient::FRect& lhs, const IComposerClient::FRect& rhs) {
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

bool operator!=(const IComposerClient::FRect& lhs,const IComposerClient::FRect& rhs){
    return !(lhs == rhs);
}

std::string toString(const IComposerClient::Color& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".r = ";
    os += ::android::hardware::toString(o.r);
    os += ", .g = ";
    os += ::android::hardware::toString(o.g);
    os += ", .b = ";
    os += ::android::hardware::toString(o.b);
    os += ", .a = ";
    os += ::android::hardware::toString(o.a);
    os += "}"; return os;
}

bool operator==(const IComposerClient::Color& lhs, const IComposerClient::Color& rhs) {
    if (lhs.r != rhs.r) {
        return false;
    }
    if (lhs.g != rhs.g) {
        return false;
    }
    if (lhs.b != rhs.b) {
        return false;
    }
    if (lhs.a != rhs.a) {
        return false;
    }
    return true;
}

bool operator!=(const IComposerClient::Color& lhs,const IComposerClient::Color& rhs){
    return !(lhs == rhs);
}

template<>
std::string toString<IComposerClient::Command>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & IComposerClient::Command::LENGTH_MASK) == static_cast<int32_t>(IComposerClient::Command::LENGTH_MASK)) {
        os += (first ? "" : " | ");
        os += "LENGTH_MASK";
        first = false;
        flipped |= IComposerClient::Command::LENGTH_MASK;
    }
    if ((o & IComposerClient::Command::OPCODE_SHIFT) == static_cast<int32_t>(IComposerClient::Command::OPCODE_SHIFT)) {
        os += (first ? "" : " | ");
        os += "OPCODE_SHIFT";
        first = false;
        flipped |= IComposerClient::Command::OPCODE_SHIFT;
    }
    if ((o & IComposerClient::Command::OPCODE_MASK) == static_cast<int32_t>(IComposerClient::Command::OPCODE_MASK)) {
        os += (first ? "" : " | ");
        os += "OPCODE_MASK";
        first = false;
        flipped |= IComposerClient::Command::OPCODE_MASK;
    }
    if ((o & IComposerClient::Command::SELECT_DISPLAY) == static_cast<int32_t>(IComposerClient::Command::SELECT_DISPLAY)) {
        os += (first ? "" : " | ");
        os += "SELECT_DISPLAY";
        first = false;
        flipped |= IComposerClient::Command::SELECT_DISPLAY;
    }
    if ((o & IComposerClient::Command::SELECT_LAYER) == static_cast<int32_t>(IComposerClient::Command::SELECT_LAYER)) {
        os += (first ? "" : " | ");
        os += "SELECT_LAYER";
        first = false;
        flipped |= IComposerClient::Command::SELECT_LAYER;
    }
    if ((o & IComposerClient::Command::SET_ERROR) == static_cast<int32_t>(IComposerClient::Command::SET_ERROR)) {
        os += (first ? "" : " | ");
        os += "SET_ERROR";
        first = false;
        flipped |= IComposerClient::Command::SET_ERROR;
    }
    if ((o & IComposerClient::Command::SET_CHANGED_COMPOSITION_TYPES) == static_cast<int32_t>(IComposerClient::Command::SET_CHANGED_COMPOSITION_TYPES)) {
        os += (first ? "" : " | ");
        os += "SET_CHANGED_COMPOSITION_TYPES";
        first = false;
        flipped |= IComposerClient::Command::SET_CHANGED_COMPOSITION_TYPES;
    }
    if ((o & IComposerClient::Command::SET_DISPLAY_REQUESTS) == static_cast<int32_t>(IComposerClient::Command::SET_DISPLAY_REQUESTS)) {
        os += (first ? "" : " | ");
        os += "SET_DISPLAY_REQUESTS";
        first = false;
        flipped |= IComposerClient::Command::SET_DISPLAY_REQUESTS;
    }
    if ((o & IComposerClient::Command::SET_PRESENT_FENCE) == static_cast<int32_t>(IComposerClient::Command::SET_PRESENT_FENCE)) {
        os += (first ? "" : " | ");
        os += "SET_PRESENT_FENCE";
        first = false;
        flipped |= IComposerClient::Command::SET_PRESENT_FENCE;
    }
    if ((o & IComposerClient::Command::SET_RELEASE_FENCES) == static_cast<int32_t>(IComposerClient::Command::SET_RELEASE_FENCES)) {
        os += (first ? "" : " | ");
        os += "SET_RELEASE_FENCES";
        first = false;
        flipped |= IComposerClient::Command::SET_RELEASE_FENCES;
    }
    if ((o & IComposerClient::Command::SET_COLOR_TRANSFORM) == static_cast<int32_t>(IComposerClient::Command::SET_COLOR_TRANSFORM)) {
        os += (first ? "" : " | ");
        os += "SET_COLOR_TRANSFORM";
        first = false;
        flipped |= IComposerClient::Command::SET_COLOR_TRANSFORM;
    }
    if ((o & IComposerClient::Command::SET_CLIENT_TARGET) == static_cast<int32_t>(IComposerClient::Command::SET_CLIENT_TARGET)) {
        os += (first ? "" : " | ");
        os += "SET_CLIENT_TARGET";
        first = false;
        flipped |= IComposerClient::Command::SET_CLIENT_TARGET;
    }
    if ((o & IComposerClient::Command::SET_OUTPUT_BUFFER) == static_cast<int32_t>(IComposerClient::Command::SET_OUTPUT_BUFFER)) {
        os += (first ? "" : " | ");
        os += "SET_OUTPUT_BUFFER";
        first = false;
        flipped |= IComposerClient::Command::SET_OUTPUT_BUFFER;
    }
    if ((o & IComposerClient::Command::VALIDATE_DISPLAY) == static_cast<int32_t>(IComposerClient::Command::VALIDATE_DISPLAY)) {
        os += (first ? "" : " | ");
        os += "VALIDATE_DISPLAY";
        first = false;
        flipped |= IComposerClient::Command::VALIDATE_DISPLAY;
    }
    if ((o & IComposerClient::Command::ACCEPT_DISPLAY_CHANGES) == static_cast<int32_t>(IComposerClient::Command::ACCEPT_DISPLAY_CHANGES)) {
        os += (first ? "" : " | ");
        os += "ACCEPT_DISPLAY_CHANGES";
        first = false;
        flipped |= IComposerClient::Command::ACCEPT_DISPLAY_CHANGES;
    }
    if ((o & IComposerClient::Command::PRESENT_DISPLAY) == static_cast<int32_t>(IComposerClient::Command::PRESENT_DISPLAY)) {
        os += (first ? "" : " | ");
        os += "PRESENT_DISPLAY";
        first = false;
        flipped |= IComposerClient::Command::PRESENT_DISPLAY;
    }
    if ((o & IComposerClient::Command::PRESENT_OR_VALIDATE_DISPLAY) == static_cast<int32_t>(IComposerClient::Command::PRESENT_OR_VALIDATE_DISPLAY)) {
        os += (first ? "" : " | ");
        os += "PRESENT_OR_VALIDATE_DISPLAY";
        first = false;
        flipped |= IComposerClient::Command::PRESENT_OR_VALIDATE_DISPLAY;
    }
    if ((o & IComposerClient::Command::SET_LAYER_CURSOR_POSITION) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_CURSOR_POSITION)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_CURSOR_POSITION";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_CURSOR_POSITION;
    }
    if ((o & IComposerClient::Command::SET_LAYER_BUFFER) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_BUFFER)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_BUFFER";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_BUFFER;
    }
    if ((o & IComposerClient::Command::SET_LAYER_SURFACE_DAMAGE) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_SURFACE_DAMAGE)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_SURFACE_DAMAGE";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_SURFACE_DAMAGE;
    }
    if ((o & IComposerClient::Command::SET_LAYER_BLEND_MODE) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_BLEND_MODE)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_BLEND_MODE";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_BLEND_MODE;
    }
    if ((o & IComposerClient::Command::SET_LAYER_COLOR) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_COLOR)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_COLOR";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_COLOR;
    }
    if ((o & IComposerClient::Command::SET_LAYER_COMPOSITION_TYPE) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_COMPOSITION_TYPE)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_COMPOSITION_TYPE";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_COMPOSITION_TYPE;
    }
    if ((o & IComposerClient::Command::SET_LAYER_DATASPACE) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_DATASPACE)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_DATASPACE";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_DATASPACE;
    }
    if ((o & IComposerClient::Command::SET_LAYER_DISPLAY_FRAME) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_DISPLAY_FRAME)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_DISPLAY_FRAME";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_DISPLAY_FRAME;
    }
    if ((o & IComposerClient::Command::SET_LAYER_PLANE_ALPHA) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_PLANE_ALPHA)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_PLANE_ALPHA";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_PLANE_ALPHA;
    }
    if ((o & IComposerClient::Command::SET_LAYER_SIDEBAND_STREAM) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_SIDEBAND_STREAM)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_SIDEBAND_STREAM";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_SIDEBAND_STREAM;
    }
    if ((o & IComposerClient::Command::SET_LAYER_SOURCE_CROP) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_SOURCE_CROP)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_SOURCE_CROP";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_SOURCE_CROP;
    }
    if ((o & IComposerClient::Command::SET_LAYER_TRANSFORM) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_TRANSFORM)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_TRANSFORM";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_TRANSFORM;
    }
    if ((o & IComposerClient::Command::SET_LAYER_VISIBLE_REGION) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_VISIBLE_REGION)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_VISIBLE_REGION";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_VISIBLE_REGION;
    }
    if ((o & IComposerClient::Command::SET_LAYER_Z_ORDER) == static_cast<int32_t>(IComposerClient::Command::SET_LAYER_Z_ORDER)) {
        os += (first ? "" : " | ");
        os += "SET_LAYER_Z_ORDER";
        first = false;
        flipped |= IComposerClient::Command::SET_LAYER_Z_ORDER;
    }
    if ((o & IComposerClient::Command::SET_PRESENT_OR_VALIDATE_DISPLAY_RESULT) == static_cast<int32_t>(IComposerClient::Command::SET_PRESENT_OR_VALIDATE_DISPLAY_RESULT)) {
        os += (first ? "" : " | ");
        os += "SET_PRESENT_OR_VALIDATE_DISPLAY_RESULT";
        first = false;
        flipped |= IComposerClient::Command::SET_PRESENT_OR_VALIDATE_DISPLAY_RESULT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(IComposerClient::Command o) {
    using ::android::hardware::details::toHexString;
    if (o == IComposerClient::Command::LENGTH_MASK) {
        return "LENGTH_MASK";
    }
    if (o == IComposerClient::Command::OPCODE_SHIFT) {
        return "OPCODE_SHIFT";
    }
    if (o == IComposerClient::Command::OPCODE_MASK) {
        return "OPCODE_MASK";
    }
    if (o == IComposerClient::Command::SELECT_DISPLAY) {
        return "SELECT_DISPLAY";
    }
    if (o == IComposerClient::Command::SELECT_LAYER) {
        return "SELECT_LAYER";
    }
    if (o == IComposerClient::Command::SET_ERROR) {
        return "SET_ERROR";
    }
    if (o == IComposerClient::Command::SET_CHANGED_COMPOSITION_TYPES) {
        return "SET_CHANGED_COMPOSITION_TYPES";
    }
    if (o == IComposerClient::Command::SET_DISPLAY_REQUESTS) {
        return "SET_DISPLAY_REQUESTS";
    }
    if (o == IComposerClient::Command::SET_PRESENT_FENCE) {
        return "SET_PRESENT_FENCE";
    }
    if (o == IComposerClient::Command::SET_RELEASE_FENCES) {
        return "SET_RELEASE_FENCES";
    }
    if (o == IComposerClient::Command::SET_COLOR_TRANSFORM) {
        return "SET_COLOR_TRANSFORM";
    }
    if (o == IComposerClient::Command::SET_CLIENT_TARGET) {
        return "SET_CLIENT_TARGET";
    }
    if (o == IComposerClient::Command::SET_OUTPUT_BUFFER) {
        return "SET_OUTPUT_BUFFER";
    }
    if (o == IComposerClient::Command::VALIDATE_DISPLAY) {
        return "VALIDATE_DISPLAY";
    }
    if (o == IComposerClient::Command::ACCEPT_DISPLAY_CHANGES) {
        return "ACCEPT_DISPLAY_CHANGES";
    }
    if (o == IComposerClient::Command::PRESENT_DISPLAY) {
        return "PRESENT_DISPLAY";
    }
    if (o == IComposerClient::Command::PRESENT_OR_VALIDATE_DISPLAY) {
        return "PRESENT_OR_VALIDATE_DISPLAY";
    }
    if (o == IComposerClient::Command::SET_LAYER_CURSOR_POSITION) {
        return "SET_LAYER_CURSOR_POSITION";
    }
    if (o == IComposerClient::Command::SET_LAYER_BUFFER) {
        return "SET_LAYER_BUFFER";
    }
    if (o == IComposerClient::Command::SET_LAYER_SURFACE_DAMAGE) {
        return "SET_LAYER_SURFACE_DAMAGE";
    }
    if (o == IComposerClient::Command::SET_LAYER_BLEND_MODE) {
        return "SET_LAYER_BLEND_MODE";
    }
    if (o == IComposerClient::Command::SET_LAYER_COLOR) {
        return "SET_LAYER_COLOR";
    }
    if (o == IComposerClient::Command::SET_LAYER_COMPOSITION_TYPE) {
        return "SET_LAYER_COMPOSITION_TYPE";
    }
    if (o == IComposerClient::Command::SET_LAYER_DATASPACE) {
        return "SET_LAYER_DATASPACE";
    }
    if (o == IComposerClient::Command::SET_LAYER_DISPLAY_FRAME) {
        return "SET_LAYER_DISPLAY_FRAME";
    }
    if (o == IComposerClient::Command::SET_LAYER_PLANE_ALPHA) {
        return "SET_LAYER_PLANE_ALPHA";
    }
    if (o == IComposerClient::Command::SET_LAYER_SIDEBAND_STREAM) {
        return "SET_LAYER_SIDEBAND_STREAM";
    }
    if (o == IComposerClient::Command::SET_LAYER_SOURCE_CROP) {
        return "SET_LAYER_SOURCE_CROP";
    }
    if (o == IComposerClient::Command::SET_LAYER_TRANSFORM) {
        return "SET_LAYER_TRANSFORM";
    }
    if (o == IComposerClient::Command::SET_LAYER_VISIBLE_REGION) {
        return "SET_LAYER_VISIBLE_REGION";
    }
    if (o == IComposerClient::Command::SET_LAYER_Z_ORDER) {
        return "SET_LAYER_Z_ORDER";
    }
    if (o == IComposerClient::Command::SET_PRESENT_OR_VALIDATE_DISPLAY_RESULT) {
        return "SET_PRESENT_OR_VALIDATE_DISPLAY_RESULT";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

std::string toString(const ::android::sp<IComposerClient>& o) {
    std::string os = "[class or subclass of ";
    os += IComposerClient::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}

const char* IComposerClient::descriptor("android.hardware.graphics.composer@2.1::IComposerClient");

__attribute__((constructor))static void static_constructor() {
    ::android::hardware::details::gBnConstructorMap.set(IComposerClient::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwComposerClient(static_cast<IComposerClient *>(iIntf));
            });
    ::android::hardware::details::gBsConstructorMap.set(IComposerClient::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsComposerClient(static_cast<IComposerClient *>(iIntf));
            });
};

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::gBnConstructorMap.erase(IComposerClient::descriptor);
    ::android::hardware::details::gBsConstructorMap.erase(IComposerClient::descriptor);
};

// Methods from IComposerClient follow.
// no default implementation for: ::android::hardware::Return<void> IComposerClient::registerCallback(const ::android::sp<IComposerCallback>& callback)
// no default implementation for: ::android::hardware::Return<uint32_t> IComposerClient::getMaxVirtualDisplayCount()
// no default implementation for: ::android::hardware::Return<void> IComposerClient::createVirtualDisplay(uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat formatHint, uint32_t outputBufferSlotCount, createVirtualDisplay_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::destroyVirtualDisplay(uint64_t display)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::createLayer(uint64_t display, uint32_t bufferSlotCount, createLayer_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::destroyLayer(uint64_t display, uint64_t layer)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getActiveConfig(uint64_t display, getActiveConfig_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::getClientTargetSupport(uint64_t display, uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, ::android::hardware::graphics::common::V1_0::Dataspace dataspace)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getColorModes(uint64_t display, getColorModes_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getDisplayAttribute(uint64_t display, uint32_t config, IComposerClient::Attribute attribute, getDisplayAttribute_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getDisplayConfigs(uint64_t display, getDisplayConfigs_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getDisplayName(uint64_t display, getDisplayName_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getDisplayType(uint64_t display, getDisplayType_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getDozeSupport(uint64_t display, getDozeSupport_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getHdrCapabilities(uint64_t display, getHdrCapabilities_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::setClientTargetSlotCount(uint64_t display, uint32_t clientTargetSlotCount)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::setActiveConfig(uint64_t display, uint32_t config)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::setColorMode(uint64_t display, ::android::hardware::graphics::common::V1_0::ColorMode mode)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::setPowerMode(uint64_t display, IComposerClient::PowerMode mode)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::setVsyncEnabled(uint64_t display, IComposerClient::Vsync enabled)
// no default implementation for: ::android::hardware::Return<Error> IComposerClient::setInputCommandQueue(const ::android::hardware::MQDescriptorSync<uint32_t>& descriptor)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::getOutputCommandQueue(getOutputCommandQueue_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComposerClient::executeCommands(uint32_t inLength, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& inHandles, executeCommands_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IComposerClient::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        IComposerClient::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IComposerClient::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();}

::android::hardware::Return<void> IComposerClient::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(IComposerClient::descriptor);
    return ::android::hardware::Void();}

::android::hardware::Return<void> IComposerClient::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){97,238,67,255,230,251,109,190,139,34,220,23,197,31,243,213,186,112,63,198,2,156,186,33,31,144,31,61,121,200,167,45} /* 61ee43ffe6fb6dbe8b22dc17c51ff3d5ba703fc6029cba211f901f3d79c8a72d */,
        (uint8_t[32]){189,218,182,24,77,122,52,109,166,160,125,192,130,140,241,154,105,111,76,170,54,17,197,31,46,20,86,90,20,180,15,217} /* bddab6184d7a346da6a07dc0828cf19a696f4caa3611c51f2e14565a14b40fd9 */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IComposerClient::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IComposerClient::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IComposerClient::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IComposerClient::getDebugInfo(getDebugInfo_cb _hidl_cb){
    _hidl_cb({ -1 /* pid */, 0 /* ptr */, 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    });
    return ::android::hardware::Void();}

::android::hardware::Return<void> IComposerClient::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();}

::android::hardware::Return<bool> IComposerClient::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


// static 
::android::hardware::Return<::android::sp<IComposerClient>> IComposerClient::castFrom(const ::android::sp<IComposerClient>& parent, bool /* emitError */) {
    return parent;
}

// static 
::android::hardware::Return<::android::sp<IComposerClient>> IComposerClient::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IComposerClient, ::android::hidl::base::V1_0::IBase, BpHwComposerClient>(
            parent, "android.hardware.graphics.composer@2.1::IComposerClient", emitError);
}

BpHwComposerClient::BpHwComposerClient(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IComposerClient>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.composer@2.1", "IComposerClient") {
}

// Methods from IComposerClient follow.
::android::hardware::Return<void> BpHwComposerClient::_hidl_registerCallback(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<IComposerCallback>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::registerCallback::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "registerCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (callback == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::toBinder<
                IComposerCallback>(callback);
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* registerCallback */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "registerCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<uint32_t> BpHwComposerClient::_hidl_getMaxVirtualDisplayCount(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getMaxVirtualDisplayCount::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getMaxVirtualDisplayCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    uint32_t _hidl_out_count;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getMaxVirtualDisplayCount */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_count);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_count);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getMaxVirtualDisplayCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint32_t>(_hidl_out_count);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<uint32_t>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_createVirtualDisplay(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat formatHint, uint32_t outputBufferSlotCount, createVirtualDisplay_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::createVirtualDisplay::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&formatHint);
        _hidl_args.push_back((void *)&outputBufferSlotCount);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "createVirtualDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    uint64_t _hidl_out_display;
    ::android::hardware::graphics::common::V1_0::PixelFormat _hidl_out_format;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(width);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(height);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)formatHint);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(outputBufferSlotCount);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* createVirtualDisplay */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_format);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, _hidl_out_display, _hidl_out_format);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)&_hidl_out_display);
        _hidl_args.push_back((void *)&_hidl_out_format);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "createVirtualDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_destroyVirtualDisplay(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::destroyVirtualDisplay::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "destroyVirtualDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* destroyVirtualDisplay */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "destroyVirtualDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_createLayer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, uint32_t bufferSlotCount, createLayer_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::createLayer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&bufferSlotCount);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "createLayer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    uint64_t _hidl_out_layer;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(bufferSlotCount);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* createLayer */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint64(&_hidl_out_layer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, _hidl_out_layer);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)&_hidl_out_layer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "createLayer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_destroyLayer(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, uint64_t layer) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::destroyLayer::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&layer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "destroyLayer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(layer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* destroyLayer */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "destroyLayer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getActiveConfig(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, getActiveConfig_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getActiveConfig::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getActiveConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    uint32_t _hidl_out_config;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* getActiveConfig */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_config);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, _hidl_out_config);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)&_hidl_out_config);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getActiveConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_getClientTargetSupport(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, ::android::hardware::graphics::common::V1_0::Dataspace dataspace) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getClientTargetSupport::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&format);
        _hidl_args.push_back((void *)&dataspace);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getClientTargetSupport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(width);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(height);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)format);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)dataspace);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* getClientTargetSupport */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getClientTargetSupport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getColorModes(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, getColorModes_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getColorModes::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getColorModes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    const ::android::hardware::hidl_vec<::android::hardware::graphics::common::V1_0::ColorMode>* _hidl_out_modes;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* getColorModes */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_modes_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_modes), &_hidl__hidl_out_modes_parent,  reinterpret_cast<const void **>(&_hidl_out_modes));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_modes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::graphics::common::V1_0::ColorMode> &>(*_hidl_out_modes),
            _hidl_reply,
            _hidl__hidl_out_modes_parent,
            0 /* parentOffset */, &_hidl__hidl_out_modes_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, *_hidl_out_modes);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)_hidl_out_modes);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getColorModes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getDisplayAttribute(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, uint32_t config, IComposerClient::Attribute attribute, getDisplayAttribute_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDisplayAttribute::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&config);
        _hidl_args.push_back((void *)&attribute);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayAttribute", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    int32_t _hidl_out_value;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(config);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)attribute);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* getDisplayAttribute */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readInt32(&_hidl_out_value);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, _hidl_out_value);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)&_hidl_out_value);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayAttribute", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getDisplayConfigs(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, getDisplayConfigs_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDisplayConfigs::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayConfigs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    const ::android::hardware::hidl_vec<uint32_t>* _hidl_out_configs;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* getDisplayConfigs */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_configs_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_configs), &_hidl__hidl_out_configs_parent,  reinterpret_cast<const void **>(&_hidl_out_configs));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_configs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*_hidl_out_configs),
            _hidl_reply,
            _hidl__hidl_out_configs_parent,
            0 /* parentOffset */, &_hidl__hidl_out_configs_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, *_hidl_out_configs);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)_hidl_out_configs);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayConfigs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getDisplayName(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, getDisplayName_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDisplayName::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    const ::android::hardware::hidl_string* _hidl_out_name;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* getDisplayName */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_name_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_name), &_hidl__hidl_out_name_parent,  reinterpret_cast<const void **>(&_hidl_out_name));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*_hidl_out_name),
            _hidl_reply,
            _hidl__hidl_out_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, *_hidl_out_name);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)_hidl_out_name);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getDisplayType(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, getDisplayType_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDisplayType::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    IComposerClient::DisplayType _hidl_out_type;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* getDisplayType */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, _hidl_out_type);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)&_hidl_out_type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getDozeSupport(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, getDozeSupport_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDozeSupport::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDozeSupport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    bool _hidl_out_support;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* getDozeSupport */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_support);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, _hidl_out_support);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)&_hidl_out_support);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDozeSupport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getHdrCapabilities(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, getHdrCapabilities_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getHdrCapabilities::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getHdrCapabilities", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    const ::android::hardware::hidl_vec<::android::hardware::graphics::common::V1_0::Hdr>* _hidl_out_types;
    float _hidl_out_maxLuminance;
    float _hidl_out_maxAverageLuminance;
    float _hidl_out_minLuminance;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* getHdrCapabilities */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_types_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_types), &_hidl__hidl_out_types_parent,  reinterpret_cast<const void **>(&_hidl_out_types));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_types_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::graphics::common::V1_0::Hdr> &>(*_hidl_out_types),
            _hidl_reply,
            _hidl__hidl_out_types_parent,
            0 /* parentOffset */, &_hidl__hidl_out_types_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readFloat(&_hidl_out_maxLuminance);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readFloat(&_hidl_out_maxAverageLuminance);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readFloat(&_hidl_out_minLuminance);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, *_hidl_out_types, _hidl_out_maxLuminance, _hidl_out_maxAverageLuminance, _hidl_out_minLuminance);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)_hidl_out_types);
        _hidl_args.push_back((void *)&_hidl_out_maxLuminance);
        _hidl_args.push_back((void *)&_hidl_out_maxAverageLuminance);
        _hidl_args.push_back((void *)&_hidl_out_minLuminance);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getHdrCapabilities", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_setClientTargetSlotCount(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, uint32_t clientTargetSlotCount) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setClientTargetSlotCount::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&clientTargetSlotCount);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setClientTargetSlotCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(clientTargetSlotCount);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* setClientTargetSlotCount */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setClientTargetSlotCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_setActiveConfig(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, uint32_t config) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setActiveConfig::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&config);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setActiveConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(config);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* setActiveConfig */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setActiveConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_setColorMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, ::android::hardware::graphics::common::V1_0::ColorMode mode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setColorMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setColorMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* setColorMode */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setColorMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_setPowerMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, IComposerClient::PowerMode mode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setPowerMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setPowerMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(19 /* setPowerMode */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setPowerMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_setVsyncEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t display, IComposerClient::Vsync enabled) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setVsyncEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setVsyncEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(display);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)enabled);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(20 /* setVsyncEnabled */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setVsyncEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<Error> BpHwComposerClient::_hidl_setInputCommandQueue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::MQDescriptorSync<uint32_t>& descriptor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setInputCommandQueue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&descriptor);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setInputCommandQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_descriptor_parent;

    _hidl_err = _hidl_data.writeBuffer(&descriptor, sizeof(descriptor), &_hidl_descriptor_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            descriptor,
            &_hidl_data,
            _hidl_descriptor_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(21 /* setInputCommandQueue */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setInputCommandQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<Error>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_getOutputCommandQueue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getOutputCommandQueue_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getOutputCommandQueue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getOutputCommandQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    const ::android::hardware::MQDescriptorSync<uint32_t>* _hidl_out_descriptor;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(22 /* getOutputCommandQueue */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_descriptor_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_descriptor), &_hidl__hidl_out_descriptor_parent,  reinterpret_cast<const void **>(&_hidl_out_descriptor));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::MQDescriptorSync<uint32_t> &>(*_hidl_out_descriptor),
            _hidl_reply,
            _hidl__hidl_out_descriptor_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_cb(_hidl_out_error, *_hidl_out_descriptor);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)_hidl_out_descriptor);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getOutputCommandQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwComposerClient::_hidl_executeCommands(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t inLength, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& inHandles, executeCommands_cb _hidl_cb) {
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::executeCommands::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&inLength);
        _hidl_args.push_back((void *)&inHandles);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "executeCommands", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::hardware::Status _hidl_status;

    Error _hidl_out_error;
    bool _hidl_out_outQueueChanged;
    uint32_t _hidl_out_outLength;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>* _hidl_out_outHandles;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComposerClient::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(inLength);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inHandles_parent;

    _hidl_err = _hidl_data.writeBuffer(&inHandles, sizeof(inHandles), &_hidl_inHandles_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inHandles_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inHandles,
            &_hidl_data,
            _hidl_inHandles_parent,
            0 /* parentOffset */, &_hidl_inHandles_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < inHandles.size(); ++_hidl_index_0) {
        _hidl_err = _hidl_data.writeEmbeddedNativeHandle(
                inHandles[_hidl_index_0],
                _hidl_inHandles_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(23 /* executeCommands */, _hidl_data, &_hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_outQueueChanged);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_reply.readUint32(&_hidl_out_outLength);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_outHandles_parent;

    _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outHandles), &_hidl__hidl_out_outHandles_parent,  reinterpret_cast<const void **>(&_hidl_out_outHandles));

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl__hidl_out_outHandles_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(*_hidl_out_outHandles),
            _hidl_reply,
            _hidl__hidl_out_outHandles_parent,
            0 /* parentOffset */, &_hidl__hidl_out_outHandles_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outHandles->size(); ++_hidl_index_0) {
        const native_handle_t *_hidl__hidl_out_outHandles_deref_indexed_ptr;
        _hidl_err = _hidl_reply.readNullableEmbeddedNativeHandle(
                _hidl__hidl_out_outHandles_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle),
                &_hidl__hidl_out_outHandles_deref_indexed_ptr
                );

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_cb(_hidl_out_error, _hidl_out_outQueueChanged, _hidl_out_outLength, *_hidl_out_outHandles);

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        _hidl_args.push_back((void *)&_hidl_out_outQueueChanged);
        _hidl_args.push_back((void *)&_hidl_out_outLength);
        _hidl_args.push_back((void *)_hidl_out_outHandles);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "executeCommands", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from IComposerClient follow.
::android::hardware::Return<void> BpHwComposerClient::registerCallback(const ::android::sp<IComposerCallback>& callback){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_registerCallback(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<uint32_t> BpHwComposerClient::getMaxVirtualDisplayCount(){
    ::android::hardware::Return<uint32_t>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getMaxVirtualDisplayCount(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::createVirtualDisplay(uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat formatHint, uint32_t outputBufferSlotCount, createVirtualDisplay_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_createVirtualDisplay(this, this, width, height, formatHint, outputBufferSlotCount, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::destroyVirtualDisplay(uint64_t display){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_destroyVirtualDisplay(this, this, display);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::createLayer(uint64_t display, uint32_t bufferSlotCount, createLayer_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_createLayer(this, this, display, bufferSlotCount, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::destroyLayer(uint64_t display, uint64_t layer){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_destroyLayer(this, this, display, layer);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getActiveConfig(uint64_t display, getActiveConfig_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getActiveConfig(this, this, display, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::getClientTargetSupport(uint64_t display, uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, ::android::hardware::graphics::common::V1_0::Dataspace dataspace){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getClientTargetSupport(this, this, display, width, height, format, dataspace);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getColorModes(uint64_t display, getColorModes_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getColorModes(this, this, display, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getDisplayAttribute(uint64_t display, uint32_t config, IComposerClient::Attribute attribute, getDisplayAttribute_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getDisplayAttribute(this, this, display, config, attribute, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getDisplayConfigs(uint64_t display, getDisplayConfigs_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getDisplayConfigs(this, this, display, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getDisplayName(uint64_t display, getDisplayName_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getDisplayName(this, this, display, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getDisplayType(uint64_t display, getDisplayType_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getDisplayType(this, this, display, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getDozeSupport(uint64_t display, getDozeSupport_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getDozeSupport(this, this, display, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getHdrCapabilities(uint64_t display, getHdrCapabilities_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getHdrCapabilities(this, this, display, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::setClientTargetSlotCount(uint64_t display, uint32_t clientTargetSlotCount){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_setClientTargetSlotCount(this, this, display, clientTargetSlotCount);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::setActiveConfig(uint64_t display, uint32_t config){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_setActiveConfig(this, this, display, config);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::setColorMode(uint64_t display, ::android::hardware::graphics::common::V1_0::ColorMode mode){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_setColorMode(this, this, display, mode);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::setPowerMode(uint64_t display, IComposerClient::PowerMode mode){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_setPowerMode(this, this, display, mode);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::setVsyncEnabled(uint64_t display, IComposerClient::Vsync enabled){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_setVsyncEnabled(this, this, display, enabled);

    return _hidl_out;
}

::android::hardware::Return<Error> BpHwComposerClient::setInputCommandQueue(const ::android::hardware::MQDescriptorSync<uint32_t>& descriptor){
    ::android::hardware::Return<Error>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_setInputCommandQueue(this, this, descriptor);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getOutputCommandQueue(getOutputCommandQueue_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_getOutputCommandQueue(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::executeCommands(uint32_t inLength, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& inHandles, executeCommands_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::graphics::composer::V2_1::BpHwComposerClient::_hidl_executeCommands(this, this, inLength, inHandles, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwComposerClient::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwComposerClient::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwComposerClient::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComposerClient::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwComposerClient::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    for (auto it = _hidl_mDeathRecipients.begin();it != _hidl_mDeathRecipients.end();++it) {
        if ((*it)->getRecipient() == recipient) {
            ::android::status_t status = remote()->unlinkToDeath(*it);
            _hidl_mDeathRecipients.erase(it);
            return status == ::android::OK;
        }}
    return false;
}


BnHwComposerClient::BnHwComposerClient(const ::android::sp<IComposerClient> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.graphics.composer@2.1", "IComposerClient") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::details::gServicePrioMap.get(_hidl_impl, {SCHED_NORMAL, 0});
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
}

BnHwComposerClient::~BnHwComposerClient() {
    ::android::hardware::details::gBnMap.eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from IComposerClient follow.
::android::status_t BnHwComposerClient::_hidl_registerCallback(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<IComposerCallback> callback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_callback_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_callback_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<IComposerCallback,BpHwComposerCallback,BnHwComposerCallback>(_hidl_callback_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::registerCallback::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "registerCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->registerCallback(callback);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "registerCallback", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getMaxVirtualDisplayCount(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getMaxVirtualDisplayCount::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getMaxVirtualDisplayCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    uint32_t _hidl_out_count = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getMaxVirtualDisplayCount();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32(_hidl_out_count);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_count);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getMaxVirtualDisplayCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_createVirtualDisplay(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t width;
    uint32_t height;
    ::android::hardware::graphics::common::V1_0::PixelFormat formatHint;
    uint32_t outputBufferSlotCount;

    _hidl_err = _hidl_data.readUint32(&width);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&height);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&formatHint);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&outputBufferSlotCount);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::createVirtualDisplay::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&formatHint);
        _hidl_args.push_back((void *)&outputBufferSlotCount);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "createVirtualDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->createVirtualDisplay(width, height, formatHint, outputBufferSlotCount, [&](const auto &_hidl_out_error, const auto &_hidl_out_display, const auto &_hidl_out_format) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createVirtualDisplay: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint64(_hidl_out_display);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_format);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_display);
            _hidl_args.push_back((void *)&_hidl_out_format);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "createVirtualDisplay", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createVirtualDisplay: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_destroyVirtualDisplay(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::destroyVirtualDisplay::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "destroyVirtualDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->destroyVirtualDisplay(display);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "destroyVirtualDisplay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_createLayer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    uint32_t bufferSlotCount;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&bufferSlotCount);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::createLayer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&bufferSlotCount);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "createLayer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->createLayer(display, bufferSlotCount, [&](const auto &_hidl_out_error, const auto &_hidl_out_layer) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createLayer: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint64(_hidl_out_layer);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_layer);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "createLayer", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createLayer: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_destroyLayer(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    uint64_t layer;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&layer);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::destroyLayer::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&layer);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "destroyLayer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->destroyLayer(display, layer);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "destroyLayer", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getActiveConfig(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getActiveConfig::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getActiveConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getActiveConfig(display, [&](const auto &_hidl_out_error, const auto &_hidl_out_config) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getActiveConfig: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_config);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_config);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getActiveConfig", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getActiveConfig: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getClientTargetSupport(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    uint32_t width;
    uint32_t height;
    ::android::hardware::graphics::common::V1_0::PixelFormat format;
    ::android::hardware::graphics::common::V1_0::Dataspace dataspace;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&width);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&height);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&format);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&dataspace);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getClientTargetSupport::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&width);
        _hidl_args.push_back((void *)&height);
        _hidl_args.push_back((void *)&format);
        _hidl_args.push_back((void *)&dataspace);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getClientTargetSupport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getClientTargetSupport(display, width, height, format, dataspace);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getClientTargetSupport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getColorModes(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getColorModes::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getColorModes", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getColorModes(display, [&](const auto &_hidl_out_error, const auto &_hidl_out_modes) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getColorModes: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_modes_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_modes, sizeof(_hidl_out_modes), &_hidl__hidl_out_modes_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_modes_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_modes,
                _hidl_reply,
                _hidl__hidl_out_modes_parent,
                0 /* parentOffset */, &_hidl__hidl_out_modes_child);

        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_modes);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getColorModes", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getColorModes: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getDisplayAttribute(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    uint32_t config;
    IComposerClient::Attribute attribute;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&config);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&attribute);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDisplayAttribute::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&config);
        _hidl_args.push_back((void *)&attribute);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayAttribute", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getDisplayAttribute(display, config, attribute, [&](const auto &_hidl_out_error, const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDisplayAttribute: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeInt32(_hidl_out_value);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayAttribute", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDisplayAttribute: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getDisplayConfigs(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDisplayConfigs::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayConfigs", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getDisplayConfigs(display, [&](const auto &_hidl_out_error, const auto &_hidl_out_configs) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDisplayConfigs: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_configs_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_configs, sizeof(_hidl_out_configs), &_hidl__hidl_out_configs_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_configs_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_configs,
                _hidl_reply,
                _hidl__hidl_out_configs_parent,
                0 /* parentOffset */, &_hidl__hidl_out_configs_child);

        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_configs);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayConfigs", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDisplayConfigs: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getDisplayName(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDisplayName::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getDisplayName(display, [&](const auto &_hidl_out_error, const auto &_hidl_out_name) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDisplayName: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_name_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_name, sizeof(_hidl_out_name), &_hidl__hidl_out_name_parent);
        /* _hidl_err ignored! */

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_name,
                _hidl_reply,
                _hidl__hidl_out_name_parent,
                0 /* parentOffset */);

        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_name);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayName", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDisplayName: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getDisplayType(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDisplayType::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayType", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getDisplayType(display, [&](const auto &_hidl_out_error, const auto &_hidl_out_type) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDisplayType: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_type);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_type);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDisplayType", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDisplayType: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getDozeSupport(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getDozeSupport::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDozeSupport", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getDozeSupport(display, [&](const auto &_hidl_out_error, const auto &_hidl_out_support) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDozeSupport: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeBool(_hidl_out_support);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_support);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getDozeSupport", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDozeSupport: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getHdrCapabilities(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getHdrCapabilities::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getHdrCapabilities", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getHdrCapabilities(display, [&](const auto &_hidl_out_error, const auto &_hidl_out_types, const auto &_hidl_out_maxLuminance, const auto &_hidl_out_maxAverageLuminance, const auto &_hidl_out_minLuminance) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getHdrCapabilities: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_types_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_types, sizeof(_hidl_out_types), &_hidl__hidl_out_types_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_types_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_types,
                _hidl_reply,
                _hidl__hidl_out_types_parent,
                0 /* parentOffset */, &_hidl__hidl_out_types_child);

        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeFloat(_hidl_out_maxLuminance);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeFloat(_hidl_out_maxAverageLuminance);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeFloat(_hidl_out_minLuminance);
        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_types);
            _hidl_args.push_back((void *)&_hidl_out_maxLuminance);
            _hidl_args.push_back((void *)&_hidl_out_maxAverageLuminance);
            _hidl_args.push_back((void *)&_hidl_out_minLuminance);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getHdrCapabilities", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getHdrCapabilities: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_setClientTargetSlotCount(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    uint32_t clientTargetSlotCount;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&clientTargetSlotCount);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setClientTargetSlotCount::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&clientTargetSlotCount);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setClientTargetSlotCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->setClientTargetSlotCount(display, clientTargetSlotCount);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setClientTargetSlotCount", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_setActiveConfig(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    uint32_t config;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&config);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setActiveConfig::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&config);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setActiveConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->setActiveConfig(display, config);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setActiveConfig", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_setColorMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    ::android::hardware::graphics::common::V1_0::ColorMode mode;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setColorMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setColorMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->setColorMode(display, mode);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setColorMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_setPowerMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    IComposerClient::PowerMode mode;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setPowerMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setPowerMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->setPowerMode(display, mode);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setPowerMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_setVsyncEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t display;
    IComposerClient::Vsync enabled;

    _hidl_err = _hidl_data.readUint64(&display);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&enabled);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setVsyncEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&display);
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setVsyncEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->setVsyncEnabled(display, enabled);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setVsyncEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_setInputCommandQueue(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::MQDescriptorSync<uint32_t>* descriptor;

    size_t _hidl_descriptor_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*descriptor), &_hidl_descriptor_parent,  reinterpret_cast<const void **>(&descriptor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::MQDescriptorSync<uint32_t> &>(*descriptor),
            _hidl_data,
            _hidl_descriptor_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::setInputCommandQueue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)descriptor);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setInputCommandQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    Error _hidl_out_error = static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->setInputCommandQueue(*descriptor);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    /* _hidl_err ignored! */

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "setInputCommandQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_getOutputCommandQueue(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::getOutputCommandQueue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getOutputCommandQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->getOutputCommandQueue([&](const auto &_hidl_out_error, const auto &_hidl_out_descriptor) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getOutputCommandQueue: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_descriptor_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_descriptor, sizeof(_hidl_out_descriptor), &_hidl__hidl_out_descriptor_parent);
        /* _hidl_err ignored! */

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_descriptor,
                _hidl_reply,
                _hidl__hidl_out_descriptor_parent,
                0 /* parentOffset */);

        /* _hidl_err ignored! */

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_descriptor);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "getOutputCommandQueue", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getOutputCommandQueue: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwComposerClient::_hidl_executeCommands(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComposerClient::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t inLength;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>* inHandles;

    _hidl_err = _hidl_data.readUint32(&inLength);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inHandles_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inHandles), &_hidl_inHandles_parent,  reinterpret_cast<const void **>(&inHandles));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inHandles_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(*inHandles),
            _hidl_data,
            _hidl_inHandles_parent,
            0 /* parentOffset */, &_hidl_inHandles_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < inHandles->size(); ++_hidl_index_0) {
        const native_handle_t *_hidl_inHandles_deref_indexed_ptr;
        _hidl_err = _hidl_data.readNullableEmbeddedNativeHandle(
                _hidl_inHandles_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle),
                &_hidl_inHandles_deref_indexed_ptr
                );

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComposerClient::executeCommands::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&inLength);
        _hidl_args.push_back((void *)inHandles);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.graphics.composer", "2.1", "IComposerClient", "executeCommands", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    static_cast<BnHwComposerClient*>(_hidl_this)->_hidl_mImpl->executeCommands(inLength, *inHandles, [&](const auto &_hidl_out_error, const auto &_hidl_out_outQueueChanged, const auto &_hidl_out_outLength, const auto &_hidl_out_outHandles) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("executeCommands: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeBool(_hidl_out_outQueueChanged);
        /* _hidl_err ignored! */

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_outLength);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_outHandles_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outHandles, sizeof(_hidl_out_outHandles), &_hidl__hidl_out_outHandles_parent);
        /* _hidl_err ignored! */

        size_t _hidl__hidl_out_outHandles_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outHandles,
                _hidl_reply,
                _hidl__hidl_out_outHandles_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outHandles_child);

        /* _hidl_err ignored! */

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outHandles.size(); ++_hidl_index_0) {
            _hidl_err = _hidl_reply->writeEmbeddedNativeHandle(
                    _hidl_out_outHandles[_hidl_index_0],
                    _hidl__hidl_out_outHandles_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

            /* _hidl_err ignored! */

        }

        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_outQueueChanged);
            _hidl_args.push_back((void *)&_hidl_out_outLength);
            _hidl_args.push_back((void *)&_hidl_out_outHandles);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.graphics.composer", "2.1", "IComposerClient", "executeCommands", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        _hidl_cb(*_hidl_reply);
    });

    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("executeCommands: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from IComposerClient follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwComposerClient::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwComposerClient::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwComposerClient::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* registerCallback */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_registerCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getMaxVirtualDisplayCount */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getMaxVirtualDisplayCount(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* createVirtualDisplay */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_createVirtualDisplay(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* destroyVirtualDisplay */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_destroyVirtualDisplay(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* createLayer */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_createLayer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* destroyLayer */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_destroyLayer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* getActiveConfig */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getActiveConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* getClientTargetSupport */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getClientTargetSupport(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* getColorModes */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getColorModes(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* getDisplayAttribute */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getDisplayAttribute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* getDisplayConfigs */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getDisplayConfigs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* getDisplayName */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getDisplayName(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* getDisplayType */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getDisplayType(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* getDozeSupport */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getDozeSupport(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* getHdrCapabilities */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getHdrCapabilities(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* setClientTargetSlotCount */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_setClientTargetSlotCount(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* setActiveConfig */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_setActiveConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* setColorMode */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_setColorMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* setPowerMode */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_setPowerMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* setVsyncEnabled */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_setVsyncEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* setInputCommandQueue */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_setInputCommandQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* getOutputCommandQueue */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_getOutputCommandQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* executeCommands */:
        {
            bool _hidl_is_oneway = _hidl_flags & ::android::hardware::IBinder::FLAG_ONEWAY;
            if (_hidl_is_oneway != false) {
                return ::android::UNKNOWN_ERROR;
            }

            _hidl_err = ::android::hardware::graphics::composer::V2_1::BnHwComposerClient::_hidl_executeCommands(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsComposerClient::BsComposerClient(const ::android::sp<IComposerClient> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.graphics.composer@2.1", "IComposerClient"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsComposerClient::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

// static
::android::sp<IComposerClient> IComposerClient::tryGetService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = ::android::hidl::manager::V1_0::IServiceManager::Transport;

    sp<IComposerClient> iface = nullptr;

    const sp<::android::hidl::manager::V1_0::IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IComposerClient::descriptor, serviceName);

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
                sm->get(IComposerClient::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IComposerClient: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IComposerClient: found null hwbinder interface");
            }break;
        }
        Return<sp<IComposerClient>> castRet = IComposerClient::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IComposerClient: found dead hwbinder service");
                break;
            } else {
                ALOGW("IComposerClient: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IComposerClient: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<::android::hidl::manager::V1_0::IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IComposerClient::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IComposerClient::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsComposerClient(iface);
                    }
                }
            }
        }
    }
    return iface;
}

// static
::android::sp<IComposerClient> IComposerClient::getService(const std::string &serviceName, const bool getStub) {
    using ::android::hardware::defaultServiceManager;
    using ::android::hardware::details::waitForHwService;
    using ::android::hardware::getPassthroughServiceManager;
    using ::android::hardware::Return;
    using ::android::sp;
    using Transport = ::android::hidl::manager::V1_0::IServiceManager::Transport;

    sp<IComposerClient> iface = nullptr;

    const sp<::android::hidl::manager::V1_0::IServiceManager> sm = defaultServiceManager();
    if (sm == nullptr) {
        ALOGE("getService: defaultServiceManager() is null");
        return nullptr;
    }

    Return<Transport> transportRet = sm->getTransport(IComposerClient::descriptor, serviceName);

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
            ALOGI("getService: Will do try %d for %s/%s in 1s...", tries, IComposerClient::descriptor, serviceName.c_str());
            sleep(1);
        }
        if (vintfHwbinder && tries > 0) {
            waitForHwService(IComposerClient::descriptor, serviceName);
        }
        Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                sm->get(IComposerClient::descriptor, serviceName);
        if (!ret.isOk()) {
            ALOGE("IComposerClient: defaultServiceManager()->get returns %s", ret.description().c_str());
            break;
        }
        sp<::android::hidl::base::V1_0::IBase> base = ret;
        if (base == nullptr) {
            if (tries > 0) {
                ALOGW("IComposerClient: found null hwbinder interface");
            }continue;
        }
        Return<sp<IComposerClient>> castRet = IComposerClient::castFrom(base, true /* emitError */);
        if (!castRet.isOk()) {
            if (castRet.isDeadObject()) {
                ALOGW("IComposerClient: found dead hwbinder service");
                continue;
            } else {
                ALOGW("IComposerClient: cannot call into hwbinder service: %s; No permission? Check for selinux denials.", castRet.description().c_str());
                break;
            }
        }
        iface = castRet;
        if (iface == nullptr) {
            ALOGW("IComposerClient: received incompatible service; bug in hwservicemanager?");
            break;
        }
        return iface;
    }
    if (getStub || vintfPassthru || vintfLegacy) {
        const sp<::android::hidl::manager::V1_0::IServiceManager> pm = getPassthroughServiceManager();
        if (pm != nullptr) {
            Return<sp<::android::hidl::base::V1_0::IBase>> ret = 
                    pm->get(IComposerClient::descriptor, serviceName);
            if (ret.isOk()) {
                sp<::android::hidl::base::V1_0::IBase> baseInterface = ret;
                if (baseInterface != nullptr) {
                    iface = IComposerClient::castFrom(baseInterface);
                    if (!getStub || trebleTestingOverride) {
                        iface = new BsComposerClient(iface);
                    }
                }
            }
        }
    }
    return iface;
}

::android::status_t IComposerClient::registerAsService(const std::string &serviceName) {
    ::android::hardware::details::onRegistration("android.hardware.graphics.composer@2.1", "IComposerClient", serviceName);

    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return ::android::INVALID_OPERATION;
    }
    ::android::hardware::Return<bool> ret = sm->add(serviceName.c_str(), this);
    return ret.isOk() && ret ? ::android::OK : ::android::UNKNOWN_ERROR;
}

bool IComposerClient::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.graphics.composer@2.1::IComposerClient",
                    serviceName, notification);
    return success.isOk() && success;
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
