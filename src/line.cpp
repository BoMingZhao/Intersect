#include <stack>
#include <vector>
#include <iostream>
#include "line.h"
#include <string>
using namespace std;

Line::Line(int x1, int y1, int x2, int y2) {
	x = 0;
	y = 0;
	A = (double)y2 - y1;
	B = (double)x1 - x2;
	C = (double)x2 * y1 - (double)x1 * y2;
	if (x1 == x2) {
		aNotExist = true;
		t = x1;
		a = 0;//delete warning
		b = 0;//delete warning
	}
	else {
		aNotExist = false;
		a = ((double)y1 - (double)y2) / ((double)x1 - (double)x2);
		b = y1 - a * x1;
		t = 0;//delete warning
	}
}

Line::Line() {
	x = 0;
	y = 0;
	A = 0;
	B = 0;
	C = 0;
	a = 0;
	b = 0;
	t = 0;
	aNotExist = false;
}

void Line::makesort(double m, double n) {
	x = m;
	y = n;
}