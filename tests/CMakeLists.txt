option(BUILD_ALL_TESTS "Builds all of tests." OFF)
option(BUILD_UNIT_TESTS "Builds unit tests." OFF)
option(BUILD_DEV_TESTS "Builds development tests." OFF)

if(BUILD_ALL_TESTS)
    set(BUILD_UNIT_TESTS ON)
    set(BUILD_DEV_TESTS ON)
endif()

if(BUILD_UNIT_TESTS)
    add_subdirectory("unit_tests")
endif()

if(BUILD_DEV_TESTS)
    add_subdirectory("dev_tests")
endif()