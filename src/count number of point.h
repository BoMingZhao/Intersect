#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include "line.h"
#include "circle.h"

using namespace std;

class Calculate {
public:
    int caculate_line_line(Line l1, Line l2);
    int caculate_line_circle(Line l, Circle c);
    int caculate_circle_circle(Circle c1, Circle c2);
};