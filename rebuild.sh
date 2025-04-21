#!/bin/bash 
#This script will install SettingsConfig library

#build
sudo rm -rf build
mkdir build 
cd build
$echo pwd
echo "prepare make configs..."
cmake ..
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
