#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include "count number of point.h"
using namespace std;

typedef struct{
    double x;
    double y;
}crosspoint;
bool operator< (const crosspoint& a, const crosspoint& b) {
    if (a.x < b.x || (a.x == b.x && a.y < b.y)) {
        return true;
    }
    return false;
}
bool operator != (const crosspoint& a, const crosspoint& b) {
    if (a.x != b.x || a.y != b.y) {
        return true;
    }
    return false;
}

typedef std::map<crosspoint, int> Map;
Map pointmap;
vector<Line> lineset;
vector<Circle> circleset;

int Calculate::caculate_line_line(Line l1,Line l2) {//caculate the crosspoint of the two lines 
    //int is eazy to test
    crosspoint point;
    if (l1.aNotExist) {
        if (l2.aNotExist) {
            return 0;
        }
        else {
            point.x = l1.t;
            point.y = l2.a * point.x + l2.b;
            pointmap.insert(pair<crosspoint, int>(point, 1));
            return 1;
        }
    }
    else if (l2.aNotExist) {
        point.x = l2.t;
        point.y = l1.a * point.x + l1.b;
        pointmap.insert(pair<crosspoint, int>(point, 1));
        return 1;
    }
    else {
        if (l1.a == l2.a) {
            return 0;
        }
        else {
            point.x = (l2.b - l1.b) / (l1.a - l2.a);
            point.y = point.x * l1.a + l1.b;
            pointmap.insert(pair<crosspoint, int>(point, 1));
            return 1;
        }
    }
}

int Calculate::caculate_line_circle(Line l, Circle c) {//caculate the crosspoint of the one line and one circle
    crosspoint point1;
    crosspoint point2;
    if (l.aNotExist) {
        point1.x = l.t;
        point2.x = l.t;
        double k = ((double)l.t - c.m) * ((double)l.t - c.m);
        double r2 = (double)c.r * c.r;
        double left = r2 - k;
        if (left < 0) {//no result
            return 0;
        }
        else if (left == 0) {//one result
            point1.y = c.n;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            return 1;
        }
        else {//two result
            point1.y = sqrt(left) + c.n;
            point2.y = c.n - sqrt(left);
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            pointmap.insert(pair<crosspoint, int>(point2, 1));
            return 2;
        }
    }
    else {//ax^2+bx+t=0
        double a = l.a * l.a + 1;
        double b = 2 * ((l.b - c.n) * l.a - c.m);
        double t = (double)c.m * c.m + (l.b - c.n) * (l.b - c.n) - (double)c.r * c.r;
        double deta = b * b - 4 * a * t;
        if (deta > 0) {
            point1.x = (sqrt(deta) - b) / (2 * a);
            point2.x = (-1 * sqrt(deta) - b) / (2 * a);
            point1.y = l.a * point1.x + l.b;
            point2.y = l.a * point2.x + l.b;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            pointmap.insert(pair<crosspoint, int>(point2, 1));
            return 2;
        }
        else if (deta == 0) {
            point1.x = (b == 0) ? 0 : -1 * b / (2 * a);
            point1.y = l.a * point1.x + l.b;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            return 1;
        }
        else {
            return 0;
        }
    }
}

int Calculate::caculate_circle_circle(Circle c1, Circle c2) {//caculate the crosspoint of the two circles
    crosspoint point1;
    crosspoint point2;
    if (c2.n == c1.n && c2.m == c1.m) {
        return 0;
    }
    else if (c2.n == c1.n) {
        double temp = ((double)c2.m * c2.m - (double)c1.m * c1.m + (double)c2.n * c2.n - (double)c1.n * c1.n + (double)c1.r * c1.r - (double)c2.r * c2.r)
            / ((double)2 * ((double)c2.m - c1.m));
        point1.x = temp;
        point2.x = temp;
        double left = (double)c1.r * c1.r - (temp - c1.m) * (temp - c1.m);
        if (left > 0) {
            point1.y = sqrt(left) + c1.n;
            point2.y = c1.n - sqrt(left);
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            pointmap.insert(pair<crosspoint, int>(point2, 1));
            return 2;
        }
        else if (left == 0) {
            point1.y = c1.n;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        double k = ((double)c1.m - c2.m) / ((double)c2.n - c1.n);
        double temp = ((double)c2.m * c2.m - (double)c1.m * c1.m + (double)c2.n * c2.n - (double)c1.n * c1.n + (double)c1.r * c1.r - (double)c2.r * c2.r)
            / ((double)2 * ((double)c2.n - c1.n));
        double a = 1 + k * k;
        double b = 2 * (k * temp - c1.n * k - c1.m);
        double c = (double)c1.m * c1.m + (double)c1.n * c1.n - (double)c1.r * c1.r + temp * temp - 2 * temp * c1.n;
        double deta = b * b - 4 * a * c;
        if (deta > 0) {
            point1.x = (sqrt(deta) - b) / (2 * a);
            point2.x = (-1 * sqrt(deta) - b) / (2 * a);
            point1.y = point1.x * k + temp;
            point2.y = point2.x * k + temp;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            pointmap.insert(pair<crosspoint, int>(point2, 1));
            return 2;
        }
        else if (deta == 0) {
            point1.x = (b == 0) ? 0 : -1 * b / (2 * a);
            point1.y = point1.x * k + temp;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            return 1;
        }
        else {
            return 0;
        }
    }
}

int main()
{
    int n;
    int x1, x2, y1, y2;
    int x, y, r;
    char type;
    cin >> n;
    Calculate calculate;
    for (int i = 1; i <= n; i++) {
        cin >> type;
        if (type == 'L') { 
            scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
            Line l(x1, y1, x2, y2);
            lineset.push_back(l);
        }
        else if (type == 'C') {
            scanf_s("%d%d%d", &x, &y, &r);
            Circle c(x, y, r);
            circleset.push_back(c);
        }
        else {
            cout << "wrong format！" << endl;
            exit(0);
        }
    }
    if (n <= 1000) {//暴力
        for (unsigned int i = 1; i < lineset.size(); i++) {
            for (unsigned int j = i + 1; j <= lineset.size(); j++) {
                Line l1 = lineset[i - 1];
                Line l2 = lineset[j - 1];
                calculate.caculate_line_line(l1, l2);
            }
        }
        for (unsigned int i = 1; i <= lineset.size(); i++) {
            for (unsigned int j = 1; j <= circleset.size(); j++) {
                Line l = lineset[i - 1];
                Circle c = circleset[j - 1];
                calculate.caculate_line_circle(l, c);
            }
        }

        for (unsigned int i = 1; i < circleset.size(); i++) {
            for (unsigned int j = i + 1; j <= circleset.size(); j++) {
                Circle c1 = circleset[i - 1];
                Circle c2 = circleset[j - 1];
                calculate.caculate_circle_circle(c1, c2);
            }
        }
        cout << pointmap.size() << endl;
        /*Map::iterator p = pointmap.begin();
        while (p != pointmap.end()) {
            cout << "(" << p->first.x << "," << p->first.y << ")\n";
            p++;
        }*/
    }
    else {//扫描线

    }
}

