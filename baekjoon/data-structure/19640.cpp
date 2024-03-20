#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;

class Employee {
public:
    int index; // 사원의 원래 순서
    int workingDays; // 근무 일수
    int urgentDegree; // 급한 정도
    Employee(int idx, int wd, int ud) : index(idx), workingDays(wd), urgentDegree(ud) {}
};

// 근무 일수가 큰 순서, 근무 일수가 같다면 급한 정도가 큰 순서, 그것도 같다면 줄 번호가 작은 순서
struct Compare {
    bool operator()(const Employee& a, const Employee& b) {
        if (a.workingDays == b.workingDays) {
            if (a.urgentDegree == b.urgentDegree) {
                return ((a.index - 1) % m) > ((b.index - 1) % m);
            }
            return a.urgentDegree < b.urgentDegree;
        }
        return a.workingDays < b.workingDays;
    }
};

priority_queue<Employee, vector<Employee>, Compare> pq;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    vector<Employee> employees;

    for (int i = 0; i < n; i++) {
        int wd, ud;
        cin >> wd >> ud;
        employees.emplace_back(i + 1, wd, ud);  // 인덱스는 1부터 시작
        if (i < m) {  // 각 줄의 첫 번째 사람만 우선순위 큐에 추가
            pq.push(employees.back());
        }
    }

    int ans = 0;
    while (!pq.empty()) {
        Employee curr = pq.top(); pq.pop();

        // 데카의 차례를 찾음
        if (curr.index == k + 1) {
            cout << ans << "\n";
            break;
        }

        ans++;  // 화장실을 사용한 사람의 수를 증가

        int nextIndex = curr.index + m;  // 같은 줄의 다음 사람
        if (nextIndex <= n) {
            pq.push(employees[nextIndex - 1]);  // 다음 사람을 큐에 추가
        }
    }

    return 0;
}
