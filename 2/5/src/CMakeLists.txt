project(oop)

set(HEADER_FILES ParseURL.h)

set(SOURCE_FILES ParseURL.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})