CC = clang
CXX = clang++


PHONELIBS = ../../../phonelibs

WARN_FLAGS = -Werror=implicit-function-declaration \
             -Werror=incompatible-pointer-types \
             -Werror=int-conversion \
             -Werror=return-type \
             -Werror=format-extra-args

CFLAGS = -std=gnu11 -g -fPIC -O2 $(WARN_FLAGS)
CXXFLAGS = -std=c++14 -g -fPIC -O2 $(WARN_FLAGS)

NANOVG_FLAGS = -I$(PHONELIBS)/nanovg

OPENGL_LIBS = -lGLESv3

FRAMEBUFFER_LIBS = -lutils -lgui -lEGL

OBJS = spinner.o \
       ../../common/glutil.o \
       ../../common/visionipc.o \
       ../../common/framebuffer.o \
       ../../common/params.o \
       ../../common/util.o \
       ../../common/touch.o \
       $(PHONELIBS)/nanovg/nanovg.o 

DEPS := $(OBJS:.o=.d)

all: spinner

spinner: $(OBJS)
	@echo "[ LINK ] $@"
	$(CXX) -fPIC -o '$@' $^ \
	      $(FRAMEBUFFER_LIBS) \
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
          -c -o '$@' '$<'

.PHONY: clean
clean:
	rm -f spinner $(OBJS) $(DEPS)

-include $(DEPS)
