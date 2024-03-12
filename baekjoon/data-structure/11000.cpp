#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Lecture {
public:
    int start;
    int end;
    Lecture(int start, int end) : start(start), end(end) {}

    // 강의 시작 시간 기준으로 정렬하기 위한 비교 연산자
    bool operator<(const Lecture& other) const {
        return start < other.start;
    }
};

// 최소 힙을 위한 비교 함수 객체
struct CompareEnd {
    // 반환값이 true이면 swap 하겠다.
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, s, e;
    cin >> n;

    vector<Lecture> lectures;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        lectures.push_back(Lecture(s, e));
    }

    // 시작 시간 기준으로 정렬
    sort(lectures.begin(), lectures.end());

    // 최소 힙을 이용해 강의 종료 시간 관리
    priority_queue<int, vector<int>, CompareEnd> lectureEndTimes;

    for (const auto& lecture : lectures) {
        if (!lectureEndTimes.empty() && lectureEndTimes.top() <= lecture.start) {
            // 가장 빨리 끝나는 강의 다음에 현재 강의 시작 가능
            lectureEndTimes.pop();
        }
        lectureEndTimes.push(lecture.end);
    }

    // 최소 힙의 크기가 필요한 최소 강의실 수
    cout << lectureEndTimes.size();

    return 0;
}
