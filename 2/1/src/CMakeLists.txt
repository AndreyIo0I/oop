project(oop)

set(HEADER_FILES vectorBasics.h)

set(SOURCE_FILES vectorBasics.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})