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
	double A, B, C;//ax+by+c = 0£∫
	double x, y;//≈≈–Ú”√
	double a, b, t;
	bool aNotExist;
	Line(int x1, int y1, int x2, int y2);
	Line();
	void makesort(double m, double n);
};