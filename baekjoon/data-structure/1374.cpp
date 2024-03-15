#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Lecture {
public:
    int num;
    int start;
    int end;
    Lecture(int num, int start, int end) : num(num), start(start), end(end) {}
};

int n;
int input, s, e;
vector<Lecture> lectures;
priority_queue<int, vector<int>, greater<int> > classroomEndTimes;

bool compare(Lecture& a, Lecture& b) {
    return a.start < b.start;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input >> s >> e;
        lectures.push_back(Lecture(input, s, e));
    }

    sort(lectures.begin(), lectures.end(), compare);

    for(int i = 0; i < lectures.size(); i++) {
        if(!classroomEndTimes.empty() && classroomEndTimes.top() <= lectures[i].start) {
            classroomEndTimes.pop();
        }

        classroomEndTimes.push(lectures[i].end);
    }

    cout << classroomEndTimes.size();

    return 0;
}
