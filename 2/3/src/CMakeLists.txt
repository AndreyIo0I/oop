project(oop)

set(HEADER_FILES CountWordOccurrences.h)

set(SOURCE_FILES CountWordOccurrences.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})