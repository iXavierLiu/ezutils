
m_define_module(thread_pool)

target_sources(${v_project}
	PUBLIC 
		FILE_SET v_module_files TYPE CXX_MODULES FILES
		"IThreadPool.cppm"
		"ThreadPool.cppm"

	PRIVATE
		"ThreadPool.cpp"
)

target_link_libraries(${v_project}
		PRIVATE
		"${v_package_namespace}thread"
)