Openpilot on termux/android-8.1 install notes (bleeding edge, pre-alpha quality)
================================================================================

TODO
====
  * UI: OpenGL ES graphics is not shown on top (spinner works)
  * waze and spotify apk patching fails
  * visiond, gpsd, sensord and other binary modules run but are currently untested
  * _hierarchy.so does not load (using python module as workaround)

INSTALL/PORT NOTES
==================
  * root android using twrp and supersu
    currently required for libusb and ui, will wipe the phone
  * install termux app from play store
  * confirm that su works in termux (grant by default in supersu, FIXME)
  * install openssh and screen
    apt install openssh screen

  * add your ssh public key to .ssh/authorized_keys (eg. copy-paste from e-mail)
  * start sshd server on the phone
```
sshd
```
  * ssh into phone
    ssh ip -p 8022
  * start screen session
    screen

  * install dev tools
    apt install git python2-dev autoconf automake libtool clang pkg-config curl

- set python2 as default
  cd $PREFIX/bin
  ln -sf python2 python
  ln -sf pip2 pip

- add its-pointless repo
  curl -O https://its-pointless.github.io/setup-pointless-repo.sh
  bash setup-pointless-repo.sh
  apt install python2-scipy

- fork commaai openpilot repo on github
- clone your forked repo to /data
  git clone https://github.com/<username>/openpilot.git
  git submodule update --init --recursive

- configure upstream url for op repo
  cd openpilot
  git remote add upstream https://github.com/commaai/openpilot.git
  git remote -v

- optional: build android aosp image (check howto in the end) to get media and graphics hidl headers
- copy android hidl headers to phone
  scp -P 8022 -r hidl ip:openpilot/phonelibs/

- download and compile capnroto c and java plugins
  cd ~/openpilot
  export PYTHONPATH=$PWD

  cd phonelibs
  curl -O https://capnproto.org/capnproto-c++-0.6.1.tar.gz
  tar zxf capnproto-c++-0.6.1.tar.gz
  cd capnproto-c++-0.6.1
  ./configure --prefix=$PREFIX TMPDIR=$PREFIX/tmp
  make -j4 check
  make install
  cd ..

- install capnproto-c
  cd c-capnproto
  git submodule update --init --recursive
  autoreconf -f -i -s
  ./configure --prefix=$PREFIX TMPDIR=$PREFIX/tmp
  make -j8
  make check
  make install
  cd ..

- install capnproto-java
  cd capnproto-java
  make -j8
  cp capnpc-java $PREFIX/bin

- install dependencies for compiling python modules
  cd ~/openpilot
  apt install freetype-dev libpng-dev boost-dev libcrypt-dev libffi-dev libpng-dev libzmq-dev libuuid-dev
  pip install -r requirements_openpilot.txt

- build libusb and libczmq in https://github.com/termux/termux-packages docker container
  https://wiki.termux.com/wiki/Package_Management#Community_Repositories
- copy libusb and libczmq debs to phone
  scp -P 8022 -r deb/ 192.168.43.1:openpilot

- install libusb and libusb-dev
  cd ~/openpilot/deb
  dpkg -i *.deb

- fix openpilot modules compliation configuration
  cd cereal
  make
  
  cd boardd

- fix Makefiles
- comment out -lgnustl_shared
- add
  PREFIX = /data/data/com.termux/files/usr
  -L$(PREFIX)/lib \
  -I$(PREFIX)/include \

- add termux include and library directories
  -I$(PREFIX)/include
  -I$(PREFIX)/include/libusb-1.0


  -L$(PREFIX)/lib

  s/-l:libcapn.a -l:libcapnp.a -l:libkj.a/-lcapnp_c -lcapnp -lkj
  s/-l:libczmq.a -l:libzmq.a/-lczmq -lzmq

  cd ..
  export PYTHONPATH=/data/data/com.termux/files/home/openpilot
  cd can
  make -j8
  cd ../controls/lib/longitudinal_mpc/
  make -j8
  cd ../lateral_mpc/
  make -j8
  cd ../../debug/getframes
  make -j8
  cd ../logcatd
  make -j8
  cd ../orbd
  temporarily comment out ioctl in /data/data/com.termux/files/usr/include/bits/ioctl.h
  make -j8
  cd ../proclogd
  make -j8
  cd ../ui
  patch Makefile
    add missing #include <EGL/egl.h>
  make -j8
  cd spinner
    create Makefile
    add missing #include <EGL/egl.h>
  make -j8

- ui/spinner libunwind missing symbols fix
  LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/system/lib64 ./spinner 'testing 1-2-3'

- pre-build openpilot
  make

- fix #$PREFIX/bin/bash in *.sh

- run openpilot
  ./launch_openpilot.sh

Build Android AOSP 8.1 image for Nexus 5X
=========================================

  * create cloud vm (16 core, 30GB RAM, 10GB ubuntu 16.04, 300GB SSD)
  * add ssh public key
    sudo fdisk /dev/sdb
    sudo mkfs.ext4 /dev/sdb1
    sudo mkdir /data
    sudo mount /dev/sdb1 /data
    sudo chown martin /data
    cd /data

  * https://source.android.com/setup/build/initializing

    mkdir aosp
    cd aosp
    curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
    chmod a+x ~/bin/repo
    export PATH=~/bin:$PATH
    git config --global user.name "Martin Lillepuu"
    git config --global user.email "martin@mlp.ee"
    repo init -u https://android.googlesource.com/platform/manifest -b android-8.1.0_r27
   repo sync

  * https://source.android.com/setup/build/downloading#verifying-git-tags
    gpg --import

  * https://source.android.com/setup/build/building
    mkdir ../drivers
    cd ../drivers
    wget https://dl.google.com/dl/android/aosp/lge-bullhead-opm4.171019.016.a1-6ca0caeb.tgz
    wget https://dl.google.com/dl/android/aosp/qcom-bullhead-opm4.171019.016.a1-adcef468.tgz
    tar xvzf lge-bullhead-opm4.171019.016.a1-6ca0caeb.tgz
    tar xvzf qcom-bullhead-opm4.171019.016.a1-adcef468.tgz
    cd ../aosp
    echo "I ACCEPT" | ../drivers/extract-lge-bullhead.sh
    echo "I ACCEPT" | ../drivers/extract-qcom-bullhead.sh
    make clobber
   . build/envsetup.sh

   lunch aosp_arm-eng
   make -j16
   
  * build hidl-gen and generate hidl headers
    https://android.googlesource.com/platform/system/tools/hidl/+/master/README.md
