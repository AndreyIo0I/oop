project(oop)

set(HEADER_FILES Car.h ConsoleControl.cpp)

set(SOURCE_FILES Car.cpp ConsoleControl.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})