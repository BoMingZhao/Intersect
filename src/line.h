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

Line::Line(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		aNotExist = true;
		t = x1;
		a = 0;//delete warning
		b = 0;//delete warning
	}
	else {
		aNotExist = false;
		a = (y1 - y2) / (x1 - x2);
		b = y1 - a * x1;
		t = 0;//delete warning
	}
}