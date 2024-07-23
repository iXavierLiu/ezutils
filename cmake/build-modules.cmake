macro(m_define_module _v_module_name)

	set(v_module_name "${_v_module_name}")
	set(v_project "${v_package_name}_${v_module_name}")
	set(v_project_alias "${v_package_namespace}${v_module_name}")

	project(${v_project} LANGUAGES CXX)

	add_library(${v_project} STATIC)
	add_library(${v_project_alias} ALIAS ${v_project})

	target_compile_options(${v_project} PUBLIC 
		"$<$<C_COMPILER_ID:MSVC>:/utf-8>"
		"$<$<CXX_COMPILER_ID:MSVC>:/utf-8>"
	)

	target_compile_features(${v_project} PUBLIC
		cxx_std_20
	)
endmacro()
