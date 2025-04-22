cmake_minimum_required(VERSION 3.25)
project(SettingsConfig VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

find_package(Logger REQUIRED)
find_package(OpenCV REQUIRED)
find_package(libconfig REQUIRED)

target_link_libraries(SettingsConfig PUBLIC DebugTools::Logger libconfig::config++ ${OpenCV_LIBS})
