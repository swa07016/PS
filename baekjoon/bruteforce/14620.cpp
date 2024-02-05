#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Point {
public:
    int y, x;

    Point(int y, int x) {
        this->y = y;
        this->x = x;
    }
    
    string toString() const {
        int val = this->y*10 + this->x;
        return to_string(val);
    }
};

int n;
int price[15][15];
int flower[15][15];
int answer = INT_MAX;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
vector<Point> points;

void initFlower() {
    for(int i=0; i<=n+1; i++) {
        for(int j=0; j<=n+1; j++) flower[i][j] = 0;
    }
}

void markingFlower(int y, int x) {
    flower[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        flower[ny][nx]++;
    }
}

bool isPossible() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(flower[i][j] >= 2) return false;
        } 
    }
    return true;
}

int getPrice(vector<Point> selectedPoints) {
    int ret = 0;
    for(int i=0; i<selectedPoints.size(); i++) {
        int ty = selectedPoints[i].y;
        int tx = selectedPoints[i].x;
        ret += price[ty][tx];

        for(int j=0; j<4; j++) {
            int ny = ty + dy[j];
            int nx = tx + dx[j];
            ret += price[ny][nx];
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> price[i][j];
      
        } 
    }

    for(int i=2; i<=n-1; i++) {
        for(int j=2; j<=n-1; j++) {
            points.push_back(Point(i, j));
        }
    }

    vector<int> selection((n-2)*(n-2));
    selection[0] = selection[1] = selection[2] = 1;

    do {
        initFlower();
        vector<Point> selectedPoints;
        
        for(int i=0; i<selection.size(); i++) {
            if(selection[i]) {
                selectedPoints.push_back(points[i]);
                int ty = points[i].y;
                int tx = points[i].x;
                markingFlower(ty, tx);
            }
        } 
        if(isPossible()) answer = min(answer, getPrice(selectedPoints));
    } while(prev_permutation(selection.begin(), selection.end()));

    cout << answer;
    return 0;
}