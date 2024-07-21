cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

set(i_package_name "ezutils")
option(BUILD_TESTS "Builds all of tests." OFF)

project(${i_package_name}_test LANGUAGES CXX)
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE "main.cpp")

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

