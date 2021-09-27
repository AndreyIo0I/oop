project(oop)

set(HEADER_FILES
        FindMax.h
        )

set(SOURCE_FILES
        FindMax.cpp
        )

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})