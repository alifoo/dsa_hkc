cmake_minimum_required(VERSION 3.10)

project(DsaHkc VERSION 1.0 LANGUAGES C)

# 1. This creates a static library (libhacking_club_c.a)
add_library(dsa_hkc STATIC
    src/hashtable.c
)

# 2. This specifies the public header file location so CMAKE knows
#target_include_directories(dsa_hkc PUBLIC
#    ${PROJECT_SOURCE_DIR}/include
#)

# 3. This defines the executable (create an executable named test from
# main.c
#add_executable(myprogram main.c)

# 4. This links the lib to the executable. It tells the program that it needs
# to link against hacking_club_c_lib. CMake will handle all the compiler flags
# for you.
#target_link_libraries(myprogram PRIVATE dsa_hkc)

# Optional: add an install rule to make it distributable
install(TARGETS dsa_hkc DESTINATION lib)
install(FILES include/dsa_hkc.h DESTINATION include)

message(STATUS "Configuration complete, run 'make' to build.")
