CC = clang
CXX = clang++

PHONELIBS = ../../phonelibs
BASEDIR = ../..
PREFIX = /data/data/com.termux/files/usr

WARN_FLAGS = -Werror=implicit-function-declaration \
             -Werror=incompatible-pointer-types \
             -Werror=int-conversion \
             -Werror=return-type \
             -Werror=format-extra-args

CFLAGS = -std=gnu11 -g -fPIC -O2 $(WARN_FLAGS)
CXXFLAGS = -std=c++14 -g -fPIC -O2 $(WARN_FLAGS)

ZMQ_FLAGS = -I$(PHONELIBS)/zmq/aarch64/include -I$(PREFIX)/include
ZMQ_LIBS = -L$(PHONELIBS)/zmq/aarch64/lib \
	   -L$(PREFIX)/lib \
           -lczmq -lzmq

.PHONY: all
all: logcatd

include ../common/cereal.mk

OBJS = logcatd.o \
       $(CEREAL_OBJS)

DEPS := $(OBJS:.o=.d)

logcatd: $(OBJS)
	@echo "[ LINK ] $@"
	$(CXX) -fPIC -o '$@' $^ \
            $(CEREAL_LIBS) \
            $(ZMQ_LIBS) \
            -llog

%.o: %.cc
	@echo "[ CXX ] $@"
	$(CXX) $(CXXFLAGS) \
           -I$(PHONELIBS)/android_system_core/include \
           $(CEREAL_CXXFLAGS) \
           $(ZMQ_FLAGS) \
           -I../ \
           -I../../ \
           -c -o '$@' '$<'

.PHONY: clean
clean:
	rm -f logcatd $(OBJS) $(DEPS)

-include $(DEPS)
