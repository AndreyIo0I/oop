project(oop)

set(HEADER_FILES HtmlEncode.h)

set(SOURCE_FILES HtmlEncode.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})