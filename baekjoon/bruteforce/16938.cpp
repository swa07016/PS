#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, L, R, X, answer = 0;
vector<int> difficulties;

// index: 현재 고려하고 있는 문제의 인덱스
// count: 현재까지 선택된 문제의 수
// total: 선택된 문제들의 난이도 합
// minDiff: 선택된 문제들 중 가장 낮은 난이도
// maxDiff: 선택된 문제들 중 가장 높은 난이도
void backtrack(int index, int count, int total, int minDiff, int maxDiff) {
    if (index == N) {
        if (count >= 2 && total >= L && total <= R && (maxDiff - minDiff) >= X) {
            answer++;
        }
        return;
    }

    // 현재 문제를 선택하는 경우
    backtrack(index + 1, count + 1, total + difficulties[index], 
              min(minDiff, difficulties[index]), max(maxDiff, difficulties[index]));
              
    // 현재 문제를 선택하지 않는 경우
    backtrack(index + 1, count, total, minDiff, maxDiff);
}

int main() {
    cin >> N >> L >> R >> X;
    difficulties.resize(N);
    for (int& diff : difficulties) {
        cin >> diff;
    }

    backtrack(0, 0, 0, INT_MAX, INT_MIN);
    cout << answer << endl;

    return 0;
}
