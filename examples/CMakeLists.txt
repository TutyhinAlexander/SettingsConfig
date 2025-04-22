cmake_minimum_required(VERSION 3.25)
project(SettingsConfigTest VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SettingsConfigTest SettingsConfigTest.cpp)

find_package(SettingsConfig REQUIRED)
find_package(Logger REQUIRED)
find_package(OpenCV REQUIRED)
find_package(libconfig REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS})

target_link_libraries(SettingsConfigTest PUBLIC DebugTools::Logger Tools::SettingsConfig libconfig::config++ ${OpenCV_LIBS})
