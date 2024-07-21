cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

set(i_package_name "ezutils")
option(BUILD_TESTS "Builds all of tests." OFF)

project(${i_package_name} LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(tests)
