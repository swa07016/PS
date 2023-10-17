#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start, end;
};

bool compare(const Meeting &a, const Meeting &b) {
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

// 1931
/*
    끝나는 시간이 빠른 회의를 우선적으로 선택함으로써 남은 시간을 최대한 활용하는 것이 문제의 핵심
*/
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, answer = 0, end_time = 0;
    cin >> N;

    vector<Meeting> meetings(N);

    for (int i = 0; i < N; i++)
        cin >> meetings[i].start >> meetings[i].end;

    // 1. 끝나는 시간 기준으로 정렬
    sort(meetings.begin(), meetings.end(), compare);

    // 2. 회의를 탐색하면서 조건에 맞는 회의 선택
    for (int i = 0; i < N; i++) {
        if (meetings[i].start >= end_time) {
            end_time = meetings[i].end;
            answer++;
        }
    }

    cout << answer;

    return 0;
}
