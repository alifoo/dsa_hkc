cmake_minimum_required(VERSION 3.10)

project(DsaHkc VERSION 1.0 LANGUAGES C)

include(GNUInstallDirs) # lib, include, share etc...

# 1. This creates a static library (libhacking_club_c.a)
add_library(dsa_hkc STATIC
    src/hashtable.c
)

add_library(DsaHkc::dsa_hkc ALIAS dsa_hkc)

# 2. This specifies the public header file location so CMAKE knows
target_include_directories(dsa_hkc
    PUBLIC
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
      ${PROJECT_SOURCE_DIR}/src
)

# 3. This defines the executable (create an executable named test from main.c)
#add_executable(myprogram main.c)
# 4. This links the lib to the executable.
#target_link_libraries(myprogram PRIVATE dsa_hkc)

# 5. Generate a version file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/DsaHkcConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# 6. Define what to export and where to install
install(TARGETS dsa_hkc
    EXPORT DsaHkcTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(FILES include/dsa_hkc.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# 7. Install the export file with our lib location
install(EXPORT DsaHkcTargets
    FILE DsaHkcTargets.cmake
    NAMESPACE DsaHkc::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DsaHkc
)

# 8. Install the config and version files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/DsaHkcConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DsaHkc
)

configure_package_config_file(
    "DsaHkcConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/DsaHkcConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DsaHkc
)

# This installs the file we just generated
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/DsaHkcConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DsaHkc
)
