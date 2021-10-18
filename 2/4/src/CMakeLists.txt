project(oop)

set(HEADER_FILES PrimeNumbers.h)

set(SOURCE_FILES PrimeNumbers.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})