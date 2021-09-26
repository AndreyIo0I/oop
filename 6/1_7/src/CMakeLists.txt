project(oop)

set(HEADER_FILES
        CHttpUrl.h
        CUrlParsingError.h)

set(SOURCE_FILES
        CHttpUrl.cpp
        CUrlParsingError.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})