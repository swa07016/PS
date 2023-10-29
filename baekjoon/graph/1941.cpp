#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

string board[5];
vector<pair<int, int>> students;  // 모든 학생의 위치를 저장할 벡터
int ans = 0;

// 좌표가 유효한지 확인하는 함수
bool safe(int y, int x) {
    return (0 <= y && y < 5) && (0 <= x && x < 5);
}

// 선택된 7명의 학생이 서로 연결되어 있는지 확인하는 함수 (DFS나 BFS로 확인 가능, 여기서는 BFS 사용)
bool isConnected(vector<pair<int, int>>& selected) {
    int count = 1;
    bool visited[5][5] = {false};
    queue<pair<int, int>> q;
    q.push(selected[0]);
    visited[selected[0].first][selected[0].second] = true;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(safe(ny, nx) && !visited[ny][nx]) {
                for(int i = 0; i < selected.size(); i++) {
                    if(ny == selected[i].first && nx == selected[i].second) {
                        count++;
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
    
    return count == 7;  // 7명 모두 연결되어 있으면 true, 아니면 false 반환
}

// 25명 중 7명을 선택하는 조합을 구현하는 함수
void comb(int idx, int sCount, int yCount, vector<pair<int, int>>& selected) {
    if(selected.size() == 7) {
        if(sCount >= 4 && isConnected(selected)) {  // 'S'가 4명 이상이고 연결되어 있다면
            ans++;
        }
        return;
    }

    if(idx == students.size()) return;

    selected.push_back(students[idx]);
    if(board[students[idx].first][students[idx].second] == 'S') {
        comb(idx+1, sCount+1, yCount, selected);  // 'S' 학생일 경우
    } else {
        comb(idx+1, sCount, yCount+1, selected);  // 'Y' 학생일 경우
    }
    selected.pop_back();

    comb(idx+1, sCount, yCount, selected);
}

int main() {
    for(int i = 0; i < 5; i++) {
        cin >> board[i];
        for(int j = 0; j < 5; j++) {
            students.push_back({i, j});  // 모든 학생의 위치 저장
        }
    }

    vector<pair<int, int>> selected;  // 7명의 학생을 선택할 벡터
    comb(0, 0, 0, selected);  // 조합 시작

    cout << ans;  // 답 출력
    return 0;
}
