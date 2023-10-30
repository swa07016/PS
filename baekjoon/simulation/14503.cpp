#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[51][51];
int dy[4] = {-1, 0, 1, 0};  // 북, 동, 남, 서 순서의 y방향 이동
int dx[4] = {0, 1, 0, -1}; // 북, 동, 남, 서 순서의 x방향 이동

// 재귀적으로 청소를 수행하는 함수
int solve(int y, int x, int d) {
    int cnt = 0;

    // 현재 위치가 청소되지 않았다면 청소
    if (board[y][x] == 0) {
        board[y][x] = 2;
        cnt++;
    }

    // 네 방향 검사
    for (int i = 0; i < 4; i++) {
        d = (d - 1 + 4) % 4;  // 왼쪽 방향으로 회전
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        // 회전한 방향에 청소하지 않은 칸이 있다면 그 방향으로 이동 후 청소 수행
        if (0 <= ny && ny < N && 0 <= nx && nx < M && board[ny][nx] == 0) {
            cnt += solve(ny, nx, d);
            return cnt;
        }
    }

    // 모든 방향이 청소되어있거나 벽인 경우
    int ny = y - dy[d];  // 뒤쪽 방향으로 이동
    int nx = x - dx[d];
    if (0 <= ny && ny < N && 0 <= nx && nx < M && board[ny][nx] != 1) {  // 뒤쪽 방향이 벽이 아니면 이동
        return cnt + solve(ny, nx, d);
    }
    return cnt;
}

int main() {
    cin >> N >> M;  // 방의 크기 입력
    int r, c, d;  // 로봇의 초기 위치와 방향 입력
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];  // 방의 상태 입력
        }
    }

    // 청소 시작 및 결과 출력
    cout << solve(r, c, d) << '\n';
    return 0;
}
