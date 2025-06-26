#!/bin/bash 
#This script will install libconfig library

# create folder for libconfig library
mkdir -p ~/libs
cd ~/libs

sudo rm -rf libconfig
mkdir -p libconfig
cd libconfig

git clone https://github.com/hyperrealm/libconfig.git .
git reset e7e8dee409632f9be89febed88a9707159e20e75 --hard

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
