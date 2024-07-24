
m_define_module(thread)

target_sources(${v_project}
	PUBLIC 
		FILE_SET v_module_files TYPE CXX_MODULES FILES
		"thread_interface.cppm"
		"thread.cppm"

	PRIVATE
		"thread.cpp"
)

target_link_libraries(${v_project}
	PRIVATE
		"std"
		"${v_package_namespace}task"
)