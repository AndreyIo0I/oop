project(oop)

set(HEADER_FILES TVSet.h RemoteControl.cpp)

set(SOURCE_FILES TVSet.cpp RemoteControl.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})