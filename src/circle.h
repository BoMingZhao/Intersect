#pragma once
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>  
using namespace std;

class Circle {
public:
	int m, n, r;
	Circle(int a, int b, int c);
};

Circle::Circle(int a, int b, int c) {
	m = a;
	n = b;
	r = c;
}