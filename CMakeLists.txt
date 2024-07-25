cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

include("cmake/build-modules.cmake")

# root project name
set(v_package_name "ezutils")
# root project namespace
set(v_package_namespace "${v_package_name}::")

project(${v_package_name} LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(tests)
