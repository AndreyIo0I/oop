add_executable(tests CountWordOccurrences_tests.cpp)
target_compile_definitions(tests PUBLIC TEST_RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(tests src_lib)