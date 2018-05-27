CC = clang
CXX = clang++


PHONELIBS = ../../phonelibs

WARN_FLAGS = -Werror=implicit-function-declaration \
             -Werror=incompatible-pointer-types \
             -Werror=int-conversion \
             -Werror=return-type \
             -Werror=format-extra-args

CFLAGS = -std=gnu11 -g -fPIC -O2 $(WARN_FLAGS)
CXXFLAGS = -std=c++14 -g -fPIC -O2 $(WARN_FLAGS)

ZMQ_FLAGS = -I$(PHONELIBS)/zmq/aarch64/include
ZMQ_LIBS = -L$(PHONELIBS)/zmq/aarch64/lib \
           -lczmq -lzmq \
           #-lgnustl_shared

CEREAL_CFLAGS = -I$(PHONELIBS)/capnp-c/include
CEREAL_LIBS = -L$(PHONELIBS)/capnp-c/aarch64/lib -lcapnp -lcapnp_c
CEREAL_OBJS = ../../cereal/gen/c/log.capnp.o

NANOVG_FLAGS = -I$(PHONELIBS)/nanovg
JSON_FLAGS = -I$(PHONELIBS)/json/src

OPENGL_LIBS = -lGLESv3

FRAMEBUFFER_LIBS = -lutils -lgui -lEGL

OBJS = ui.o \
       ../common/glutil.o \
       ../common/visionipc.o \
       ../common/framebuffer.o \
       ../common/params.o \
       ../common/util.o \
       ../common/touch.o \
       ../common/swaglog.o \
       $(PHONELIBS)/nanovg/nanovg.o \
       $(PHONELIBS)/json/src/json.o \
       $(CEREAL_OBJS)

DEPS := $(OBJS:.o=.d)

all: ui

ui: $(OBJS)
	@echo "[ LINK ] $@"
	$(CXX) -fPIC -o '$@' $^ \
	      $(FRAMEBUFFER_LIBS) \
	      $(CEREAL_LIBS) \
	      $(ZMQ_LIBS) \
        -L/system/vendor/lib64 \
        -L/system/lib64 \
        -lhardware \
        $(OPENGL_LIBS) \
        -lcutils -lm -llog -llzma

%.o: %.cc
	@echo "[ CXX ] $@"
	$(CXX) $(CXXFLAGS) -MMD \
           -Iinclude -I.. -I../.. \
           -I$(PHONELIBS)/android_frameworks_native/include \
           -I$(PHONELIBS)/android_frameworks_native/libs/nativebase/include \
           -I$(PHONELIBS)/android_frameworks_native/libs/nativewindow/include \
           -I$(PHONELIBS)/android_system_core/include \
           -I$(PHONELIBS)/android_system_core/base/include \
           -I$(PHONELIBS)/android_system_core/libcutils/include \
           -I$(PHONELIBS)/android_system_core/libsystem/include \
           -I$(PHONELIBS)/android_system_libhidl/base/include \
           -I$(PHONELIBS)/android_system_libhidl/transport/token/1.0/utils/include \
           -I$(PHONELIBS)/hidl/graphics/bufferqueue/1.0/android.hardware.graphics.bufferqueue@1.0_genc++_headers/gen \
           -I$(PHONELIBS)/hidl/base/android.hidl.base@1.0_genc++_headers/gen \
           -I$(PHONELIBS)/hidl/manager/android.hidl.manager@1.0_genc++_headers/gen \
           -I$(PHONELIBS)/hidl/graphics/common/1.0/android.hardware.graphics.common@1.0_genc++_headers/gen \
           -I$(PHONELIBS)/hidl/media/1.0/android.hardware.media@1.0_genc++_headers/gen \
           -I$(PHONELIBS)/android_hardware_libhardware/include \
           -c -o '$@' '$<'

%.o: %.c
	@echo "[ CC ] $@"
	$(CC) $(CFLAGS) -MMD \
          -I.. -I../.. \
          -I$(PHONELIBS)/android_system_core/libcutils/include \
          -I$(PHONELIBS)/android_system_core/libsystem/include \
          -I$(PHONELIBS)/android_system_core/libutils/include \
          -I$(PHONELIBS)/android_hardware_libhardware/include \
          $(NANOVG_FLAGS) \
          $(ZMQ_FLAGS) \
          $(CEREAL_CFLAGS) \
          $(JSON_FLAGS) \
          -c -o '$@' '$<'

.PHONY: clean
clean:
	rm -f ui $(OBJS) $(DEPS)

-include $(DEPS)
