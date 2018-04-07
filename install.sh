#!/bin/bash

cores=`grep --count ^processor /proc/cpuinfo`

mkdir build; cd build/
cmake .. && make -j $cores
sudo make install
cd ../

sudo cp /usr/local/lib/libtmx-loader.so /usr/lib/
sudo cp /usr/local/lib/libpugi.so /usr/lib/