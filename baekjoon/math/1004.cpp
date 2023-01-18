#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;
int x1, y1, x2, y2;
int a, b, c;

struct Circle {
    int x, y, r;
} typedef Circle;
vector<Circle> circles;

int distanceSquare(int ax, int ay, int bx, int by) {
    return (abs(ax-bx)*abs(ax-bx)) + (abs(ay-by)*abs(ay-by));
}

int isInclude(int x, int y, Circle circle) {
    if(distanceSquare(x, y, circle.x, circle.y) > (circle.r*circle.r)) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for(int i=0; i<t; i++) {
        int res_s = 0, res_d = 0, res_same = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for(int j=0; j<n; j++) {
            Circle circle;
            cin >> circle.x >> circle.y >> circle.r;
            circles.push_back(circle);
        }
        for(int j=0; j<n; j++) {
            int sourceInclude, destinationInclude;
            sourceInclude = isInclude(x1, y1, circles[j]);
            destinationInclude = isInclude(x2, y2, circles[j]);
            if(sourceInclude == 1 && destinationInclude == 1) res_same += 1;
            res_s += sourceInclude;
            res_d += destinationInclude;
        }
        cout << res_s + res_d - res_same*2 << "\n";
        circles.clear();
    }
    return 0;
}