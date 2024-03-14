#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
    모든 회의를 시작 시간 기준으로 오름차순 정렬합니다.
    최소 힙(우선순위 큐)을 사용하여 현재 진행 중인 회의들의 종료 시간을 관리합니다.
    
    각 회의에 대해 다음을 수행합니다:
    현재 회의의 시작 시간이 힙의 최소 원소(가장 먼저 끝나는 회의의 종료 시간)보다 크거나 같다면,
    이 회의는 가장 먼저 끝나는 회의실에서 진행할 수 있으며, 
    해당 회의실을 업데이트합니다(최소 원소를 제거하고 현재 회의의 종료 시간을 삽입).
    그렇지 않다면, 새 회의실이 필요하며, 현재 회의의 종료 시간을 힙에 삽입합니다.
    모든 회의를 처리한 후, 힙에 남아 있는 원소의 수가 필요한 최소 회의실 수입니다.
*/

// Meeting 구조체는 하나의 회의를 나타냅니다. 시작 시간(start)과 종료 시간(end)을 포함합니다.
struct Meeting {
    int start, end;
};

// compareMeeting 함수는 두 회의를 시작 시간을 기준으로 비교합니다.
bool compareMeeting(const Meeting &a, const Meeting &b) {
    return a.start < b.start;
}

int main() {
    int N;
    cin >> N;

    vector<Meeting> meetings(N);

    // 모든 회의의 시작 시간과 종료 시간을 입력받습니다.
    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].start >> meetings[i].end;
    }

    // 회의들을 시작 시간을 기준으로 오름차순 정렬합니다.
    sort(meetings.begin(), meetings.end(), compareMeeting);

    // 우선순위 큐(pq)를 사용하여 각 회의실에서 다음 회의가 시작될 수 있는 가장 빠른 시간을 관리합니다.
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto &meeting : meetings) {
        // 현재 회의가 시작하기 전에 끝나는 회의실이 있다면, 그 회의실을 재사용합니다.
        if (!pq.empty() && pq.top() <= meeting.start) {
            pq.pop();  // 기존 회의실의 사용이 끝났으므로 큐에서 제거합니다.
        }
        
        // 현재 회의의 종료 시간을 큐에 추가합니다. 이는 새로운 회의를 시작할 때 이 회의실이 사용 가능하다는 것을 의미합니다.
        pq.push(meeting.end);
    }

    // 모든 회의를 배치한 후, pq에 남아 있는 원소의 수가 필요한 최소 회의실의 개수입니다.
    cout << pq.size() << endl;

    return 0;
}