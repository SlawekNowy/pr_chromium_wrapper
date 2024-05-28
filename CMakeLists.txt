include(${CMAKE_SOURCE_DIR}/cmake/pr_common.cmake)

set(PROJ_NAME pr_chromium_wrapper)
pr_add_library(${PROJ_NAME} SHARED)

pr_add_headers(${PROJ_NAME} "include/")
pr_add_sources(${PROJ_NAME} "src/")

pr_add_external_dependency(${PROJ_NAME} chromium LIBRARY PUBLIC)
pr_add_external_dependency(${PROJ_NAME} libcef_dll_wrapper LIBRARY PUBLIC)

if(MSVC)
	target_compile_definitions(${PROJ_NAME} PRIVATE -D_UNICODE -DUNICODE)
	target_compile_options(${PROJ_NAME} PRIVATE "/MT")
endif()

add_subdirectory("subprocess")
pr_add_dependency(pr_chromium_subprocess ${PROJ_NAME} TARGET PUBLIC)

pr_finalize(${PROJ_NAME})
