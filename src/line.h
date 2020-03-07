#pragma once
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>  
using namespace std;

class Line {
public:
	double a, b;//y=ax+b
	bool aNotExist;//consider x=t
	int t;
	Line(int x1, int y1, int x2, int y2);
};