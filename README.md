# SettingsConfig

Settings Config

## Description

Wrapper for libconfig library

## Dependencies
	
	Project uses `LinuxLogger`, `libconfig` so you need to install them first:
	
	https://github.com/TutyhinAlexander/LinuxLogger
	https://github.com/hyperrealm/libconfig
	

## Installation on Linux

### libconfig quick install

	```bash
	$ sh libconfig_install.sh
	```	
	
### SettingsConfig quick install

	```bash
	$ mkdir SettingsConfig
	$ cd SettingsConfig	
	$ git clone https://github.com/TutyhinAlexander/SettingsConfig.git .
	$ sh rebuild.sh
	```	


## Using This Project As A CMake Dependency

Add folowwing to your main `CMakeLists.txt`:

```cmake
find_package(SettingsConfig REQUIRED)

...
target_link_libraries(<Your project name> PUBLIC Tools::SettingsConfig)
```

## Using & Examples

See `SettingsConfigTest.cpp` for example of using SettingsConfig library

On a Linux system you should be able to compile this example with:

```cmake
mkdir build
cmake -B ./build .
cmake --build ./build
```	
