function(f_subdir _v_result _v_base_dir)
    set({_v_result} "")

    file(GLOB _v_children LIST_DIRECTORIES true RELATIVE "${_v_base_dir}" "${_v_base_dir}/*")
    foreach(_v_child IN LISTS _v_children)
        if(IS_DIRECTORY "${_v_base_dir}/${_v_child}")
            list(APPEND ${_v_result} "${_v_child}")
        endif ()
    endforeach()

    return(PROPAGATE ${_v_result})
endfunction()