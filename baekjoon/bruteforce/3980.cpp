#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int stat[12][12];
bool visited[12];
int max_sum = -1;

void go(int depth, int sum) {
    // 종료조건
    if(depth == 11) { 
        max_sum = max(max_sum, sum);
        return ;
    }

    // depth + 1번 친구가 i번 포지션에 서는 경우
    // 다음 경우 탐색 (0이 아닌 경우만 가지 뻗기)
    for(int i=1; i<=11; i++) {
        int st = stat[depth + 1][i];
        if(st > 0 && !visited[i]) {
            visited[i] = true;
            go(depth + 1, sum + st);
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while(t--) {
        // 입력
        for(int i=1; i<=11; i++)
            for(int j=1; j<=11; j++) 
                cin >> stat[i][j];
                
        max_sum = -1;
        go(0, 0);

        cout << max_sum << "\n";
    }

    return 0;
}