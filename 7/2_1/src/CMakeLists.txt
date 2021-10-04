project(oop)

set(HEADER_FILES
        CMyArray.h
        )

set(SOURCE_FILES
        CMyArray.cpp
        )

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})