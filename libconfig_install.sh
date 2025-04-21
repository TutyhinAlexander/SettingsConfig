#!/bin/bash 
#This script will install libconfig library

# create folder for libconfig library
mkdir -p ~/libs/libconfig
cd ~/libs/libconfig

git clone https://github.com/hyperrealm/libconfig.git .

#build & install library
mkdir build 
cd build
$echo pwd
echo "prepare make configs..."
cmake ..
echo "build libconfig project..."
make
echo "install libconfig library..."
sudo make install
