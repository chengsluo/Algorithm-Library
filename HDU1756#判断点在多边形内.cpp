#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define maxn 111  
int m,n;
  
struct point {  
    double x, y;  
    point (double _x = 0, double _y = 0) : x(_x), y(_y) {}  
    point operator - (point a) const {  
        return point (x-a.x, y-a.y);
    }
    bool operator < (const point &a) const {  
        return x < a.x || (x == a.x && y < a.y);
    }
}p[maxn];  
  
const double eps = 1e-10;  
int dcmp (double x) {
    if (fabs (x) < eps)  
        return 0;  
    else return x < 0 ? -1 : 1;  
}  
double cross (point a, point b) {  
    return a.x*b.y-a.y*b.x;  
}  
double dot (point a, point b) {  
    return a.x*b.x + a.y*b.y;  
}  
bool PointOnLine (point a1, point a2, point p) {//判断点p是不是在线段a1a2上  
    if (dcmp (cross (a1-p, a2-p)) == 0 && dcmp (dot (a1-p, a2-p)) <= 0)  
        return 1;  
    return 0;  
}
  
bool PointInPolygon (point a, point *b) {
    int w = 0;
    for (int i = 0; i < n; i++) {
        if (PointOnLine (b[i], b[(i+1)%n], a))  
            return 0;
        int k = dcmp (cross (b[(i+1)%n]-b[i], a-b[i]));  
        int d1 = dcmp (b[i].y - a.y);
        int d2 = dcmp (b[(i+1)%n].y - a.y);
        if (k > 0 && d1 <= 0 && d2 > 0)  
            w++;
        if (k < 0 && d2 <= 0 && d1 > 0)  
            w--;
    }
    if (w != 0)
        return 1;
    return 0;
}

int main () {  
    ios::sync_with_stdio(0);
    while (cin >> n) {  
        for (int i = 0; i < n; i++) {  
            cin >> p[i].x >> p[i].y;  
        }  
        cin >> m;  
        while (m--) {  
            point tmp;  
            cin >> tmp.x >> tmp.y;  
            if (PointInPolygon (tmp, p)) {  
                cout << "Yes" << endl;  
            }  
            else cout << "No" << endl;  
        }
    }
    return 0;
}