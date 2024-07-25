
macro(m_define_module _v_module_name)

	set(v_module_name "${_v_module_name}")
	set(v_project "${v_package_name}_${v_module_name}")
	set(v_project_alias "${v_package_namespace}${v_module_name}")

	project(${v_project} LANGUAGES CXX)

	add_library(${v_project} STATIC)
	add_library(${v_project_alias} ALIAS ${v_project})

	m_set_target_flags(${v_project})
endmacro()

macro(m_define_test _v_test_name)

	set(v_test_name "${_v_test_name}")
	set(v_project "${v_package_name}_${v_test_name}")
	set(v_project_alias "${v_package_namespace}${v_test_name}")

	project(${v_project} LANGUAGES CXX)

	add_executable(${v_project})
	add_executable(${v_project_alias} ALIAS ${v_project})

	m_set_target_flags(${v_project})
endmacro()

macro(m_set_target_flags _v_target_name)

	target_compile_options(${_v_target_name} PUBLIC
			"$<$<C_COMPILER_ID:MSVC>:/utf-8>"
			"$<$<CXX_COMPILER_ID:MSVC>:/utf-8>"
	)

	target_compile_features(${_v_target_name} PUBLIC
			cxx_std_20
	)
endmacro()