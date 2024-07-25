
f_subdir(_v_subdirs "${CMAKE_CURRENT_SOURCE_DIR}")
foreach (_v_subdir IN ITEMS ${_v_subdirs})
    add_subdirectory("${_v_subdir}")
endforeach ()

# generate `all` target links all modules
m_configure_project_env(all)
add_library(${v_project} INTERFACE)
add_library(${v_project_alias} ALIAS ${v_project})
foreach (_v_subdir IN ITEMS ${_v_subdirs})
    set(_v_module_name "${v_package_namespace}${_v_subdir}")
    target_link_libraries(${v_project} INTERFACE ${_v_module_name})
endforeach()