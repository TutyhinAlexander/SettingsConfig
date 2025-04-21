cmake_minimum_required(VERSION 3.25)
project(SettingsConfig VERSION 1.0)

add_subdirectory(src)

find_package(Logger REQUIRED)
find_package(libconfig REQUIRED)

target_link_libraries(SettingsConfig PUBLIC DebugTools::Logger libconfig::config++)
