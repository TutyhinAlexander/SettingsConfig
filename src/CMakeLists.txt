add_library(SettingsConfig STATIC)
add_library(Tools::SettingsConfig ALIAS SettingsConfig)

target_compile_features(SettingsConfig PRIVATE cxx_std_17)
target_sources(SettingsConfig PRIVATE SettingsConfig.cpp SettingsWindow.cpp)
target_include_directories(SettingsConfig PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>")

## Installing
include(CMakePackageConfigHelpers)

install(
  TARGETS SettingsConfig 
  EXPORT SettingsConfigTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include
)

install(
  EXPORT SettingsConfigTargets
  FILE SettingsConfigTargets.cmake
  NAMESPACE Tools::
  DESTINATION lib/cmake/SettingsConfig
)
install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include/SettingsConfig 
  DESTINATION include
)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/SettingsConfigConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SettingsConfig
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    SettingsConfigConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
  FILES 
    "${CMAKE_CURRENT_BINARY_DIR}/SettingsConfigConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/SettingsConfigConfigVersion.cmake"
  DESTINATION lib/cmake/SettingsConfig
)
