#!/bin/bash 
#This script will install SettingsConfig library

#build
clear
sudo rm -rf build
mkdir build 
cd build
$echo pwd
echo "prepare make configs..."
# $1 can be -DWITH_LOGS=OFF
cmake $1 ..
echo "build SettingsConfig project..."
make
echo "install SettingsConfig library..."
sudo make install

echo "build examples..."
cd ../examples
sudo rm -rf build
mkdir build
cd build
$echo pwd
cmake ..
make
