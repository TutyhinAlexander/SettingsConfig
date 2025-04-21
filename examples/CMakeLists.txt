cmake_minimum_required(VERSION 3.25)
project(SettingsConfigTest VERSION 1.0)

add_executable(SettingsConfigTest SettingsConfigTest.cpp)

find_package(SettingsConfig REQUIRED)
find_package(Logger REQUIRED)
find_package(libconfig REQUIRED)

target_link_libraries(SettingsConfigTest PUBLIC DebugTools::Logger Tools::SettingsConfig libconfig::config++)
