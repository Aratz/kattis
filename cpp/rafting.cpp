#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAX_DIST 10000

using namespace std;

class Point {
    public:
        int x;
        int y;

        Point(int x, int y) : x(x), y(y)  {}

        Point operator+(const Point& b) const {
            Point p {this->x + b.x, this->y + b.y};
            return p;
        }

        Point operator-(const Point& b) const {
            Point p {this->x - b.x, this->y - b.y};
            return p;
        }

        int dot(const Point& a, const Point& b) {
            return a.x*b.x + a.y*b.y;
        }

        double norm() {
            return sqrt(this->x*this->x + this->y*this->y);
        }

        double dist2line(const Point& a, const Point& b);

};

double dist(const Point& a, const Point& b) {
    return (a-b).norm();
}

double Point::dist2line(const Point& a, const Point& b) {
    Point ac = *this - a;
    Point bc = *this - b;
    Point ab = b - a;

    int dota = dot(ab, ac);
    int dotb = dot(ab, bc);
    int ddot = dota*dotb;

    if(ddot < 0) {
        //proj c \in [a,b]
        double alpha = acos(dota/(ac.norm()*ab.norm()));
        return sin(alpha)*ac.norm();
    }
    else {
        return min(dist(a, *this), dist(b, *this));
    }
}

Point operator*(const int k, const Point& a) {
    Point p {k*a.x, k*a.y};
    return p;
}

Point operator*(const Point& a, const int k) {
    return k*a;
}


int main() {
    //Point a(0, 0), b(10, 0);
    //Point c(12, 2);
    //printf("%lf\n", c.dist2line(a, b));

    //*
    int t;
    cin >> t;
    while(t--) {
        int ni;
        cin >> ni;
        vector<Point> inner; inner.reserve(ni);
        while(ni--) {
            int x, y;
            cin >> x >> y;
            inner.push_back(Point(x, y));
        }

        int no;
        cin >> no;
        vector<Point> outer; outer.reserve(no);
        while(no--) {
            int x, y;
            cin >> x >> y;
            outer.push_back(Point(x, y));
        }

        double boat_diam = MAX_DIST;

        for(auto p: inner){
            for(int i = 0; i < outer.size() - 1; i++) {
                boat_diam = min(boat_diam, p.dist2line(outer[i], outer[i+1]));
            }
        }
        for(auto p: outer){
            for(int i = 0; i < inner.size() - 1; i++) {
                boat_diam = min(boat_diam, p.dist2line(inner[i], inner[i+1]));
            }
        }

        cout.precision(10);
        cout << boat_diam / 2 << "\n";
    }
    //*/
    return 0;
}
