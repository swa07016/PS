// Draft
#include <iostream>

using namespace std;
int n, m;
int cheeseCount;
int cheese[110][110], cheeseCopy[110][110];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool safe(int y, int x) {
    return (1<=y & y<=n) && (1<=x && x<=m);
}

void input() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) cin >> cheese[i][j];
    }
}

bool isCheeseEmpty() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) if(cheese[i][j]) return false;
    }
    return true;
}

int getCheeseCount() {
    int cnt = 0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) if(cheese[i][j]) cnt++;
    }

    return cnt;
}

void copyCheese() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) 
            cheeseCopy[i][j] = cheese[i][j];
    }
}

void updateCheese() {
    // 치즈 원본 복제본 생성
    copyCheese();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    input();
    int currentTime = 0;

    whlie(true) {
        // 현재 치즈 개수 가져오기
        cheeseCount = getCheeseCount();
        // 1시간 증가
        currentTime++;
        // 치즈 녹이기
        updateCheese();
        // 녹이고서 다 녹았다면 탈출
        if(isEmptyCheese()) break;
    }

    cout << currentTime << "\n" << cheeseCount;

    return 0;
}