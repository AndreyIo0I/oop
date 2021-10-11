project(oop)

set(HEADER_FILES Dictionary.h)

set(SOURCE_FILES Dictionary.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})