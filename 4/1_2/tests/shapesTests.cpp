#define CATCH_CONFIG_MAIN

#include <utils/readShapes.hpp>
#include <utils/minMax.hpp>
#include "catch.hpp"

using namespace std;

SCENARIO("Using shapes utils")
{
    WHEN("read shapes from empty input")
    {
        auto input = istringstream("");
        vector<shared_ptr<IShape>> shapes = ReadShapes(input);
        THEN("shapes are empty")
        {
            CHECK(shapes.empty());
        }
    }

    WHEN("read and print shapes")
    {
        auto input = istringstream("line 1 2 3 4 abcdef\ntriangle 10 0 20 0 30 30\n\ncircle 1 2 3 ffffff 123456\nrectangle 1.2 @ 3 0\nrectangle 1.2 2 3 0 987654");
        vector<shared_ptr<IShape>> shapes = ReadShapes(input);
        THEN("shapes are correct")
        {
            CHECK(shapes[0]->ToString() == "line segment: (1.000000, 2.000000) (3.000000, 4.000000) abcdef");
            CHECK(shapes[1]->ToString() == "triangle: (10.000000, 0.000000) (20.000000, 0.000000) (30.000000, 30.000000) 0 0");
            CHECK(shapes[2]->ToString() == "circle: (1.000000, 2.000000) 3.000000 ffffff 123456");
            CHECK(shapes[3]->ToString() == "rectangle: (1.200000, 2.000000) (3.000000, 0.000000) 987654 0");
        }
    }

    WHEN("work with shapes via interface")
    {
        vector<shared_ptr<IShape>> shapes;
        shapes.push_back(make_unique<CCircle>(1, 2, 3));
        shapes.push_back(make_unique<CRectangle>(1, 2, 2, 3));
        THEN("shapes are empty")
        {
            CHECK(GetMinPerimeterShape(shapes)->ToString() == "rectangle: (1.000000, 2.000000) (2.000000, 3.000000) 0 0");
            CHECK(GetMaxAreaShape(shapes)->ToString() == "circle: (1.000000, 2.000000) 3.000000 0 0");
        }
    }
}
