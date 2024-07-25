
m_define_test(unit_tests)

# add unit test files
aux_source_directory(. v_source_files)
target_sources(${v_project}
	PRIVATE
		${v_source_files}
)

# link gtest
find_package(GTest CONFIG REQUIRED)
target_link_libraries(${v_project}
		PRIVATE
		GTest::gtest_main
)

# link all modules to be tested
target_link_libraries(${v_project}
	PRIVATE
)