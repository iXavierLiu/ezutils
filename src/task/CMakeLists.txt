
m_define_module(task)

target_sources(${v_project}
	PUBLIC 
		FILE_SET v_module_files TYPE CXX_MODULES FILES
		"task_interface.cppm"
		"task.cppm"

	PRIVATE
		"task.cpp"
)
