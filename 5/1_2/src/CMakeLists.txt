project(oop)

set(HEADER_FILES Vector.h)

set(SOURCE_FILES Vector.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})