#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> egg[8]; // 계란의 내구도와 무게 저장 (first: 내구도, second: 무게)

// idx번째 계란을 들어서 다른 계란들을 치는 함수
int solve(int idx) {
    // 가장 오른쪽 계란까지 모두 검사했다면 종료
    if (idx == n) {
        int brokenCount = 0;
        for (int i = 0; i < n; i++) {
            if (egg[i].first <= 0) {
                brokenCount++;
            }
        }
        return brokenCount;
    }

    // 이미 깨진 계란이면 다음 계란을 검사
    if (egg[idx].first <= 0) return solve(idx + 1);

    int res = 0;
    bool isHit = false; // 다른 계란을 친 경우 확인을 위한 변수

    for (int i = 0; i < n; i++) {
        if (i != idx && egg[i].first > 0) {
            isHit = true;
            egg[i].first -= egg[idx].second;
            egg[idx].first -= egg[i].second;
            res = max(res, solve(idx + 1));
            // 원상태로 복구
            egg[i].first += egg[idx].second;
            egg[idx].first += egg[i].second;
        }
    }

    // 아무 계란도 치지 않았다면 다음 계란으로 넘어감
    if (!isHit) return solve(idx + 1);
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> egg[i].first >> egg[i].second;
    }

    cout << solve(0) << "\n";
    return 0;
}
