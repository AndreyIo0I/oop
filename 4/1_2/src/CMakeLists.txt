project(oop)

set(HEADER_FILES
        figures/CPoint.h
        figures/CLineSegment.h
        figures/CTriangle.h
        figures/CRectangle.h
        figures/CCircle.h
        utils/print.h)

set(SOURCE_FILES
        figures/CPoint.cpp
        figures/CLineSegment.cpp
        figures/CTriangle.cpp
        figures/CRectangle.cpp
        figures/CCircle.cpp
        utils/print.cpp)

add_library(src_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})