#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_ICOMPOSERCLIENT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_ICOMPOSERCLIENT_H

#include <android/hardware/graphics/common/1.0/types.h>
#include <android/hardware/graphics/composer/2.1/IComposerCallback.h>
#include <android/hardware/graphics/composer/2.1/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace graphics {
namespace composer {
namespace V2_1 {

struct IComposerClient : public ::android::hidl::base::V1_0::IBase {
    enum class Attribute : int32_t {
        INVALID = 0,
        WIDTH = 1,
        HEIGHT = 2,
        VSYNC_PERIOD = 3,
        DPI_X = 4,
        DPI_Y = 5,
    };

    enum class DisplayRequest : uint32_t {
        FLIP_CLIENT_TARGET = 1u, // (1 << 0)
        WRITE_CLIENT_TARGET_TO_OUTPUT = 2u, // (1 << 1)
    };

    enum class LayerRequest : uint32_t {
        CLEAR_CLIENT_TARGET = 1u, // (1 << 0)
    };

    enum class PowerMode : int32_t {
        OFF = 0,
        DOZE = 1,
        DOZE_SUSPEND = 3,
        ON = 2,
    };

    enum class Vsync : int32_t {
        INVALID = 0,
        ENABLE = 1,
        DISABLE = 2,
    };

    enum class BlendMode : int32_t {
        INVALID = 0,
        NONE = 1,
        PREMULTIPLIED = 2,
        COVERAGE = 3,
    };

    enum class Composition : int32_t {
        INVALID = 0,
        CLIENT = 1,
        DEVICE = 2,
        SOLID_COLOR = 3,
        CURSOR = 4,
        SIDEBAND = 5,
    };

    enum class DisplayType : int32_t {
        INVALID = 0,
        PHYSICAL = 1,
        VIRTUAL = 2,
    };

    enum class HandleIndex : int32_t {
        EMPTY = -1, // (-1)
        CACHED = -2, // (-2)
    };

    struct Rect final {
        int32_t left __attribute__ ((aligned(4)));
        int32_t top __attribute__ ((aligned(4)));
        int32_t right __attribute__ ((aligned(4)));
        int32_t bottom __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(IComposerClient::Rect, left) == 0, "wrong offset");
    static_assert(offsetof(IComposerClient::Rect, top) == 4, "wrong offset");
    static_assert(offsetof(IComposerClient::Rect, right) == 8, "wrong offset");
    static_assert(offsetof(IComposerClient::Rect, bottom) == 12, "wrong offset");
    static_assert(sizeof(IComposerClient::Rect) == 16, "wrong size");
    static_assert(__alignof(IComposerClient::Rect) == 4, "wrong alignment");

    struct FRect final {
        float left __attribute__ ((aligned(4)));
        float top __attribute__ ((aligned(4)));
        float right __attribute__ ((aligned(4)));
        float bottom __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(IComposerClient::FRect, left) == 0, "wrong offset");
    static_assert(offsetof(IComposerClient::FRect, top) == 4, "wrong offset");
    static_assert(offsetof(IComposerClient::FRect, right) == 8, "wrong offset");
    static_assert(offsetof(IComposerClient::FRect, bottom) == 12, "wrong offset");
    static_assert(sizeof(IComposerClient::FRect) == 16, "wrong size");
    static_assert(__alignof(IComposerClient::FRect) == 4, "wrong alignment");

    struct Color final {
        uint8_t r __attribute__ ((aligned(1)));
        uint8_t g __attribute__ ((aligned(1)));
        uint8_t b __attribute__ ((aligned(1)));
        uint8_t a __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(IComposerClient::Color, r) == 0, "wrong offset");
    static_assert(offsetof(IComposerClient::Color, g) == 1, "wrong offset");
    static_assert(offsetof(IComposerClient::Color, b) == 2, "wrong offset");
    static_assert(offsetof(IComposerClient::Color, a) == 3, "wrong offset");
    static_assert(sizeof(IComposerClient::Color) == 4, "wrong size");
    static_assert(__alignof(IComposerClient::Color) == 1, "wrong alignment");

    enum class Command : int32_t {
        LENGTH_MASK = 65535, // 0xffff
        OPCODE_SHIFT = 16,
        OPCODE_MASK = -65536, // (0xffff << OPCODE_SHIFT)
        SELECT_DISPLAY = 0, // (0x000 << OPCODE_SHIFT)
        SELECT_LAYER = 65536, // (0x001 << OPCODE_SHIFT)
        SET_ERROR = 16777216, // (0x100 << OPCODE_SHIFT)
        SET_CHANGED_COMPOSITION_TYPES = 16842752, // (0x101 << OPCODE_SHIFT)
        SET_DISPLAY_REQUESTS = 16908288, // (0x102 << OPCODE_SHIFT)
        SET_PRESENT_FENCE = 16973824, // (0x103 << OPCODE_SHIFT)
        SET_RELEASE_FENCES = 17039360, // (0x104 << OPCODE_SHIFT)
        SET_COLOR_TRANSFORM = 33554432, // (0x200 << OPCODE_SHIFT)
        SET_CLIENT_TARGET = 33619968, // (0x201 << OPCODE_SHIFT)
        SET_OUTPUT_BUFFER = 33685504, // (0x202 << OPCODE_SHIFT)
        VALIDATE_DISPLAY = 33751040, // (0x203 << OPCODE_SHIFT)
        ACCEPT_DISPLAY_CHANGES = 33816576, // (0x204 << OPCODE_SHIFT)
        PRESENT_DISPLAY = 33882112, // (0x205 << OPCODE_SHIFT)
        PRESENT_OR_VALIDATE_DISPLAY = 33947648, // (0x206 << OPCODE_SHIFT)
        SET_LAYER_CURSOR_POSITION = 50331648, // (0x300 << OPCODE_SHIFT)
        SET_LAYER_BUFFER = 50397184, // (0x301 << OPCODE_SHIFT)
        SET_LAYER_SURFACE_DAMAGE = 50462720, // (0x302 << OPCODE_SHIFT)
        SET_LAYER_BLEND_MODE = 67108864, // (0x400 << OPCODE_SHIFT)
        SET_LAYER_COLOR = 67174400, // (0x401 << OPCODE_SHIFT)
        SET_LAYER_COMPOSITION_TYPE = 67239936, // (0x402 << OPCODE_SHIFT)
        SET_LAYER_DATASPACE = 67305472, // (0x403 << OPCODE_SHIFT)
        SET_LAYER_DISPLAY_FRAME = 67371008, // (0x404 << OPCODE_SHIFT)
        SET_LAYER_PLANE_ALPHA = 67436544, // (0x405 << OPCODE_SHIFT)
        SET_LAYER_SIDEBAND_STREAM = 67502080, // (0x406 << OPCODE_SHIFT)
        SET_LAYER_SOURCE_CROP = 67567616, // (0x407 << OPCODE_SHIFT)
        SET_LAYER_TRANSFORM = 67633152, // (0x408 << OPCODE_SHIFT)
        SET_LAYER_VISIBLE_REGION = 67698688, // (0x409 << OPCODE_SHIFT)
        SET_LAYER_Z_ORDER = 67764224, // (0x40a << OPCODE_SHIFT)
        SET_PRESENT_OR_VALIDATE_DISPLAY_RESULT = 67829760, // (0x40b << OPCODE_SHIFT)
    };

    virtual bool isRemote() const override { return false; }


    // @entry @callflow(next="*")
    virtual ::android::hardware::Return<void> registerCallback(const ::android::sp<IComposerCallback>& callback) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<uint32_t> getMaxVirtualDisplayCount() = 0;

    using createVirtualDisplay_cb = std::function<void(Error error, uint64_t display, ::android::hardware::graphics::common::V1_0::PixelFormat format)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> createVirtualDisplay(uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat formatHint, uint32_t outputBufferSlotCount, createVirtualDisplay_cb _hidl_cb) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> destroyVirtualDisplay(uint64_t display) = 0;

    using createLayer_cb = std::function<void(Error error, uint64_t layer)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> createLayer(uint64_t display, uint32_t bufferSlotCount, createLayer_cb _hidl_cb) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> destroyLayer(uint64_t display, uint64_t layer) = 0;

    using getActiveConfig_cb = std::function<void(Error error, uint32_t config)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getActiveConfig(uint64_t display, getActiveConfig_cb _hidl_cb) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> getClientTargetSupport(uint64_t display, uint32_t width, uint32_t height, ::android::hardware::graphics::common::V1_0::PixelFormat format, ::android::hardware::graphics::common::V1_0::Dataspace dataspace) = 0;

    using getColorModes_cb = std::function<void(Error error, const ::android::hardware::hidl_vec<::android::hardware::graphics::common::V1_0::ColorMode>& modes)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getColorModes(uint64_t display, getColorModes_cb _hidl_cb) = 0;

    using getDisplayAttribute_cb = std::function<void(Error error, int32_t value)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getDisplayAttribute(uint64_t display, uint32_t config, IComposerClient::Attribute attribute, getDisplayAttribute_cb _hidl_cb) = 0;

    using getDisplayConfigs_cb = std::function<void(Error error, const ::android::hardware::hidl_vec<uint32_t>& configs)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getDisplayConfigs(uint64_t display, getDisplayConfigs_cb _hidl_cb) = 0;

    using getDisplayName_cb = std::function<void(Error error, const ::android::hardware::hidl_string& name)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getDisplayName(uint64_t display, getDisplayName_cb _hidl_cb) = 0;

    using getDisplayType_cb = std::function<void(Error error, IComposerClient::DisplayType type)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getDisplayType(uint64_t display, getDisplayType_cb _hidl_cb) = 0;

    using getDozeSupport_cb = std::function<void(Error error, bool support)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getDozeSupport(uint64_t display, getDozeSupport_cb _hidl_cb) = 0;

    using getHdrCapabilities_cb = std::function<void(Error error, const ::android::hardware::hidl_vec<::android::hardware::graphics::common::V1_0::Hdr>& types, float maxLuminance, float maxAverageLuminance, float minLuminance)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getHdrCapabilities(uint64_t display, getHdrCapabilities_cb _hidl_cb) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> setClientTargetSlotCount(uint64_t display, uint32_t clientTargetSlotCount) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> setActiveConfig(uint64_t display, uint32_t config) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> setColorMode(uint64_t display, ::android::hardware::graphics::common::V1_0::ColorMode mode) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> setPowerMode(uint64_t display, IComposerClient::PowerMode mode) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> setVsyncEnabled(uint64_t display, IComposerClient::Vsync enabled) = 0;

    // @callflow(next="*")
    virtual ::android::hardware::Return<Error> setInputCommandQueue(const ::android::hardware::MQDescriptorSync<uint32_t>& descriptor) = 0;

    using getOutputCommandQueue_cb = std::function<void(Error error, const ::android::hardware::MQDescriptorSync<uint32_t>& descriptor)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> getOutputCommandQueue(getOutputCommandQueue_cb _hidl_cb) = 0;

    using executeCommands_cb = std::function<void(Error error, bool outQueueChanged, uint32_t outLength, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& outHandles)>;
    // @callflow(next="*")
    virtual ::android::hardware::Return<void> executeCommands(uint32_t inLength, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& inHandles, executeCommands_cb _hidl_cb) = 0;

    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    virtual ::android::hardware::Return<void> ping() override;

    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;
    // cast static functions
    static ::android::hardware::Return<::android::sp<IComposerClient>> castFrom(const ::android::sp<IComposerClient>& parent, bool emitError = false);
    static ::android::hardware::Return<::android::sp<IComposerClient>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    static const char* descriptor;

    static ::android::sp<IComposerClient> tryGetService(const std::string &serviceName="default", bool getStub=false);
    static ::android::sp<IComposerClient> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    static ::android::sp<IComposerClient> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    static ::android::sp<IComposerClient> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    static ::android::sp<IComposerClient> getService(const std::string &serviceName="default", bool getStub=false);
    static ::android::sp<IComposerClient> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    static ::android::sp<IComposerClient> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    static ::android::sp<IComposerClient> getService(bool getStub) { return getService("default", getStub); }
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

constexpr int32_t operator|(const IComposerClient::Attribute lhs, const IComposerClient::Attribute rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposerClient::Attribute rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposerClient::Attribute lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposerClient::Attribute lhs, const IComposerClient::Attribute rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposerClient::Attribute rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposerClient::Attribute lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposerClient::Attribute e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposerClient::Attribute e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposerClient::Attribute>(int32_t o);

std::string toString(IComposerClient::Attribute o);

constexpr uint32_t operator|(const IComposerClient::DisplayRequest lhs, const IComposerClient::DisplayRequest rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}

constexpr uint32_t operator|(const uint32_t lhs, const IComposerClient::DisplayRequest rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}

constexpr uint32_t operator|(const IComposerClient::DisplayRequest lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}

constexpr uint32_t operator&(const IComposerClient::DisplayRequest lhs, const IComposerClient::DisplayRequest rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}

constexpr uint32_t operator&(const uint32_t lhs, const IComposerClient::DisplayRequest rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}

constexpr uint32_t operator&(const IComposerClient::DisplayRequest lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}

constexpr uint32_t &operator|=(uint32_t& v, const IComposerClient::DisplayRequest e) {
    v |= static_cast<uint32_t>(e);
    return v;
}

constexpr uint32_t &operator&=(uint32_t& v, const IComposerClient::DisplayRequest e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
std::string toString(uint32_t o);
template<>
std::string toString<IComposerClient::DisplayRequest>(uint32_t o);

std::string toString(IComposerClient::DisplayRequest o);

constexpr uint32_t operator|(const IComposerClient::LayerRequest lhs, const IComposerClient::LayerRequest rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}

constexpr uint32_t operator|(const uint32_t lhs, const IComposerClient::LayerRequest rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}

constexpr uint32_t operator|(const IComposerClient::LayerRequest lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}

constexpr uint32_t operator&(const IComposerClient::LayerRequest lhs, const IComposerClient::LayerRequest rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}

constexpr uint32_t operator&(const uint32_t lhs, const IComposerClient::LayerRequest rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}

constexpr uint32_t operator&(const IComposerClient::LayerRequest lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}

constexpr uint32_t &operator|=(uint32_t& v, const IComposerClient::LayerRequest e) {
    v |= static_cast<uint32_t>(e);
    return v;
}

constexpr uint32_t &operator&=(uint32_t& v, const IComposerClient::LayerRequest e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
std::string toString(uint32_t o);
template<>
std::string toString<IComposerClient::LayerRequest>(uint32_t o);

std::string toString(IComposerClient::LayerRequest o);

constexpr int32_t operator|(const IComposerClient::PowerMode lhs, const IComposerClient::PowerMode rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposerClient::PowerMode rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposerClient::PowerMode lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposerClient::PowerMode lhs, const IComposerClient::PowerMode rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposerClient::PowerMode rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposerClient::PowerMode lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposerClient::PowerMode e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposerClient::PowerMode e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposerClient::PowerMode>(int32_t o);

std::string toString(IComposerClient::PowerMode o);

constexpr int32_t operator|(const IComposerClient::Vsync lhs, const IComposerClient::Vsync rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposerClient::Vsync rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposerClient::Vsync lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposerClient::Vsync lhs, const IComposerClient::Vsync rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposerClient::Vsync rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposerClient::Vsync lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposerClient::Vsync e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposerClient::Vsync e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposerClient::Vsync>(int32_t o);

std::string toString(IComposerClient::Vsync o);

constexpr int32_t operator|(const IComposerClient::BlendMode lhs, const IComposerClient::BlendMode rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposerClient::BlendMode rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposerClient::BlendMode lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposerClient::BlendMode lhs, const IComposerClient::BlendMode rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposerClient::BlendMode rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposerClient::BlendMode lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposerClient::BlendMode e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposerClient::BlendMode e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposerClient::BlendMode>(int32_t o);

std::string toString(IComposerClient::BlendMode o);

constexpr int32_t operator|(const IComposerClient::Composition lhs, const IComposerClient::Composition rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposerClient::Composition rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposerClient::Composition lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposerClient::Composition lhs, const IComposerClient::Composition rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposerClient::Composition rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposerClient::Composition lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposerClient::Composition e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposerClient::Composition e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposerClient::Composition>(int32_t o);

std::string toString(IComposerClient::Composition o);

constexpr int32_t operator|(const IComposerClient::DisplayType lhs, const IComposerClient::DisplayType rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposerClient::DisplayType rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposerClient::DisplayType lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposerClient::DisplayType lhs, const IComposerClient::DisplayType rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposerClient::DisplayType rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposerClient::DisplayType lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposerClient::DisplayType e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposerClient::DisplayType e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposerClient::DisplayType>(int32_t o);

std::string toString(IComposerClient::DisplayType o);

constexpr int32_t operator|(const IComposerClient::HandleIndex lhs, const IComposerClient::HandleIndex rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposerClient::HandleIndex rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposerClient::HandleIndex lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposerClient::HandleIndex lhs, const IComposerClient::HandleIndex rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposerClient::HandleIndex rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposerClient::HandleIndex lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposerClient::HandleIndex e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposerClient::HandleIndex e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposerClient::HandleIndex>(int32_t o);

std::string toString(IComposerClient::HandleIndex o);

std::string toString(const IComposerClient::Rect&);

bool operator==(const IComposerClient::Rect&, const IComposerClient::Rect&);

bool operator!=(const IComposerClient::Rect&, const IComposerClient::Rect&);

std::string toString(const IComposerClient::FRect&);

bool operator==(const IComposerClient::FRect&, const IComposerClient::FRect&);

bool operator!=(const IComposerClient::FRect&, const IComposerClient::FRect&);

std::string toString(const IComposerClient::Color&);

bool operator==(const IComposerClient::Color&, const IComposerClient::Color&);

bool operator!=(const IComposerClient::Color&, const IComposerClient::Color&);

constexpr int32_t operator|(const IComposerClient::Command lhs, const IComposerClient::Command rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const int32_t lhs, const IComposerClient::Command rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}

constexpr int32_t operator|(const IComposerClient::Command lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}

constexpr int32_t operator&(const IComposerClient::Command lhs, const IComposerClient::Command rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const int32_t lhs, const IComposerClient::Command rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}

constexpr int32_t operator&(const IComposerClient::Command lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}

constexpr int32_t &operator|=(int32_t& v, const IComposerClient::Command e) {
    v |= static_cast<int32_t>(e);
    return v;
}

constexpr int32_t &operator&=(int32_t& v, const IComposerClient::Command e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
std::string toString(int32_t o);
template<>
std::string toString<IComposerClient::Command>(int32_t o);

std::string toString(IComposerClient::Command o);

std::string toString(const ::android::sp<IComposerClient>&);

}  // namespace V2_1
}  // namespace composer
}  // namespace graphics
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMPOSER_V2_1_ICOMPOSERCLIENT_H
