project(oop)

set(HEADER_FILES CHttpUrl.h)

set(SOURCE_FILES CHttpUrl.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})