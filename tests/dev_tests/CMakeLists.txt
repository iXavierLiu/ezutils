
m_define_test(dev_tests)

# add unit test files
target_sources(${v_project}
    PRIVATE
        "main.cpp"
)

# link all modules to be tested
target_link_libraries(${v_project}
    PRIVATE
        "${v_package_namespace}thread_pool"
)