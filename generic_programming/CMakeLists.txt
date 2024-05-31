SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

FOREACH (subdir ${SUBDIRS})
    IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
        add_subdirectory(${subdir})
        MESSAGE(STATUS "Adding demo ${subdir}...")
    ENDIF ()
ENDFOREACH ()