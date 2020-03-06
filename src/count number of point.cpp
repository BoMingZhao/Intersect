#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include "line.h"
#include "circle.h"
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

void caculate_line_line(Line l1,Line l2) {//caculate the crosspoint of the two lines 
    crosspoint point;
    if (l1.aNotExist) {
        if (l2.aNotExist) {
            return;
        }
        else {
            point.x = l1.t;
            point.y = l2.a * point.x + l2.b;
            pointmap.insert(pair<crosspoint, int>(point, 1));
            return;
        }
    }
    else if (l2.aNotExist) {
        point.x = l2.t;
        point.y = l1.a * point.x + l1.b;
        pointmap.insert(pair<crosspoint, int>(point, 1));
        return;
    }
    else {
        point.x = (l2.b - l1.b) / (l1.a-l2.a);
        point.y = point.x * l1.a + l1.b;
        pointmap.insert(pair<crosspoint, int>(point, 1));
        return;
    }
}

void caculate_line_circle(Line l, Circle c) {//caculate the crosspoint of the one line and one circle
    crosspoint point1;
    crosspoint point2;
    if (l.aNotExist) {
        point1.x = l.t;
        point2.x = l.t;
        int k = (l.t - c.m) * (l.t - c.m);
        int r2 = c.r * c.r;
        int left = r2 - k;
        if (left < 0) {//no result
            return;
        }
        else if (left == 0) {//one result
            point1.y = c.n;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
        }
        else {//two result
            point1.y = sqrt(left) + c.n;
            point2.y = c.n - sqrt(left);
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            pointmap.insert(pair<crosspoint, int>(point2, 1));
        }
    }
    else {//ax^2+bx+t=0
        double a = l.a * l.a + 1;
        double b = 2 * ((l.b - c.n) * l.a - c.m);
        double t = (double)c.m * c.m + (l.b - c.n) * (l.b - c.n) - (double)c.r * c.r;
        double deta = b * b - 4 * a * t;
        if (deta > 0) {
            point1.x = (sqrt(deta) - b) / (2 * a);
            point2.x = (-1*sqrt(deta) - b) / (2 * a);
            point1.y = l.a * point1.x + l.b;
            point2.y = l.a * point2.x + l.b;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
            pointmap.insert(pair<crosspoint, int>(point2, 1));
        }
        else if (deta == 0) {
            point1.x = (b == 0) ? 0 : -1 * b / (2 * a);
            point1.y = l.a * point1.x + l.b;
            pointmap.insert(pair<crosspoint, int>(point1, 1));
        }
        else {
            return;
        }
    }
}

void caculate_circle_circle(Circle c1, Circle c2) {//caculate the crosspoint of the two circles

}

int main()
{
    int n;
    int x1, x2, y1, y2;
    int x, y, r;
    char type;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> type;
        if (type == 'L') { 
            scanf_s("%d%d%d%d",&x1,&y1,&x2,&y2);
            Line l(x1,y1,x2,y2);
            lineset.push_back(l);
        }
        else if (type == 'C') {
            scanf_s("%d%d%d", &x, &y, &r);
            Circle c(x,y,r);
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
                //cout << "l1:y=" << l1.a << "x+" << l1.b << endl;
                //cout << "l2:y=" << l2.a << "x+" << l2.b << endl;
                caculate_line_line(l1, l2);
            }
        }
        for (unsigned int i = 1; i <= lineset.size(); i++) {
            for (unsigned int j = 1; j <= circleset.size(); j++) {
                Line l = lineset[i - 1];
                Circle c = circleset[j - 1];
                caculate_line_circle(l, c);
            }
        }
        for (unsigned int i = 1; i < circleset.size(); i++) {
            for (unsigned int j = i + 1; j <= circleset.size(); j++) {
                Circle c1 = circleset[i - 1];
                Circle c2 = circleset[i - 2];
                caculate_circle_circle(c1, c2);
            }
        }
        cout << pointmap.size() << endl;
        Map::iterator p = pointmap.begin();
        while (p != pointmap.end()) {
            cout << "(" << p->first.x << "," << p->first.y << ")\n";
            p++;
        }
    }
    else {//扫描线

    }
}

