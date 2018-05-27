#define LOG_TAG "android.hardware.graphics.common@1.0::types"

#include <android/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <android/hardware/graphics/common/1.0/types.h>
#include <android/hardware/graphics/common/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace graphics {
namespace common {
namespace V1_0 {

template<>
std::string toString<PixelFormat>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & PixelFormat::RGBA_8888) == static_cast<int32_t>(PixelFormat::RGBA_8888)) {
        os += (first ? "" : " | ");
        os += "RGBA_8888";
        first = false;
        flipped |= PixelFormat::RGBA_8888;
    }
    if ((o & PixelFormat::RGBX_8888) == static_cast<int32_t>(PixelFormat::RGBX_8888)) {
        os += (first ? "" : " | ");
        os += "RGBX_8888";
        first = false;
        flipped |= PixelFormat::RGBX_8888;
    }
    if ((o & PixelFormat::RGB_888) == static_cast<int32_t>(PixelFormat::RGB_888)) {
        os += (first ? "" : " | ");
        os += "RGB_888";
        first = false;
        flipped |= PixelFormat::RGB_888;
    }
    if ((o & PixelFormat::RGB_565) == static_cast<int32_t>(PixelFormat::RGB_565)) {
        os += (first ? "" : " | ");
        os += "RGB_565";
        first = false;
        flipped |= PixelFormat::RGB_565;
    }
    if ((o & PixelFormat::BGRA_8888) == static_cast<int32_t>(PixelFormat::BGRA_8888)) {
        os += (first ? "" : " | ");
        os += "BGRA_8888";
        first = false;
        flipped |= PixelFormat::BGRA_8888;
    }
    if ((o & PixelFormat::YCBCR_422_SP) == static_cast<int32_t>(PixelFormat::YCBCR_422_SP)) {
        os += (first ? "" : " | ");
        os += "YCBCR_422_SP";
        first = false;
        flipped |= PixelFormat::YCBCR_422_SP;
    }
    if ((o & PixelFormat::YCRCB_420_SP) == static_cast<int32_t>(PixelFormat::YCRCB_420_SP)) {
        os += (first ? "" : " | ");
        os += "YCRCB_420_SP";
        first = false;
        flipped |= PixelFormat::YCRCB_420_SP;
    }
    if ((o & PixelFormat::YCBCR_422_I) == static_cast<int32_t>(PixelFormat::YCBCR_422_I)) {
        os += (first ? "" : " | ");
        os += "YCBCR_422_I";
        first = false;
        flipped |= PixelFormat::YCBCR_422_I;
    }
    if ((o & PixelFormat::RGBA_FP16) == static_cast<int32_t>(PixelFormat::RGBA_FP16)) {
        os += (first ? "" : " | ");
        os += "RGBA_FP16";
        first = false;
        flipped |= PixelFormat::RGBA_FP16;
    }
    if ((o & PixelFormat::RAW16) == static_cast<int32_t>(PixelFormat::RAW16)) {
        os += (first ? "" : " | ");
        os += "RAW16";
        first = false;
        flipped |= PixelFormat::RAW16;
    }
    if ((o & PixelFormat::BLOB) == static_cast<int32_t>(PixelFormat::BLOB)) {
        os += (first ? "" : " | ");
        os += "BLOB";
        first = false;
        flipped |= PixelFormat::BLOB;
    }
    if ((o & PixelFormat::IMPLEMENTATION_DEFINED) == static_cast<int32_t>(PixelFormat::IMPLEMENTATION_DEFINED)) {
        os += (first ? "" : " | ");
        os += "IMPLEMENTATION_DEFINED";
        first = false;
        flipped |= PixelFormat::IMPLEMENTATION_DEFINED;
    }
    if ((o & PixelFormat::YCBCR_420_888) == static_cast<int32_t>(PixelFormat::YCBCR_420_888)) {
        os += (first ? "" : " | ");
        os += "YCBCR_420_888";
        first = false;
        flipped |= PixelFormat::YCBCR_420_888;
    }
    if ((o & PixelFormat::RAW_OPAQUE) == static_cast<int32_t>(PixelFormat::RAW_OPAQUE)) {
        os += (first ? "" : " | ");
        os += "RAW_OPAQUE";
        first = false;
        flipped |= PixelFormat::RAW_OPAQUE;
    }
    if ((o & PixelFormat::RAW10) == static_cast<int32_t>(PixelFormat::RAW10)) {
        os += (first ? "" : " | ");
        os += "RAW10";
        first = false;
        flipped |= PixelFormat::RAW10;
    }
    if ((o & PixelFormat::RAW12) == static_cast<int32_t>(PixelFormat::RAW12)) {
        os += (first ? "" : " | ");
        os += "RAW12";
        first = false;
        flipped |= PixelFormat::RAW12;
    }
    if ((o & PixelFormat::RGBA_1010102) == static_cast<int32_t>(PixelFormat::RGBA_1010102)) {
        os += (first ? "" : " | ");
        os += "RGBA_1010102";
        first = false;
        flipped |= PixelFormat::RGBA_1010102;
    }
    if ((o & PixelFormat::Y8) == static_cast<int32_t>(PixelFormat::Y8)) {
        os += (first ? "" : " | ");
        os += "Y8";
        first = false;
        flipped |= PixelFormat::Y8;
    }
    if ((o & PixelFormat::Y16) == static_cast<int32_t>(PixelFormat::Y16)) {
        os += (first ? "" : " | ");
        os += "Y16";
        first = false;
        flipped |= PixelFormat::Y16;
    }
    if ((o & PixelFormat::YV12) == static_cast<int32_t>(PixelFormat::YV12)) {
        os += (first ? "" : " | ");
        os += "YV12";
        first = false;
        flipped |= PixelFormat::YV12;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(PixelFormat o) {
    using ::android::hardware::details::toHexString;
    if (o == PixelFormat::RGBA_8888) {
        return "RGBA_8888";
    }
    if (o == PixelFormat::RGBX_8888) {
        return "RGBX_8888";
    }
    if (o == PixelFormat::RGB_888) {
        return "RGB_888";
    }
    if (o == PixelFormat::RGB_565) {
        return "RGB_565";
    }
    if (o == PixelFormat::BGRA_8888) {
        return "BGRA_8888";
    }
    if (o == PixelFormat::YCBCR_422_SP) {
        return "YCBCR_422_SP";
    }
    if (o == PixelFormat::YCRCB_420_SP) {
        return "YCRCB_420_SP";
    }
    if (o == PixelFormat::YCBCR_422_I) {
        return "YCBCR_422_I";
    }
    if (o == PixelFormat::RGBA_FP16) {
        return "RGBA_FP16";
    }
    if (o == PixelFormat::RAW16) {
        return "RAW16";
    }
    if (o == PixelFormat::BLOB) {
        return "BLOB";
    }
    if (o == PixelFormat::IMPLEMENTATION_DEFINED) {
        return "IMPLEMENTATION_DEFINED";
    }
    if (o == PixelFormat::YCBCR_420_888) {
        return "YCBCR_420_888";
    }
    if (o == PixelFormat::RAW_OPAQUE) {
        return "RAW_OPAQUE";
    }
    if (o == PixelFormat::RAW10) {
        return "RAW10";
    }
    if (o == PixelFormat::RAW12) {
        return "RAW12";
    }
    if (o == PixelFormat::RGBA_1010102) {
        return "RGBA_1010102";
    }
    if (o == PixelFormat::Y8) {
        return "Y8";
    }
    if (o == PixelFormat::Y16) {
        return "Y16";
    }
    if (o == PixelFormat::YV12) {
        return "YV12";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<BufferUsage>(uint64_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    uint64_t flipped = 0;
    bool first = true;
    if ((o & BufferUsage::CPU_READ_MASK) == static_cast<uint64_t>(BufferUsage::CPU_READ_MASK)) {
        os += (first ? "" : " | ");
        os += "CPU_READ_MASK";
        first = false;
        flipped |= BufferUsage::CPU_READ_MASK;
    }
    if ((o & BufferUsage::CPU_READ_NEVER) == static_cast<uint64_t>(BufferUsage::CPU_READ_NEVER)) {
        os += (first ? "" : " | ");
        os += "CPU_READ_NEVER";
        first = false;
        flipped |= BufferUsage::CPU_READ_NEVER;
    }
    if ((o & BufferUsage::CPU_READ_RARELY) == static_cast<uint64_t>(BufferUsage::CPU_READ_RARELY)) {
        os += (first ? "" : " | ");
        os += "CPU_READ_RARELY";
        first = false;
        flipped |= BufferUsage::CPU_READ_RARELY;
    }
    if ((o & BufferUsage::CPU_READ_OFTEN) == static_cast<uint64_t>(BufferUsage::CPU_READ_OFTEN)) {
        os += (first ? "" : " | ");
        os += "CPU_READ_OFTEN";
        first = false;
        flipped |= BufferUsage::CPU_READ_OFTEN;
    }
    if ((o & BufferUsage::CPU_WRITE_MASK) == static_cast<uint64_t>(BufferUsage::CPU_WRITE_MASK)) {
        os += (first ? "" : " | ");
        os += "CPU_WRITE_MASK";
        first = false;
        flipped |= BufferUsage::CPU_WRITE_MASK;
    }
    if ((o & BufferUsage::CPU_WRITE_NEVER) == static_cast<uint64_t>(BufferUsage::CPU_WRITE_NEVER)) {
        os += (first ? "" : " | ");
        os += "CPU_WRITE_NEVER";
        first = false;
        flipped |= BufferUsage::CPU_WRITE_NEVER;
    }
    if ((o & BufferUsage::CPU_WRITE_RARELY) == static_cast<uint64_t>(BufferUsage::CPU_WRITE_RARELY)) {
        os += (first ? "" : " | ");
        os += "CPU_WRITE_RARELY";
        first = false;
        flipped |= BufferUsage::CPU_WRITE_RARELY;
    }
    if ((o & BufferUsage::CPU_WRITE_OFTEN) == static_cast<uint64_t>(BufferUsage::CPU_WRITE_OFTEN)) {
        os += (first ? "" : " | ");
        os += "CPU_WRITE_OFTEN";
        first = false;
        flipped |= BufferUsage::CPU_WRITE_OFTEN;
    }
    if ((o & BufferUsage::GPU_TEXTURE) == static_cast<uint64_t>(BufferUsage::GPU_TEXTURE)) {
        os += (first ? "" : " | ");
        os += "GPU_TEXTURE";
        first = false;
        flipped |= BufferUsage::GPU_TEXTURE;
    }
    if ((o & BufferUsage::GPU_RENDER_TARGET) == static_cast<uint64_t>(BufferUsage::GPU_RENDER_TARGET)) {
        os += (first ? "" : " | ");
        os += "GPU_RENDER_TARGET";
        first = false;
        flipped |= BufferUsage::GPU_RENDER_TARGET;
    }
    if ((o & BufferUsage::COMPOSER_OVERLAY) == static_cast<uint64_t>(BufferUsage::COMPOSER_OVERLAY)) {
        os += (first ? "" : " | ");
        os += "COMPOSER_OVERLAY";
        first = false;
        flipped |= BufferUsage::COMPOSER_OVERLAY;
    }
    if ((o & BufferUsage::COMPOSER_CLIENT_TARGET) == static_cast<uint64_t>(BufferUsage::COMPOSER_CLIENT_TARGET)) {
        os += (first ? "" : " | ");
        os += "COMPOSER_CLIENT_TARGET";
        first = false;
        flipped |= BufferUsage::COMPOSER_CLIENT_TARGET;
    }
    if ((o & BufferUsage::PROTECTED) == static_cast<uint64_t>(BufferUsage::PROTECTED)) {
        os += (first ? "" : " | ");
        os += "PROTECTED";
        first = false;
        flipped |= BufferUsage::PROTECTED;
    }
    if ((o & BufferUsage::COMPOSER_CURSOR) == static_cast<uint64_t>(BufferUsage::COMPOSER_CURSOR)) {
        os += (first ? "" : " | ");
        os += "COMPOSER_CURSOR";
        first = false;
        flipped |= BufferUsage::COMPOSER_CURSOR;
    }
    if ((o & BufferUsage::VIDEO_ENCODER) == static_cast<uint64_t>(BufferUsage::VIDEO_ENCODER)) {
        os += (first ? "" : " | ");
        os += "VIDEO_ENCODER";
        first = false;
        flipped |= BufferUsage::VIDEO_ENCODER;
    }
    if ((o & BufferUsage::CAMERA_OUTPUT) == static_cast<uint64_t>(BufferUsage::CAMERA_OUTPUT)) {
        os += (first ? "" : " | ");
        os += "CAMERA_OUTPUT";
        first = false;
        flipped |= BufferUsage::CAMERA_OUTPUT;
    }
    if ((o & BufferUsage::CAMERA_INPUT) == static_cast<uint64_t>(BufferUsage::CAMERA_INPUT)) {
        os += (first ? "" : " | ");
        os += "CAMERA_INPUT";
        first = false;
        flipped |= BufferUsage::CAMERA_INPUT;
    }
    if ((o & BufferUsage::RENDERSCRIPT) == static_cast<uint64_t>(BufferUsage::RENDERSCRIPT)) {
        os += (first ? "" : " | ");
        os += "RENDERSCRIPT";
        first = false;
        flipped |= BufferUsage::RENDERSCRIPT;
    }
    if ((o & BufferUsage::VIDEO_DECODER) == static_cast<uint64_t>(BufferUsage::VIDEO_DECODER)) {
        os += (first ? "" : " | ");
        os += "VIDEO_DECODER";
        first = false;
        flipped |= BufferUsage::VIDEO_DECODER;
    }
    if ((o & BufferUsage::SENSOR_DIRECT_DATA) == static_cast<uint64_t>(BufferUsage::SENSOR_DIRECT_DATA)) {
        os += (first ? "" : " | ");
        os += "SENSOR_DIRECT_DATA";
        first = false;
        flipped |= BufferUsage::SENSOR_DIRECT_DATA;
    }
    if ((o & BufferUsage::GPU_DATA_BUFFER) == static_cast<uint64_t>(BufferUsage::GPU_DATA_BUFFER)) {
        os += (first ? "" : " | ");
        os += "GPU_DATA_BUFFER";
        first = false;
        flipped |= BufferUsage::GPU_DATA_BUFFER;
    }
    if ((o & BufferUsage::VENDOR_MASK) == static_cast<uint64_t>(BufferUsage::VENDOR_MASK)) {
        os += (first ? "" : " | ");
        os += "VENDOR_MASK";
        first = false;
        flipped |= BufferUsage::VENDOR_MASK;
    }
    if ((o & BufferUsage::VENDOR_MASK_HI) == static_cast<uint64_t>(BufferUsage::VENDOR_MASK_HI)) {
        os += (first ? "" : " | ");
        os += "VENDOR_MASK_HI";
        first = false;
        flipped |= BufferUsage::VENDOR_MASK_HI;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(BufferUsage o) {
    using ::android::hardware::details::toHexString;
    if (o == BufferUsage::CPU_READ_MASK) {
        return "CPU_READ_MASK";
    }
    if (o == BufferUsage::CPU_READ_NEVER) {
        return "CPU_READ_NEVER";
    }
    if (o == BufferUsage::CPU_READ_RARELY) {
        return "CPU_READ_RARELY";
    }
    if (o == BufferUsage::CPU_READ_OFTEN) {
        return "CPU_READ_OFTEN";
    }
    if (o == BufferUsage::CPU_WRITE_MASK) {
        return "CPU_WRITE_MASK";
    }
    if (o == BufferUsage::CPU_WRITE_NEVER) {
        return "CPU_WRITE_NEVER";
    }
    if (o == BufferUsage::CPU_WRITE_RARELY) {
        return "CPU_WRITE_RARELY";
    }
    if (o == BufferUsage::CPU_WRITE_OFTEN) {
        return "CPU_WRITE_OFTEN";
    }
    if (o == BufferUsage::GPU_TEXTURE) {
        return "GPU_TEXTURE";
    }
    if (o == BufferUsage::GPU_RENDER_TARGET) {
        return "GPU_RENDER_TARGET";
    }
    if (o == BufferUsage::COMPOSER_OVERLAY) {
        return "COMPOSER_OVERLAY";
    }
    if (o == BufferUsage::COMPOSER_CLIENT_TARGET) {
        return "COMPOSER_CLIENT_TARGET";
    }
    if (o == BufferUsage::PROTECTED) {
        return "PROTECTED";
    }
    if (o == BufferUsage::COMPOSER_CURSOR) {
        return "COMPOSER_CURSOR";
    }
    if (o == BufferUsage::VIDEO_ENCODER) {
        return "VIDEO_ENCODER";
    }
    if (o == BufferUsage::CAMERA_OUTPUT) {
        return "CAMERA_OUTPUT";
    }
    if (o == BufferUsage::CAMERA_INPUT) {
        return "CAMERA_INPUT";
    }
    if (o == BufferUsage::RENDERSCRIPT) {
        return "RENDERSCRIPT";
    }
    if (o == BufferUsage::VIDEO_DECODER) {
        return "VIDEO_DECODER";
    }
    if (o == BufferUsage::SENSOR_DIRECT_DATA) {
        return "SENSOR_DIRECT_DATA";
    }
    if (o == BufferUsage::GPU_DATA_BUFFER) {
        return "GPU_DATA_BUFFER";
    }
    if (o == BufferUsage::VENDOR_MASK) {
        return "VENDOR_MASK";
    }
    if (o == BufferUsage::VENDOR_MASK_HI) {
        return "VENDOR_MASK_HI";
    }
    std::string os;
    os += toHexString(static_cast<uint64_t>(o));
    return os;
}

template<>
std::string toString<Transform>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & Transform::FLIP_H) == static_cast<int32_t>(Transform::FLIP_H)) {
        os += (first ? "" : " | ");
        os += "FLIP_H";
        first = false;
        flipped |= Transform::FLIP_H;
    }
    if ((o & Transform::FLIP_V) == static_cast<int32_t>(Transform::FLIP_V)) {
        os += (first ? "" : " | ");
        os += "FLIP_V";
        first = false;
        flipped |= Transform::FLIP_V;
    }
    if ((o & Transform::ROT_90) == static_cast<int32_t>(Transform::ROT_90)) {
        os += (first ? "" : " | ");
        os += "ROT_90";
        first = false;
        flipped |= Transform::ROT_90;
    }
    if ((o & Transform::ROT_180) == static_cast<int32_t>(Transform::ROT_180)) {
        os += (first ? "" : " | ");
        os += "ROT_180";
        first = false;
        flipped |= Transform::ROT_180;
    }
    if ((o & Transform::ROT_270) == static_cast<int32_t>(Transform::ROT_270)) {
        os += (first ? "" : " | ");
        os += "ROT_270";
        first = false;
        flipped |= Transform::ROT_270;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(Transform o) {
    using ::android::hardware::details::toHexString;
    if (o == Transform::FLIP_H) {
        return "FLIP_H";
    }
    if (o == Transform::FLIP_V) {
        return "FLIP_V";
    }
    if (o == Transform::ROT_90) {
        return "ROT_90";
    }
    if (o == Transform::ROT_180) {
        return "ROT_180";
    }
    if (o == Transform::ROT_270) {
        return "ROT_270";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<Dataspace>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & Dataspace::UNKNOWN) == static_cast<int32_t>(Dataspace::UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN";
        first = false;
        flipped |= Dataspace::UNKNOWN;
    }
    if ((o & Dataspace::ARBITRARY) == static_cast<int32_t>(Dataspace::ARBITRARY)) {
        os += (first ? "" : " | ");
        os += "ARBITRARY";
        first = false;
        flipped |= Dataspace::ARBITRARY;
    }
    if ((o & Dataspace::STANDARD_SHIFT) == static_cast<int32_t>(Dataspace::STANDARD_SHIFT)) {
        os += (first ? "" : " | ");
        os += "STANDARD_SHIFT";
        first = false;
        flipped |= Dataspace::STANDARD_SHIFT;
    }
    if ((o & Dataspace::STANDARD_MASK) == static_cast<int32_t>(Dataspace::STANDARD_MASK)) {
        os += (first ? "" : " | ");
        os += "STANDARD_MASK";
        first = false;
        flipped |= Dataspace::STANDARD_MASK;
    }
    if ((o & Dataspace::STANDARD_UNSPECIFIED) == static_cast<int32_t>(Dataspace::STANDARD_UNSPECIFIED)) {
        os += (first ? "" : " | ");
        os += "STANDARD_UNSPECIFIED";
        first = false;
        flipped |= Dataspace::STANDARD_UNSPECIFIED;
    }
    if ((o & Dataspace::STANDARD_BT709) == static_cast<int32_t>(Dataspace::STANDARD_BT709)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT709";
        first = false;
        flipped |= Dataspace::STANDARD_BT709;
    }
    if ((o & Dataspace::STANDARD_BT601_625) == static_cast<int32_t>(Dataspace::STANDARD_BT601_625)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT601_625";
        first = false;
        flipped |= Dataspace::STANDARD_BT601_625;
    }
    if ((o & Dataspace::STANDARD_BT601_625_UNADJUSTED) == static_cast<int32_t>(Dataspace::STANDARD_BT601_625_UNADJUSTED)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT601_625_UNADJUSTED";
        first = false;
        flipped |= Dataspace::STANDARD_BT601_625_UNADJUSTED;
    }
    if ((o & Dataspace::STANDARD_BT601_525) == static_cast<int32_t>(Dataspace::STANDARD_BT601_525)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT601_525";
        first = false;
        flipped |= Dataspace::STANDARD_BT601_525;
    }
    if ((o & Dataspace::STANDARD_BT601_525_UNADJUSTED) == static_cast<int32_t>(Dataspace::STANDARD_BT601_525_UNADJUSTED)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT601_525_UNADJUSTED";
        first = false;
        flipped |= Dataspace::STANDARD_BT601_525_UNADJUSTED;
    }
    if ((o & Dataspace::STANDARD_BT2020) == static_cast<int32_t>(Dataspace::STANDARD_BT2020)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT2020";
        first = false;
        flipped |= Dataspace::STANDARD_BT2020;
    }
    if ((o & Dataspace::STANDARD_BT2020_CONSTANT_LUMINANCE) == static_cast<int32_t>(Dataspace::STANDARD_BT2020_CONSTANT_LUMINANCE)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT2020_CONSTANT_LUMINANCE";
        first = false;
        flipped |= Dataspace::STANDARD_BT2020_CONSTANT_LUMINANCE;
    }
    if ((o & Dataspace::STANDARD_BT470M) == static_cast<int32_t>(Dataspace::STANDARD_BT470M)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT470M";
        first = false;
        flipped |= Dataspace::STANDARD_BT470M;
    }
    if ((o & Dataspace::STANDARD_FILM) == static_cast<int32_t>(Dataspace::STANDARD_FILM)) {
        os += (first ? "" : " | ");
        os += "STANDARD_FILM";
        first = false;
        flipped |= Dataspace::STANDARD_FILM;
    }
    if ((o & Dataspace::STANDARD_DCI_P3) == static_cast<int32_t>(Dataspace::STANDARD_DCI_P3)) {
        os += (first ? "" : " | ");
        os += "STANDARD_DCI_P3";
        first = false;
        flipped |= Dataspace::STANDARD_DCI_P3;
    }
    if ((o & Dataspace::STANDARD_ADOBE_RGB) == static_cast<int32_t>(Dataspace::STANDARD_ADOBE_RGB)) {
        os += (first ? "" : " | ");
        os += "STANDARD_ADOBE_RGB";
        first = false;
        flipped |= Dataspace::STANDARD_ADOBE_RGB;
    }
    if ((o & Dataspace::TRANSFER_SHIFT) == static_cast<int32_t>(Dataspace::TRANSFER_SHIFT)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_SHIFT";
        first = false;
        flipped |= Dataspace::TRANSFER_SHIFT;
    }
    if ((o & Dataspace::TRANSFER_MASK) == static_cast<int32_t>(Dataspace::TRANSFER_MASK)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_MASK";
        first = false;
        flipped |= Dataspace::TRANSFER_MASK;
    }
    if ((o & Dataspace::TRANSFER_UNSPECIFIED) == static_cast<int32_t>(Dataspace::TRANSFER_UNSPECIFIED)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_UNSPECIFIED";
        first = false;
        flipped |= Dataspace::TRANSFER_UNSPECIFIED;
    }
    if ((o & Dataspace::TRANSFER_LINEAR) == static_cast<int32_t>(Dataspace::TRANSFER_LINEAR)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_LINEAR";
        first = false;
        flipped |= Dataspace::TRANSFER_LINEAR;
    }
    if ((o & Dataspace::TRANSFER_SRGB) == static_cast<int32_t>(Dataspace::TRANSFER_SRGB)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_SRGB";
        first = false;
        flipped |= Dataspace::TRANSFER_SRGB;
    }
    if ((o & Dataspace::TRANSFER_SMPTE_170M) == static_cast<int32_t>(Dataspace::TRANSFER_SMPTE_170M)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_SMPTE_170M";
        first = false;
        flipped |= Dataspace::TRANSFER_SMPTE_170M;
    }
    if ((o & Dataspace::TRANSFER_GAMMA2_2) == static_cast<int32_t>(Dataspace::TRANSFER_GAMMA2_2)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_GAMMA2_2";
        first = false;
        flipped |= Dataspace::TRANSFER_GAMMA2_2;
    }
    if ((o & Dataspace::TRANSFER_GAMMA2_6) == static_cast<int32_t>(Dataspace::TRANSFER_GAMMA2_6)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_GAMMA2_6";
        first = false;
        flipped |= Dataspace::TRANSFER_GAMMA2_6;
    }
    if ((o & Dataspace::TRANSFER_GAMMA2_8) == static_cast<int32_t>(Dataspace::TRANSFER_GAMMA2_8)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_GAMMA2_8";
        first = false;
        flipped |= Dataspace::TRANSFER_GAMMA2_8;
    }
    if ((o & Dataspace::TRANSFER_ST2084) == static_cast<int32_t>(Dataspace::TRANSFER_ST2084)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_ST2084";
        first = false;
        flipped |= Dataspace::TRANSFER_ST2084;
    }
    if ((o & Dataspace::TRANSFER_HLG) == static_cast<int32_t>(Dataspace::TRANSFER_HLG)) {
        os += (first ? "" : " | ");
        os += "TRANSFER_HLG";
        first = false;
        flipped |= Dataspace::TRANSFER_HLG;
    }
    if ((o & Dataspace::RANGE_SHIFT) == static_cast<int32_t>(Dataspace::RANGE_SHIFT)) {
        os += (first ? "" : " | ");
        os += "RANGE_SHIFT";
        first = false;
        flipped |= Dataspace::RANGE_SHIFT;
    }
    if ((o & Dataspace::RANGE_MASK) == static_cast<int32_t>(Dataspace::RANGE_MASK)) {
        os += (first ? "" : " | ");
        os += "RANGE_MASK";
        first = false;
        flipped |= Dataspace::RANGE_MASK;
    }
    if ((o & Dataspace::RANGE_UNSPECIFIED) == static_cast<int32_t>(Dataspace::RANGE_UNSPECIFIED)) {
        os += (first ? "" : " | ");
        os += "RANGE_UNSPECIFIED";
        first = false;
        flipped |= Dataspace::RANGE_UNSPECIFIED;
    }
    if ((o & Dataspace::RANGE_FULL) == static_cast<int32_t>(Dataspace::RANGE_FULL)) {
        os += (first ? "" : " | ");
        os += "RANGE_FULL";
        first = false;
        flipped |= Dataspace::RANGE_FULL;
    }
    if ((o & Dataspace::RANGE_LIMITED) == static_cast<int32_t>(Dataspace::RANGE_LIMITED)) {
        os += (first ? "" : " | ");
        os += "RANGE_LIMITED";
        first = false;
        flipped |= Dataspace::RANGE_LIMITED;
    }
    if ((o & Dataspace::RANGE_EXTENDED) == static_cast<int32_t>(Dataspace::RANGE_EXTENDED)) {
        os += (first ? "" : " | ");
        os += "RANGE_EXTENDED";
        first = false;
        flipped |= Dataspace::RANGE_EXTENDED;
    }
    if ((o & Dataspace::SRGB_LINEAR) == static_cast<int32_t>(Dataspace::SRGB_LINEAR)) {
        os += (first ? "" : " | ");
        os += "SRGB_LINEAR";
        first = false;
        flipped |= Dataspace::SRGB_LINEAR;
    }
    if ((o & Dataspace::V0_SRGB_LINEAR) == static_cast<int32_t>(Dataspace::V0_SRGB_LINEAR)) {
        os += (first ? "" : " | ");
        os += "V0_SRGB_LINEAR";
        first = false;
        flipped |= Dataspace::V0_SRGB_LINEAR;
    }
    if ((o & Dataspace::V0_SCRGB_LINEAR) == static_cast<int32_t>(Dataspace::V0_SCRGB_LINEAR)) {
        os += (first ? "" : " | ");
        os += "V0_SCRGB_LINEAR";
        first = false;
        flipped |= Dataspace::V0_SCRGB_LINEAR;
    }
    if ((o & Dataspace::SRGB) == static_cast<int32_t>(Dataspace::SRGB)) {
        os += (first ? "" : " | ");
        os += "SRGB";
        first = false;
        flipped |= Dataspace::SRGB;
    }
    if ((o & Dataspace::V0_SRGB) == static_cast<int32_t>(Dataspace::V0_SRGB)) {
        os += (first ? "" : " | ");
        os += "V0_SRGB";
        first = false;
        flipped |= Dataspace::V0_SRGB;
    }
    if ((o & Dataspace::V0_SCRGB) == static_cast<int32_t>(Dataspace::V0_SCRGB)) {
        os += (first ? "" : " | ");
        os += "V0_SCRGB";
        first = false;
        flipped |= Dataspace::V0_SCRGB;
    }
    if ((o & Dataspace::JFIF) == static_cast<int32_t>(Dataspace::JFIF)) {
        os += (first ? "" : " | ");
        os += "JFIF";
        first = false;
        flipped |= Dataspace::JFIF;
    }
    if ((o & Dataspace::V0_JFIF) == static_cast<int32_t>(Dataspace::V0_JFIF)) {
        os += (first ? "" : " | ");
        os += "V0_JFIF";
        first = false;
        flipped |= Dataspace::V0_JFIF;
    }
    if ((o & Dataspace::BT601_625) == static_cast<int32_t>(Dataspace::BT601_625)) {
        os += (first ? "" : " | ");
        os += "BT601_625";
        first = false;
        flipped |= Dataspace::BT601_625;
    }
    if ((o & Dataspace::V0_BT601_625) == static_cast<int32_t>(Dataspace::V0_BT601_625)) {
        os += (first ? "" : " | ");
        os += "V0_BT601_625";
        first = false;
        flipped |= Dataspace::V0_BT601_625;
    }
    if ((o & Dataspace::BT601_525) == static_cast<int32_t>(Dataspace::BT601_525)) {
        os += (first ? "" : " | ");
        os += "BT601_525";
        first = false;
        flipped |= Dataspace::BT601_525;
    }
    if ((o & Dataspace::V0_BT601_525) == static_cast<int32_t>(Dataspace::V0_BT601_525)) {
        os += (first ? "" : " | ");
        os += "V0_BT601_525";
        first = false;
        flipped |= Dataspace::V0_BT601_525;
    }
    if ((o & Dataspace::BT709) == static_cast<int32_t>(Dataspace::BT709)) {
        os += (first ? "" : " | ");
        os += "BT709";
        first = false;
        flipped |= Dataspace::BT709;
    }
    if ((o & Dataspace::V0_BT709) == static_cast<int32_t>(Dataspace::V0_BT709)) {
        os += (first ? "" : " | ");
        os += "V0_BT709";
        first = false;
        flipped |= Dataspace::V0_BT709;
    }
    if ((o & Dataspace::DCI_P3_LINEAR) == static_cast<int32_t>(Dataspace::DCI_P3_LINEAR)) {
        os += (first ? "" : " | ");
        os += "DCI_P3_LINEAR";
        first = false;
        flipped |= Dataspace::DCI_P3_LINEAR;
    }
    if ((o & Dataspace::DCI_P3) == static_cast<int32_t>(Dataspace::DCI_P3)) {
        os += (first ? "" : " | ");
        os += "DCI_P3";
        first = false;
        flipped |= Dataspace::DCI_P3;
    }
    if ((o & Dataspace::DISPLAY_P3_LINEAR) == static_cast<int32_t>(Dataspace::DISPLAY_P3_LINEAR)) {
        os += (first ? "" : " | ");
        os += "DISPLAY_P3_LINEAR";
        first = false;
        flipped |= Dataspace::DISPLAY_P3_LINEAR;
    }
    if ((o & Dataspace::DISPLAY_P3) == static_cast<int32_t>(Dataspace::DISPLAY_P3)) {
        os += (first ? "" : " | ");
        os += "DISPLAY_P3";
        first = false;
        flipped |= Dataspace::DISPLAY_P3;
    }
    if ((o & Dataspace::ADOBE_RGB) == static_cast<int32_t>(Dataspace::ADOBE_RGB)) {
        os += (first ? "" : " | ");
        os += "ADOBE_RGB";
        first = false;
        flipped |= Dataspace::ADOBE_RGB;
    }
    if ((o & Dataspace::BT2020_LINEAR) == static_cast<int32_t>(Dataspace::BT2020_LINEAR)) {
        os += (first ? "" : " | ");
        os += "BT2020_LINEAR";
        first = false;
        flipped |= Dataspace::BT2020_LINEAR;
    }
    if ((o & Dataspace::BT2020) == static_cast<int32_t>(Dataspace::BT2020)) {
        os += (first ? "" : " | ");
        os += "BT2020";
        first = false;
        flipped |= Dataspace::BT2020;
    }
    if ((o & Dataspace::BT2020_PQ) == static_cast<int32_t>(Dataspace::BT2020_PQ)) {
        os += (first ? "" : " | ");
        os += "BT2020_PQ";
        first = false;
        flipped |= Dataspace::BT2020_PQ;
    }
    if ((o & Dataspace::DEPTH) == static_cast<int32_t>(Dataspace::DEPTH)) {
        os += (first ? "" : " | ");
        os += "DEPTH";
        first = false;
        flipped |= Dataspace::DEPTH;
    }
    if ((o & Dataspace::SENSOR) == static_cast<int32_t>(Dataspace::SENSOR)) {
        os += (first ? "" : " | ");
        os += "SENSOR";
        first = false;
        flipped |= Dataspace::SENSOR;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(Dataspace o) {
    using ::android::hardware::details::toHexString;
    if (o == Dataspace::UNKNOWN) {
        return "UNKNOWN";
    }
    if (o == Dataspace::ARBITRARY) {
        return "ARBITRARY";
    }
    if (o == Dataspace::STANDARD_SHIFT) {
        return "STANDARD_SHIFT";
    }
    if (o == Dataspace::STANDARD_MASK) {
        return "STANDARD_MASK";
    }
    if (o == Dataspace::STANDARD_UNSPECIFIED) {
        return "STANDARD_UNSPECIFIED";
    }
    if (o == Dataspace::STANDARD_BT709) {
        return "STANDARD_BT709";
    }
    if (o == Dataspace::STANDARD_BT601_625) {
        return "STANDARD_BT601_625";
    }
    if (o == Dataspace::STANDARD_BT601_625_UNADJUSTED) {
        return "STANDARD_BT601_625_UNADJUSTED";
    }
    if (o == Dataspace::STANDARD_BT601_525) {
        return "STANDARD_BT601_525";
    }
    if (o == Dataspace::STANDARD_BT601_525_UNADJUSTED) {
        return "STANDARD_BT601_525_UNADJUSTED";
    }
    if (o == Dataspace::STANDARD_BT2020) {
        return "STANDARD_BT2020";
    }
    if (o == Dataspace::STANDARD_BT2020_CONSTANT_LUMINANCE) {
        return "STANDARD_BT2020_CONSTANT_LUMINANCE";
    }
    if (o == Dataspace::STANDARD_BT470M) {
        return "STANDARD_BT470M";
    }
    if (o == Dataspace::STANDARD_FILM) {
        return "STANDARD_FILM";
    }
    if (o == Dataspace::STANDARD_DCI_P3) {
        return "STANDARD_DCI_P3";
    }
    if (o == Dataspace::STANDARD_ADOBE_RGB) {
        return "STANDARD_ADOBE_RGB";
    }
    if (o == Dataspace::TRANSFER_SHIFT) {
        return "TRANSFER_SHIFT";
    }
    if (o == Dataspace::TRANSFER_MASK) {
        return "TRANSFER_MASK";
    }
    if (o == Dataspace::TRANSFER_UNSPECIFIED) {
        return "TRANSFER_UNSPECIFIED";
    }
    if (o == Dataspace::TRANSFER_LINEAR) {
        return "TRANSFER_LINEAR";
    }
    if (o == Dataspace::TRANSFER_SRGB) {
        return "TRANSFER_SRGB";
    }
    if (o == Dataspace::TRANSFER_SMPTE_170M) {
        return "TRANSFER_SMPTE_170M";
    }
    if (o == Dataspace::TRANSFER_GAMMA2_2) {
        return "TRANSFER_GAMMA2_2";
    }
    if (o == Dataspace::TRANSFER_GAMMA2_6) {
        return "TRANSFER_GAMMA2_6";
    }
    if (o == Dataspace::TRANSFER_GAMMA2_8) {
        return "TRANSFER_GAMMA2_8";
    }
    if (o == Dataspace::TRANSFER_ST2084) {
        return "TRANSFER_ST2084";
    }
    if (o == Dataspace::TRANSFER_HLG) {
        return "TRANSFER_HLG";
    }
    if (o == Dataspace::RANGE_SHIFT) {
        return "RANGE_SHIFT";
    }
    if (o == Dataspace::RANGE_MASK) {
        return "RANGE_MASK";
    }
    if (o == Dataspace::RANGE_UNSPECIFIED) {
        return "RANGE_UNSPECIFIED";
    }
    if (o == Dataspace::RANGE_FULL) {
        return "RANGE_FULL";
    }
    if (o == Dataspace::RANGE_LIMITED) {
        return "RANGE_LIMITED";
    }
    if (o == Dataspace::RANGE_EXTENDED) {
        return "RANGE_EXTENDED";
    }
    if (o == Dataspace::SRGB_LINEAR) {
        return "SRGB_LINEAR";
    }
    if (o == Dataspace::V0_SRGB_LINEAR) {
        return "V0_SRGB_LINEAR";
    }
    if (o == Dataspace::V0_SCRGB_LINEAR) {
        return "V0_SCRGB_LINEAR";
    }
    if (o == Dataspace::SRGB) {
        return "SRGB";
    }
    if (o == Dataspace::V0_SRGB) {
        return "V0_SRGB";
    }
    if (o == Dataspace::V0_SCRGB) {
        return "V0_SCRGB";
    }
    if (o == Dataspace::JFIF) {
        return "JFIF";
    }
    if (o == Dataspace::V0_JFIF) {
        return "V0_JFIF";
    }
    if (o == Dataspace::BT601_625) {
        return "BT601_625";
    }
    if (o == Dataspace::V0_BT601_625) {
        return "V0_BT601_625";
    }
    if (o == Dataspace::BT601_525) {
        return "BT601_525";
    }
    if (o == Dataspace::V0_BT601_525) {
        return "V0_BT601_525";
    }
    if (o == Dataspace::BT709) {
        return "BT709";
    }
    if (o == Dataspace::V0_BT709) {
        return "V0_BT709";
    }
    if (o == Dataspace::DCI_P3_LINEAR) {
        return "DCI_P3_LINEAR";
    }
    if (o == Dataspace::DCI_P3) {
        return "DCI_P3";
    }
    if (o == Dataspace::DISPLAY_P3_LINEAR) {
        return "DISPLAY_P3_LINEAR";
    }
    if (o == Dataspace::DISPLAY_P3) {
        return "DISPLAY_P3";
    }
    if (o == Dataspace::ADOBE_RGB) {
        return "ADOBE_RGB";
    }
    if (o == Dataspace::BT2020_LINEAR) {
        return "BT2020_LINEAR";
    }
    if (o == Dataspace::BT2020) {
        return "BT2020";
    }
    if (o == Dataspace::BT2020_PQ) {
        return "BT2020_PQ";
    }
    if (o == Dataspace::DEPTH) {
        return "DEPTH";
    }
    if (o == Dataspace::SENSOR) {
        return "SENSOR";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<ColorMode>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & ColorMode::NATIVE) == static_cast<int32_t>(ColorMode::NATIVE)) {
        os += (first ? "" : " | ");
        os += "NATIVE";
        first = false;
        flipped |= ColorMode::NATIVE;
    }
    if ((o & ColorMode::STANDARD_BT601_625) == static_cast<int32_t>(ColorMode::STANDARD_BT601_625)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT601_625";
        first = false;
        flipped |= ColorMode::STANDARD_BT601_625;
    }
    if ((o & ColorMode::STANDARD_BT601_625_UNADJUSTED) == static_cast<int32_t>(ColorMode::STANDARD_BT601_625_UNADJUSTED)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT601_625_UNADJUSTED";
        first = false;
        flipped |= ColorMode::STANDARD_BT601_625_UNADJUSTED;
    }
    if ((o & ColorMode::STANDARD_BT601_525) == static_cast<int32_t>(ColorMode::STANDARD_BT601_525)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT601_525";
        first = false;
        flipped |= ColorMode::STANDARD_BT601_525;
    }
    if ((o & ColorMode::STANDARD_BT601_525_UNADJUSTED) == static_cast<int32_t>(ColorMode::STANDARD_BT601_525_UNADJUSTED)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT601_525_UNADJUSTED";
        first = false;
        flipped |= ColorMode::STANDARD_BT601_525_UNADJUSTED;
    }
    if ((o & ColorMode::STANDARD_BT709) == static_cast<int32_t>(ColorMode::STANDARD_BT709)) {
        os += (first ? "" : " | ");
        os += "STANDARD_BT709";
        first = false;
        flipped |= ColorMode::STANDARD_BT709;
    }
    if ((o & ColorMode::DCI_P3) == static_cast<int32_t>(ColorMode::DCI_P3)) {
        os += (first ? "" : " | ");
        os += "DCI_P3";
        first = false;
        flipped |= ColorMode::DCI_P3;
    }
    if ((o & ColorMode::SRGB) == static_cast<int32_t>(ColorMode::SRGB)) {
        os += (first ? "" : " | ");
        os += "SRGB";
        first = false;
        flipped |= ColorMode::SRGB;
    }
    if ((o & ColorMode::ADOBE_RGB) == static_cast<int32_t>(ColorMode::ADOBE_RGB)) {
        os += (first ? "" : " | ");
        os += "ADOBE_RGB";
        first = false;
        flipped |= ColorMode::ADOBE_RGB;
    }
    if ((o & ColorMode::DISPLAY_P3) == static_cast<int32_t>(ColorMode::DISPLAY_P3)) {
        os += (first ? "" : " | ");
        os += "DISPLAY_P3";
        first = false;
        flipped |= ColorMode::DISPLAY_P3;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(ColorMode o) {
    using ::android::hardware::details::toHexString;
    if (o == ColorMode::NATIVE) {
        return "NATIVE";
    }
    if (o == ColorMode::STANDARD_BT601_625) {
        return "STANDARD_BT601_625";
    }
    if (o == ColorMode::STANDARD_BT601_625_UNADJUSTED) {
        return "STANDARD_BT601_625_UNADJUSTED";
    }
    if (o == ColorMode::STANDARD_BT601_525) {
        return "STANDARD_BT601_525";
    }
    if (o == ColorMode::STANDARD_BT601_525_UNADJUSTED) {
        return "STANDARD_BT601_525_UNADJUSTED";
    }
    if (o == ColorMode::STANDARD_BT709) {
        return "STANDARD_BT709";
    }
    if (o == ColorMode::DCI_P3) {
        return "DCI_P3";
    }
    if (o == ColorMode::SRGB) {
        return "SRGB";
    }
    if (o == ColorMode::ADOBE_RGB) {
        return "ADOBE_RGB";
    }
    if (o == ColorMode::DISPLAY_P3) {
        return "DISPLAY_P3";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<ColorTransform>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & ColorTransform::IDENTITY) == static_cast<int32_t>(ColorTransform::IDENTITY)) {
        os += (first ? "" : " | ");
        os += "IDENTITY";
        first = false;
        flipped |= ColorTransform::IDENTITY;
    }
    if ((o & ColorTransform::ARBITRARY_MATRIX) == static_cast<int32_t>(ColorTransform::ARBITRARY_MATRIX)) {
        os += (first ? "" : " | ");
        os += "ARBITRARY_MATRIX";
        first = false;
        flipped |= ColorTransform::ARBITRARY_MATRIX;
    }
    if ((o & ColorTransform::VALUE_INVERSE) == static_cast<int32_t>(ColorTransform::VALUE_INVERSE)) {
        os += (first ? "" : " | ");
        os += "VALUE_INVERSE";
        first = false;
        flipped |= ColorTransform::VALUE_INVERSE;
    }
    if ((o & ColorTransform::GRAYSCALE) == static_cast<int32_t>(ColorTransform::GRAYSCALE)) {
        os += (first ? "" : " | ");
        os += "GRAYSCALE";
        first = false;
        flipped |= ColorTransform::GRAYSCALE;
    }
    if ((o & ColorTransform::CORRECT_PROTANOPIA) == static_cast<int32_t>(ColorTransform::CORRECT_PROTANOPIA)) {
        os += (first ? "" : " | ");
        os += "CORRECT_PROTANOPIA";
        first = false;
        flipped |= ColorTransform::CORRECT_PROTANOPIA;
    }
    if ((o & ColorTransform::CORRECT_DEUTERANOPIA) == static_cast<int32_t>(ColorTransform::CORRECT_DEUTERANOPIA)) {
        os += (first ? "" : " | ");
        os += "CORRECT_DEUTERANOPIA";
        first = false;
        flipped |= ColorTransform::CORRECT_DEUTERANOPIA;
    }
    if ((o & ColorTransform::CORRECT_TRITANOPIA) == static_cast<int32_t>(ColorTransform::CORRECT_TRITANOPIA)) {
        os += (first ? "" : " | ");
        os += "CORRECT_TRITANOPIA";
        first = false;
        flipped |= ColorTransform::CORRECT_TRITANOPIA;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(ColorTransform o) {
    using ::android::hardware::details::toHexString;
    if (o == ColorTransform::IDENTITY) {
        return "IDENTITY";
    }
    if (o == ColorTransform::ARBITRARY_MATRIX) {
        return "ARBITRARY_MATRIX";
    }
    if (o == ColorTransform::VALUE_INVERSE) {
        return "VALUE_INVERSE";
    }
    if (o == ColorTransform::GRAYSCALE) {
        return "GRAYSCALE";
    }
    if (o == ColorTransform::CORRECT_PROTANOPIA) {
        return "CORRECT_PROTANOPIA";
    }
    if (o == ColorTransform::CORRECT_DEUTERANOPIA) {
        return "CORRECT_DEUTERANOPIA";
    }
    if (o == ColorTransform::CORRECT_TRITANOPIA) {
        return "CORRECT_TRITANOPIA";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
std::string toString<Hdr>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    int32_t flipped = 0;
    bool first = true;
    if ((o & Hdr::DOLBY_VISION) == static_cast<int32_t>(Hdr::DOLBY_VISION)) {
        os += (first ? "" : " | ");
        os += "DOLBY_VISION";
        first = false;
        flipped |= Hdr::DOLBY_VISION;
    }
    if ((o & Hdr::HDR10) == static_cast<int32_t>(Hdr::HDR10)) {
        os += (first ? "" : " | ");
        os += "HDR10";
        first = false;
        flipped |= Hdr::HDR10;
    }
    if ((o & Hdr::HLG) == static_cast<int32_t>(Hdr::HLG)) {
        os += (first ? "" : " | ");
        os += "HLG";
        first = false;
        flipped |= Hdr::HLG;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

std::string toString(Hdr o) {
    using ::android::hardware::details::toHexString;
    if (o == Hdr::DOLBY_VISION) {
        return "DOLBY_VISION";
    }
    if (o == Hdr::HDR10) {
        return "HDR10";
    }
    if (o == Hdr::HLG) {
        return "HLG";
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

}  // namespace V1_0
}  // namespace common
}  // namespace graphics
}  // namespace hardware
}  // namespace android
