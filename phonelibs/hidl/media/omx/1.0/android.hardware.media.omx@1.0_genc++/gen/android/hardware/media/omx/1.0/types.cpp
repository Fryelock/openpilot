#define LOG_TAG "android.hardware.media.omx@1.0::types"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hardware/media/omx/1.0/types.h>
#include <android/hardware/media/omx/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace media {
namespace omx {
namespace V1_0 {

template<>
std::string toString<Status>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & Status::OK) == static_cast<int32_t>(Status::OK)) {
        os += (first ? "" : " | ");
        os += "OK";
        first = false;
        flipped |= Status::OK;
    }
    if ((o & Status::NO_ERROR) == static_cast<int32_t>(Status::NO_ERROR)) {
        os += (first ? "" : " | ");
        os += "NO_ERROR";
        first = false;
        flipped |= Status::NO_ERROR;
    }
    if ((o & Status::NAME_NOT_FOUND) == static_cast<int32_t>(Status::NAME_NOT_FOUND)) {
        os += (first ? "" : " | ");
        os += "NAME_NOT_FOUND";
        first = false;
        flipped |= Status::NAME_NOT_FOUND;
    }
    if ((o & Status::WOULD_BLOCK) == static_cast<int32_t>(Status::WOULD_BLOCK)) {
        os += (first ? "" : " | ");
        os += "WOULD_BLOCK";
        first = false;
        flipped |= Status::WOULD_BLOCK;
    }
    if ((o & Status::NO_MEMORY) == static_cast<int32_t>(Status::NO_MEMORY)) {
        os += (first ? "" : " | ");
        os += "NO_MEMORY";
        first = false;
        flipped |= Status::NO_MEMORY;
    }
    if ((o & Status::ALREADY_EXISTS) == static_cast<int32_t>(Status::ALREADY_EXISTS)) {
        os += (first ? "" : " | ");
        os += "ALREADY_EXISTS";
        first = false;
        flipped |= Status::ALREADY_EXISTS;
    }
    if ((o & Status::NO_INIT) == static_cast<int32_t>(Status::NO_INIT)) {
        os += (first ? "" : " | ");
        os += "NO_INIT";
        first = false;
        flipped |= Status::NO_INIT;
    }
    if ((o & Status::BAD_VALUE) == static_cast<int32_t>(Status::BAD_VALUE)) {
        os += (first ? "" : " | ");
        os += "BAD_VALUE";
        first = false;
        flipped |= Status::BAD_VALUE;
    }
    if ((o & Status::DEAD_OBJECT) == static_cast<int32_t>(Status::DEAD_OBJECT)) {
        os += (first ? "" : " | ");
        os += "DEAD_OBJECT";
        first = false;
        flipped |= Status::DEAD_OBJECT;
    }
    if ((o & Status::INVALID_OPERATION) == static_cast<int32_t>(Status::INVALID_OPERATION)) {
        os += (first ? "" : " | ");
        os += "INVALID_OPERATION";
        first = false;
        flipped |= Status::INVALID_OPERATION;
    }
    if ((o & Status::TIMED_OUT) == static_cast<int32_t>(Status::TIMED_OUT)) {
        os += (first ? "" : " | ");
        os += "TIMED_OUT";
        first = false;
        flipped |= Status::TIMED_OUT;
    }
    if ((o & Status::ERROR_UNSUPPORTED) == static_cast<int32_t>(Status::ERROR_UNSUPPORTED)) {
        os += (first ? "" : " | ");
        os += "ERROR_UNSUPPORTED";
        first = false;
        flipped |= Status::ERROR_UNSUPPORTED;
    }
    if ((o & Status::UNKNOWN_ERROR) == static_cast<int32_t>(Status::UNKNOWN_ERROR)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN_ERROR";
        first = false;
        flipped |= Status::UNKNOWN_ERROR;
    }
    if ((o & Status::BUFFER_NEEDS_REALLOCATION) == static_cast<int32_t>(Status::BUFFER_NEEDS_REALLOCATION)) {
        os += (first ? "" : " | ");
        os += "BUFFER_NEEDS_REALLOCATION";
        first = false;
        flipped |= Status::BUFFER_NEEDS_REALLOCATION;
    }
    if ((o & Status::RELEASE_ALL_BUFFERS) == static_cast<int32_t>(Status::RELEASE_ALL_BUFFERS)) {
        os += (first ? "" : " | ");
        os += "RELEASE_ALL_BUFFERS";
        first = false;
        flipped |= Status::RELEASE_ALL_BUFFERS;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(Status o) {
    using ::android::hardware::details::toHexString;
    if (o == Status::OK) {
        return "OK";
    }
    if (o == Status::NO_ERROR) {
        return "NO_ERROR";
    }
    if (o == Status::NAME_NOT_FOUND) {
        return "NAME_NOT_FOUND";
    }
    if (o == Status::WOULD_BLOCK) {
        return "WOULD_BLOCK";
    }
    if (o == Status::NO_MEMORY) {
        return "NO_MEMORY";
    }
    if (o == Status::ALREADY_EXISTS) {
        return "ALREADY_EXISTS";
    }
    if (o == Status::NO_INIT) {
        return "NO_INIT";
    }
    if (o == Status::BAD_VALUE) {
        return "BAD_VALUE";
    }
    if (o == Status::DEAD_OBJECT) {
        return "DEAD_OBJECT";
    }
    if (o == Status::INVALID_OPERATION) {
        return "INVALID_OPERATION";
    }
    if (o == Status::TIMED_OUT) {
        return "TIMED_OUT";
    }
    if (o == Status::ERROR_UNSUPPORTED) {
        return "ERROR_UNSUPPORTED";
    }
    if (o == Status::UNKNOWN_ERROR) {
        return "UNKNOWN_ERROR";
    }
    if (o == Status::BUFFER_NEEDS_REALLOCATION) {
        return "BUFFER_NEEDS_REALLOCATION";
    }
    if (o == Status::RELEASE_ALL_BUFFERS) {
        return "RELEASE_ALL_BUFFERS";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<Message::Type>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    uint32_t flipped = 0;
    bool first = true;
    if ((o & Message::Type::EVENT) == static_cast<uint32_t>(Message::Type::EVENT)) {
        os += (first ? "" : " | ");
        os += "EVENT";
        first = false;
        flipped |= Message::Type::EVENT;
    }
    if ((o & Message::Type::EMPTY_BUFFER_DONE) == static_cast<uint32_t>(Message::Type::EMPTY_BUFFER_DONE)) {
        os += (first ? "" : " | ");
        os += "EMPTY_BUFFER_DONE";
        first = false;
        flipped |= Message::Type::EMPTY_BUFFER_DONE;
    }
    if ((o & Message::Type::FILL_BUFFER_DONE) == static_cast<uint32_t>(Message::Type::FILL_BUFFER_DONE)) {
        os += (first ? "" : " | ");
        os += "FILL_BUFFER_DONE";
        first = false;
        flipped |= Message::Type::FILL_BUFFER_DONE;
    }
    if ((o & Message::Type::FRAME_RENDERED) == static_cast<uint32_t>(Message::Type::FRAME_RENDERED)) {
        os += (first ? "" : " | ");
        os += "FRAME_RENDERED";
        first = false;
        flipped |= Message::Type::FRAME_RENDERED;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(Message::Type o) {
    using ::android::hardware::details::toHexString;
    if (o == Message::Type::EVENT) {
        return "EVENT";
    }
    if (o == Message::Type::EMPTY_BUFFER_DONE) {
        return "EMPTY_BUFFER_DONE";
    }
    if (o == Message::Type::FILL_BUFFER_DONE) {
        return "FILL_BUFFER_DONE";
    }
    if (o == Message::Type::FRAME_RENDERED) {
        return "FRAME_RENDERED";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

std::string toString(const Message::EventData& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".event = ";
    os += ::android::hardware::toString(o.event);
    os += ", .data1 = ";
    os += ::android::hardware::toString(o.data1);
    os += ", .data2 = ";
    os += ::android::hardware::toString(o.data2);
    os += ", .data3 = ";
    os += ::android::hardware::toString(o.data3);
    os += ", .data4 = ";
    os += ::android::hardware::toString(o.data4);
    os += "}"; return os;
}

bool operator==(const Message::EventData& lhs, const Message::EventData& rhs) {
    if (lhs.event != rhs.event) {
        return false;
    }
    if (lhs.data1 != rhs.data1) {
        return false;
    }
    if (lhs.data2 != rhs.data2) {
        return false;
    }
    if (lhs.data3 != rhs.data3) {
        return false;
    }
    if (lhs.data4 != rhs.data4) {
        return false;
    }
    return true;
}

bool operator!=(const Message::EventData& lhs,const Message::EventData& rhs){
    return !(lhs == rhs);
}

std::string toString(const Message::BufferData& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".buffer = ";
    os += ::android::hardware::toString(o.buffer);
    os += "}"; return os;
}

bool operator==(const Message::BufferData& lhs, const Message::BufferData& rhs) {
    if (lhs.buffer != rhs.buffer) {
        return false;
    }
    return true;
}

bool operator!=(const Message::BufferData& lhs,const Message::BufferData& rhs){
    return !(lhs == rhs);
}

std::string toString(const Message::ExtendedBufferData& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".buffer = ";
    os += ::android::hardware::toString(o.buffer);
    os += ", .rangeOffset = ";
    os += ::android::hardware::toString(o.rangeOffset);
    os += ", .rangeLength = ";
    os += ::android::hardware::toString(o.rangeLength);
    os += ", .flags = ";
    os += ::android::hardware::toString(o.flags);
    os += ", .timestampUs = ";
    os += ::android::hardware::toString(o.timestampUs);
    os += "}"; return os;
}

bool operator==(const Message::ExtendedBufferData& lhs, const Message::ExtendedBufferData& rhs) {
    if (lhs.buffer != rhs.buffer) {
        return false;
    }
    if (lhs.rangeOffset != rhs.rangeOffset) {
        return false;
    }
    if (lhs.rangeLength != rhs.rangeLength) {
        return false;
    }
    if (lhs.flags != rhs.flags) {
        return false;
    }
    if (lhs.timestampUs != rhs.timestampUs) {
        return false;
    }
    return true;
}

bool operator!=(const Message::ExtendedBufferData& lhs,const Message::ExtendedBufferData& rhs){
    return !(lhs == rhs);
}

std::string toString(const Message::RenderData& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".timestampUs = ";
    os += ::android::hardware::toString(o.timestampUs);
    os += ", .systemTimeNs = ";
    os += ::android::hardware::toString(o.systemTimeNs);
    os += "}"; return os;
}

bool operator==(const Message::RenderData& lhs, const Message::RenderData& rhs) {
    if (lhs.timestampUs != rhs.timestampUs) {
        return false;
    }
    if (lhs.systemTimeNs != rhs.systemTimeNs) {
        return false;
    }
    return true;
}

bool operator!=(const Message::RenderData& lhs,const Message::RenderData& rhs){
    return !(lhs == rhs);
}

std::string toString(const Message::Data& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".eventData = ";
    os += toString(o.eventData);
    os += ", .bufferData = ";
    os += toString(o.bufferData);
    os += ", .extendedBufferData = ";
    os += toString(o.extendedBufferData);
    os += ", .renderData = ";
    os += toString(o.renderData);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Data
::android::status_t readEmbeddedFromParcel(
        const Message &/* obj */,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    const native_handle_t *_hidl_fence_ptr;
    _hidl_err = parcel.readNullableEmbeddedNativeHandle(
            parentHandle,
            parentOffset + offsetof(Message, fence),
            &_hidl_fence_ptr
            );

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Message &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = parcel->writeEmbeddedNativeHandle(
            obj.fence,
            parentHandle,
            parentOffset + offsetof(Message, fence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

std::string toString(const Message& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".type = ";
    os += toString(o.type);
    os += ", .fence = ";
    os += ::android::hardware::toString(o.fence);
    os += ", .data = ";
    os += toString(o.data);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Message
template<>
std::string toString<CodecBuffer::Type>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & CodecBuffer::Type::INVALID) == static_cast<int32_t>(CodecBuffer::Type::INVALID)) {
        os += (first ? "" : " | ");
        os += "INVALID";
        first = false;
        flipped |= CodecBuffer::Type::INVALID;
    }
    if ((o & CodecBuffer::Type::PRESET) == static_cast<int32_t>(CodecBuffer::Type::PRESET)) {
        os += (first ? "" : " | ");
        os += "PRESET";
        first = false;
        flipped |= CodecBuffer::Type::PRESET;
    }
    if ((o & CodecBuffer::Type::SHARED_MEM) == static_cast<int32_t>(CodecBuffer::Type::SHARED_MEM)) {
        os += (first ? "" : " | ");
        os += "SHARED_MEM";
        first = false;
        flipped |= CodecBuffer::Type::SHARED_MEM;
    }
    if ((o & CodecBuffer::Type::ANW_BUFFER) == static_cast<int32_t>(CodecBuffer::Type::ANW_BUFFER)) {
        os += (first ? "" : " | ");
        os += "ANW_BUFFER";
        first = false;
        flipped |= CodecBuffer::Type::ANW_BUFFER;
    }
    if ((o & CodecBuffer::Type::NATIVE_HANDLE) == static_cast<int32_t>(CodecBuffer::Type::NATIVE_HANDLE)) {
        os += (first ? "" : " | ");
        os += "NATIVE_HANDLE";
        first = false;
        flipped |= CodecBuffer::Type::NATIVE_HANDLE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(CodecBuffer::Type o) {
    using ::android::hardware::details::toHexString;
    if (o == CodecBuffer::Type::INVALID) {
        return "INVALID";
    }
    if (o == CodecBuffer::Type::PRESET) {
        return "PRESET";
    }
    if (o == CodecBuffer::Type::SHARED_MEM) {
        return "SHARED_MEM";
    }
    if (o == CodecBuffer::Type::ANW_BUFFER) {
        return "ANW_BUFFER";
    }
    if (o == CodecBuffer::Type::NATIVE_HANDLE) {
        return "NATIVE_HANDLE";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

std::string toString(const CodecBuffer::PresetAttributes& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".rangeOffset = ";
    os += ::android::hardware::toString(o.rangeOffset);
    os += ", .rangeLength = ";
    os += ::android::hardware::toString(o.rangeLength);
    os += "}"; return os;
}

bool operator==(const CodecBuffer::PresetAttributes& lhs, const CodecBuffer::PresetAttributes& rhs) {
    if (lhs.rangeOffset != rhs.rangeOffset) {
        return false;
    }
    if (lhs.rangeLength != rhs.rangeLength) {
        return false;
    }
    return true;
}

bool operator!=(const CodecBuffer::PresetAttributes& lhs,const CodecBuffer::PresetAttributes& rhs){
    return !(lhs == rhs);
}

std::string toString(const CodecBuffer::Attributes& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".preset = ";
    os += toString(o.preset);
    os += ", .anwBuffer = ";
    os += ::android::hardware::media::V1_0::toString(o.anwBuffer);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Attributes
::android::status_t readEmbeddedFromParcel(
        const CodecBuffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    const native_handle_t *_hidl_nativeHandle_ptr;
    _hidl_err = parcel.readNullableEmbeddedNativeHandle(
            parentHandle,
            parentOffset + offsetof(CodecBuffer, nativeHandle),
            &_hidl_nativeHandle_ptr
            );

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_memory &>(obj.sharedMemory),
            parcel,
            parentHandle,
            parentOffset + offsetof(CodecBuffer, sharedMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CodecBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = parcel->writeEmbeddedNativeHandle(
            obj.nativeHandle,
            parentHandle,
            parentOffset + offsetof(CodecBuffer, nativeHandle));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sharedMemory,
            parcel,
            parentHandle,
            parentOffset + offsetof(CodecBuffer, sharedMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

std::string toString(const CodecBuffer& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".type = ";
    os += toString(o.type);
    os += ", .attr = ";
    os += toString(o.attr);
    os += ", .nativeHandle = ";
    os += ::android::hardware::toString(o.nativeHandle);
    os += ", .sharedMemory = ";
    os += ::android::hardware::toString(o.sharedMemory);
    os += "}"; return os;
}

// operator== and operator!= are not generated for CodecBuffer
template<>
std::string toString<PortMode>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & PortMode::PRESET_START) == static_cast<int32_t>(PortMode::PRESET_START)) {
        os += (first ? "" : " | ");
        os += "PRESET_START";
        first = false;
        flipped |= PortMode::PRESET_START;
    }
    if ((o & PortMode::PRESET_BYTE_BUFFER) == static_cast<int32_t>(PortMode::PRESET_BYTE_BUFFER)) {
        os += (first ? "" : " | ");
        os += "PRESET_BYTE_BUFFER";
        first = false;
        flipped |= PortMode::PRESET_BYTE_BUFFER;
    }
    if ((o & PortMode::PRESET_ANW_BUFFER) == static_cast<int32_t>(PortMode::PRESET_ANW_BUFFER)) {
        os += (first ? "" : " | ");
        os += "PRESET_ANW_BUFFER";
        first = false;
        flipped |= PortMode::PRESET_ANW_BUFFER;
    }
    if ((o & PortMode::PRESET_SECURE_BUFFER) == static_cast<int32_t>(PortMode::PRESET_SECURE_BUFFER)) {
        os += (first ? "" : " | ");
        os += "PRESET_SECURE_BUFFER";
        first = false;
        flipped |= PortMode::PRESET_SECURE_BUFFER;
    }
    if ((o & PortMode::PRESET_END) == static_cast<int32_t>(PortMode::PRESET_END)) {
        os += (first ? "" : " | ");
        os += "PRESET_END";
        first = false;
        flipped |= PortMode::PRESET_END;
    }
    if ((o & PortMode::DYNAMIC_START) == static_cast<int32_t>(PortMode::DYNAMIC_START)) {
        os += (first ? "" : " | ");
        os += "DYNAMIC_START";
        first = false;
        flipped |= PortMode::DYNAMIC_START;
    }
    if ((o & PortMode::DYNAMIC_ANW_BUFFER) == static_cast<int32_t>(PortMode::DYNAMIC_ANW_BUFFER)) {
        os += (first ? "" : " | ");
        os += "DYNAMIC_ANW_BUFFER";
        first = false;
        flipped |= PortMode::DYNAMIC_ANW_BUFFER;
    }
    if ((o & PortMode::DYNAMIC_NATIVE_HANDLE) == static_cast<int32_t>(PortMode::DYNAMIC_NATIVE_HANDLE)) {
        os += (first ? "" : " | ");
        os += "DYNAMIC_NATIVE_HANDLE";
        first = false;
        flipped |= PortMode::DYNAMIC_NATIVE_HANDLE;
    }
    if ((o & PortMode::DYNAMIC_END) == static_cast<int32_t>(PortMode::DYNAMIC_END)) {
        os += (first ? "" : " | ");
        os += "DYNAMIC_END";
        first = false;
        flipped |= PortMode::DYNAMIC_END;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(PortMode o) {
    using ::android::hardware::details::toHexString;
    if (o == PortMode::PRESET_START) {
        return "PRESET_START";
    }
    if (o == PortMode::PRESET_BYTE_BUFFER) {
        return "PRESET_BYTE_BUFFER";
    }
    if (o == PortMode::PRESET_ANW_BUFFER) {
        return "PRESET_ANW_BUFFER";
    }
    if (o == PortMode::PRESET_SECURE_BUFFER) {
        return "PRESET_SECURE_BUFFER";
    }
    if (o == PortMode::PRESET_END) {
        return "PRESET_END";
    }
    if (o == PortMode::DYNAMIC_START) {
        return "DYNAMIC_START";
    }
    if (o == PortMode::DYNAMIC_ANW_BUFFER) {
        return "DYNAMIC_ANW_BUFFER";
    }
    if (o == PortMode::DYNAMIC_NATIVE_HANDLE) {
        return "DYNAMIC_NATIVE_HANDLE";
    }
    if (o == PortMode::DYNAMIC_END) {
        return "DYNAMIC_END";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<ColorAspects::Range>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    uint32_t flipped = 0;
    bool first = true;
    if ((o & ColorAspects::Range::UNSPECIFIED) == static_cast<uint32_t>(ColorAspects::Range::UNSPECIFIED)) {
        os += (first ? "" : " | ");
        os += "UNSPECIFIED";
        first = false;
        flipped |= ColorAspects::Range::UNSPECIFIED;
    }
    if ((o & ColorAspects::Range::FULL) == static_cast<uint32_t>(ColorAspects::Range::FULL)) {
        os += (first ? "" : " | ");
        os += "FULL";
        first = false;
        flipped |= ColorAspects::Range::FULL;
    }
    if ((o & ColorAspects::Range::LIMITED) == static_cast<uint32_t>(ColorAspects::Range::LIMITED)) {
        os += (first ? "" : " | ");
        os += "LIMITED";
        first = false;
        flipped |= ColorAspects::Range::LIMITED;
    }
    if ((o & ColorAspects::Range::OTHER) == static_cast<uint32_t>(ColorAspects::Range::OTHER)) {
        os += (first ? "" : " | ");
        os += "OTHER";
        first = false;
        flipped |= ColorAspects::Range::OTHER;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(ColorAspects::Range o) {
    using ::android::hardware::details::toHexString;
    if (o == ColorAspects::Range::UNSPECIFIED) {
        return "UNSPECIFIED";
    }
    if (o == ColorAspects::Range::FULL) {
        return "FULL";
    }
    if (o == ColorAspects::Range::LIMITED) {
        return "LIMITED";
    }
    if (o == ColorAspects::Range::OTHER) {
        return "OTHER";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
std::string toString<ColorAspects::Primaries>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    uint32_t flipped = 0;
    bool first = true;
    if ((o & ColorAspects::Primaries::UNSPECIFIED) == static_cast<uint32_t>(ColorAspects::Primaries::UNSPECIFIED)) {
        os += (first ? "" : " | ");
        os += "UNSPECIFIED";
        first = false;
        flipped |= ColorAspects::Primaries::UNSPECIFIED;
    }
    if ((o & ColorAspects::Primaries::BT709_5) == static_cast<uint32_t>(ColorAspects::Primaries::BT709_5)) {
        os += (first ? "" : " | ");
        os += "BT709_5";
        first = false;
        flipped |= ColorAspects::Primaries::BT709_5;
    }
    if ((o & ColorAspects::Primaries::BT470_6M) == static_cast<uint32_t>(ColorAspects::Primaries::BT470_6M)) {
        os += (first ? "" : " | ");
        os += "BT470_6M";
        first = false;
        flipped |= ColorAspects::Primaries::BT470_6M;
    }
    if ((o & ColorAspects::Primaries::BT601_6_625) == static_cast<uint32_t>(ColorAspects::Primaries::BT601_6_625)) {
        os += (first ? "" : " | ");
        os += "BT601_6_625";
        first = false;
        flipped |= ColorAspects::Primaries::BT601_6_625;
    }
    if ((o & ColorAspects::Primaries::BT601_6_525) == static_cast<uint32_t>(ColorAspects::Primaries::BT601_6_525)) {
        os += (first ? "" : " | ");
        os += "BT601_6_525";
        first = false;
        flipped |= ColorAspects::Primaries::BT601_6_525;
    }
    if ((o & ColorAspects::Primaries::GENERIC_FILM) == static_cast<uint32_t>(ColorAspects::Primaries::GENERIC_FILM)) {
        os += (first ? "" : " | ");
        os += "GENERIC_FILM";
        first = false;
        flipped |= ColorAspects::Primaries::GENERIC_FILM;
    }
    if ((o & ColorAspects::Primaries::BT2020) == static_cast<uint32_t>(ColorAspects::Primaries::BT2020)) {
        os += (first ? "" : " | ");
        os += "BT2020";
        first = false;
        flipped |= ColorAspects::Primaries::BT2020;
    }
    if ((o & ColorAspects::Primaries::OTHER) == static_cast<uint32_t>(ColorAspects::Primaries::OTHER)) {
        os += (first ? "" : " | ");
        os += "OTHER";
        first = false;
        flipped |= ColorAspects::Primaries::OTHER;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(ColorAspects::Primaries o) {
    using ::android::hardware::details::toHexString;
    if (o == ColorAspects::Primaries::UNSPECIFIED) {
        return "UNSPECIFIED";
    }
    if (o == ColorAspects::Primaries::BT709_5) {
        return "BT709_5";
    }
    if (o == ColorAspects::Primaries::BT470_6M) {
        return "BT470_6M";
    }
    if (o == ColorAspects::Primaries::BT601_6_625) {
        return "BT601_6_625";
    }
    if (o == ColorAspects::Primaries::BT601_6_525) {
        return "BT601_6_525";
    }
    if (o == ColorAspects::Primaries::GENERIC_FILM) {
        return "GENERIC_FILM";
    }
    if (o == ColorAspects::Primaries::BT2020) {
        return "BT2020";
    }
    if (o == ColorAspects::Primaries::OTHER) {
        return "OTHER";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
std::string toString<ColorAspects::Transfer>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    uint32_t flipped = 0;
    bool first = true;
    if ((o & ColorAspects::Transfer::UNSPECIFIED) == static_cast<uint32_t>(ColorAspects::Transfer::UNSPECIFIED)) {
        os += (first ? "" : " | ");
        os += "UNSPECIFIED";
        first = false;
        flipped |= ColorAspects::Transfer::UNSPECIFIED;
    }
    if ((o & ColorAspects::Transfer::LINEAR) == static_cast<uint32_t>(ColorAspects::Transfer::LINEAR)) {
        os += (first ? "" : " | ");
        os += "LINEAR";
        first = false;
        flipped |= ColorAspects::Transfer::LINEAR;
    }
    if ((o & ColorAspects::Transfer::SRGB) == static_cast<uint32_t>(ColorAspects::Transfer::SRGB)) {
        os += (first ? "" : " | ");
        os += "SRGB";
        first = false;
        flipped |= ColorAspects::Transfer::SRGB;
    }
    if ((o & ColorAspects::Transfer::SMPTE170M) == static_cast<uint32_t>(ColorAspects::Transfer::SMPTE170M)) {
        os += (first ? "" : " | ");
        os += "SMPTE170M";
        first = false;
        flipped |= ColorAspects::Transfer::SMPTE170M;
    }
    if ((o & ColorAspects::Transfer::GAMMA22) == static_cast<uint32_t>(ColorAspects::Transfer::GAMMA22)) {
        os += (first ? "" : " | ");
        os += "GAMMA22";
        first = false;
        flipped |= ColorAspects::Transfer::GAMMA22;
    }
    if ((o & ColorAspects::Transfer::GAMMA28) == static_cast<uint32_t>(ColorAspects::Transfer::GAMMA28)) {
        os += (first ? "" : " | ");
        os += "GAMMA28";
        first = false;
        flipped |= ColorAspects::Transfer::GAMMA28;
    }
    if ((o & ColorAspects::Transfer::ST2084) == static_cast<uint32_t>(ColorAspects::Transfer::ST2084)) {
        os += (first ? "" : " | ");
        os += "ST2084";
        first = false;
        flipped |= ColorAspects::Transfer::ST2084;
    }
    if ((o & ColorAspects::Transfer::HLG) == static_cast<uint32_t>(ColorAspects::Transfer::HLG)) {
        os += (first ? "" : " | ");
        os += "HLG";
        first = false;
        flipped |= ColorAspects::Transfer::HLG;
    }
    if ((o & ColorAspects::Transfer::SMPTE240M) == static_cast<uint32_t>(ColorAspects::Transfer::SMPTE240M)) {
        os += (first ? "" : " | ");
        os += "SMPTE240M";
        first = false;
        flipped |= ColorAspects::Transfer::SMPTE240M;
    }
    if ((o & ColorAspects::Transfer::XVYCC) == static_cast<uint32_t>(ColorAspects::Transfer::XVYCC)) {
        os += (first ? "" : " | ");
        os += "XVYCC";
        first = false;
        flipped |= ColorAspects::Transfer::XVYCC;
    }
    if ((o & ColorAspects::Transfer::BT1361) == static_cast<uint32_t>(ColorAspects::Transfer::BT1361)) {
        os += (first ? "" : " | ");
        os += "BT1361";
        first = false;
        flipped |= ColorAspects::Transfer::BT1361;
    }
    if ((o & ColorAspects::Transfer::ST428) == static_cast<uint32_t>(ColorAspects::Transfer::ST428)) {
        os += (first ? "" : " | ");
        os += "ST428";
        first = false;
        flipped |= ColorAspects::Transfer::ST428;
    }
    if ((o & ColorAspects::Transfer::OTHER) == static_cast<uint32_t>(ColorAspects::Transfer::OTHER)) {
        os += (first ? "" : " | ");
        os += "OTHER";
        first = false;
        flipped |= ColorAspects::Transfer::OTHER;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(ColorAspects::Transfer o) {
    using ::android::hardware::details::toHexString;
    if (o == ColorAspects::Transfer::UNSPECIFIED) {
        return "UNSPECIFIED";
    }
    if (o == ColorAspects::Transfer::LINEAR) {
        return "LINEAR";
    }
    if (o == ColorAspects::Transfer::SRGB) {
        return "SRGB";
    }
    if (o == ColorAspects::Transfer::SMPTE170M) {
        return "SMPTE170M";
    }
    if (o == ColorAspects::Transfer::GAMMA22) {
        return "GAMMA22";
    }
    if (o == ColorAspects::Transfer::GAMMA28) {
        return "GAMMA28";
    }
    if (o == ColorAspects::Transfer::ST2084) {
        return "ST2084";
    }
    if (o == ColorAspects::Transfer::HLG) {
        return "HLG";
    }
    if (o == ColorAspects::Transfer::SMPTE240M) {
        return "SMPTE240M";
    }
    if (o == ColorAspects::Transfer::XVYCC) {
        return "XVYCC";
    }
    if (o == ColorAspects::Transfer::BT1361) {
        return "BT1361";
    }
    if (o == ColorAspects::Transfer::ST428) {
        return "ST428";
    }
    if (o == ColorAspects::Transfer::OTHER) {
        return "OTHER";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
std::string toString<ColorAspects::MatrixCoeffs>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    uint32_t flipped = 0;
    bool first = true;
    if ((o & ColorAspects::MatrixCoeffs::UNSPECIFIED) == static_cast<uint32_t>(ColorAspects::MatrixCoeffs::UNSPECIFIED)) {
        os += (first ? "" : " | ");
        os += "UNSPECIFIED";
        first = false;
        flipped |= ColorAspects::MatrixCoeffs::UNSPECIFIED;
    }
    if ((o & ColorAspects::MatrixCoeffs::BT709_5) == static_cast<uint32_t>(ColorAspects::MatrixCoeffs::BT709_5)) {
        os += (first ? "" : " | ");
        os += "BT709_5";
        first = false;
        flipped |= ColorAspects::MatrixCoeffs::BT709_5;
    }
    if ((o & ColorAspects::MatrixCoeffs::BT470_6M) == static_cast<uint32_t>(ColorAspects::MatrixCoeffs::BT470_6M)) {
        os += (first ? "" : " | ");
        os += "BT470_6M";
        first = false;
        flipped |= ColorAspects::MatrixCoeffs::BT470_6M;
    }
    if ((o & ColorAspects::MatrixCoeffs::BT601_6) == static_cast<uint32_t>(ColorAspects::MatrixCoeffs::BT601_6)) {
        os += (first ? "" : " | ");
        os += "BT601_6";
        first = false;
        flipped |= ColorAspects::MatrixCoeffs::BT601_6;
    }
    if ((o & ColorAspects::MatrixCoeffs::SMPTE240M) == static_cast<uint32_t>(ColorAspects::MatrixCoeffs::SMPTE240M)) {
        os += (first ? "" : " | ");
        os += "SMPTE240M";
        first = false;
        flipped |= ColorAspects::MatrixCoeffs::SMPTE240M;
    }
    if ((o & ColorAspects::MatrixCoeffs::BT2020) == static_cast<uint32_t>(ColorAspects::MatrixCoeffs::BT2020)) {
        os += (first ? "" : " | ");
        os += "BT2020";
        first = false;
        flipped |= ColorAspects::MatrixCoeffs::BT2020;
    }
    if ((o & ColorAspects::MatrixCoeffs::BT2020CONSTANT) == static_cast<uint32_t>(ColorAspects::MatrixCoeffs::BT2020CONSTANT)) {
        os += (first ? "" : " | ");
        os += "BT2020CONSTANT";
        first = false;
        flipped |= ColorAspects::MatrixCoeffs::BT2020CONSTANT;
    }
    if ((o & ColorAspects::MatrixCoeffs::OTHER) == static_cast<uint32_t>(ColorAspects::MatrixCoeffs::OTHER)) {
        os += (first ? "" : " | ");
        os += "OTHER";
        first = false;
        flipped |= ColorAspects::MatrixCoeffs::OTHER;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(ColorAspects::MatrixCoeffs o) {
    using ::android::hardware::details::toHexString;
    if (o == ColorAspects::MatrixCoeffs::UNSPECIFIED) {
        return "UNSPECIFIED";
    }
    if (o == ColorAspects::MatrixCoeffs::BT709_5) {
        return "BT709_5";
    }
    if (o == ColorAspects::MatrixCoeffs::BT470_6M) {
        return "BT470_6M";
    }
    if (o == ColorAspects::MatrixCoeffs::BT601_6) {
        return "BT601_6";
    }
    if (o == ColorAspects::MatrixCoeffs::SMPTE240M) {
        return "SMPTE240M";
    }
    if (o == ColorAspects::MatrixCoeffs::BT2020) {
        return "BT2020";
    }
    if (o == ColorAspects::MatrixCoeffs::BT2020CONSTANT) {
        return "BT2020CONSTANT";
    }
    if (o == ColorAspects::MatrixCoeffs::OTHER) {
        return "OTHER";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

std::string toString(const ColorAspects& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".range = ";
    os += toString(o.range);
    os += ", .primaries = ";
    os += toString(o.primaries);
    os += ", .transfer = ";
    os += toString(o.transfer);
    os += ", .matrixCoeffs = ";
    os += toString(o.matrixCoeffs);
    os += "}"; return os;
}

bool operator==(const ColorAspects& lhs, const ColorAspects& rhs) {
    if (lhs.range != rhs.range) {
        return false;
    }
    if (lhs.primaries != rhs.primaries) {
        return false;
    }
    if (lhs.transfer != rhs.transfer) {
        return false;
    }
    if (lhs.matrixCoeffs != rhs.matrixCoeffs) {
        return false;
    }
    return true;
}

bool operator!=(const ColorAspects& lhs,const ColorAspects& rhs){
    return !(lhs == rhs);
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
