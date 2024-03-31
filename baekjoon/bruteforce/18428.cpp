#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
public:
    int y;
    int x;
    Point(int y, int x) : y(y), x(x) {}
};

int n;
char board[10][10];
char copyBoard[10][10];
vector<Point> emptyPoints;
vector<Point> teachers;
vector<bool> selected;

void setCopyBoard() {
    // 원본 카피
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) 
            copyBoard[i][j] = board[i][j];
    }

    // 세 곳 장애물 설치
    for(int i=0; i<selected.size(); i++) {
        if(selected[i]) {
            Point s = emptyPoints[i];
            copyBoard[s.y][s.x] = 'O';
        }
    }
}

bool safe(int a, int b) {
    return (0 <= a && a < n) && (0 <= b && b < n);
}

bool isStudent(int y, int x) {
    if(copyBoard[y][x] == 'S') return true;
    return false;
}

bool isObstacle(int y, int x) {
    if(copyBoard[y][x] == 'O') return true;
    return false;
}

bool goTeacher(int ty, int tx) {
    // 왼쪽) y고정 x감소
    int cy = ty; 
    int cx = tx;
    while(safe(cy, cx)) {
        if(isStudent(cy, cx)) return false;       
        if(isObstacle(cy, cx)) break;
        cx--;
    }

    // 오른쪽) y고정 x증가
    cy = ty; cx = tx;
    while(safe(cy, cx)) {
        if(isStudent(cy, cx)) return false;       
        if(isObstacle(cy, cx)) break;
        cx++;
    }

    // 위) y감소 x고정
    cy = ty; cx = tx;
    while(safe(cy, cx)) {
        if(isStudent(cy, cx)) return false;       
        if(isObstacle(cy, cx)) break;
        cy--;
    }

    // 아래) y증가 x고정
    cy = ty; cx = tx;
    while(safe(cy, cx)) {
        if(isStudent(cy, cx)) return false;       
        if(isObstacle(cy, cx)) break;
        cy++;
    }    

    return true;
}

bool checkBoard() {
    for(int i=0; i<teachers.size(); i++) {
        Point teacher = teachers[i];
        int ty = teacher.y;
        int tx = teacher.x;

        bool isValid = goTeacher(ty, tx);
        if(!isValid) return false;
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'X') emptyPoints.push_back(Point(i, j));
            if(board[i][j] == 'T') teachers.push_back(Point(i, j));
        }
    }

    selected.resize(emptyPoints.size());
    selected[0] = selected[1] = selected[2] = true;
    
    do {
        // 3개 선택
        setCopyBoard();

        // 모든 학생들이 감시로부터 피할 수 있는지 확인
        bool isValid = checkBoard();
        if(isValid) {
            cout << "YES";
            return 0;
        }
    } while(prev_permutation(selected.begin(), selected.end()));

    cout << "NO";
    return 0;
}