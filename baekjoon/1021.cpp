#include <iostream>
#include <deque>
#include <vector>

using namespace std;
deque<int> dq;
int n, m;
vector<int> v;
int ans;

void moveLeft(deque<int>& _dq) {
    int tmp = _dq.front();
    _dq.pop_front();
    _dq.push_back(tmp);
}

void moveRight(deque<int>& _dq) {
    int tmp = _dq.back();
    _dq.pop_back();
    _dq.push_front(tmp);
}

char decideDirection(int key) {
    deque<int> copyLeftDq(dq);
    deque<int> copyRightDq(dq);
    int L = 0, R = 0;
    while(1) {
        if(copyLeftDq.front() == key) break;
        moveLeft(copyLeftDq);
        L++;
    }
    while(1) {
        if(copyRightDq.front() == key) break;
        moveRight(copyRightDq);
        R++;
    }
    return L < R ? 'L' : 'R';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    v.resize(m);
    for(int i=0; i<m; i++) cin >> v[i];
    for(int i=1; i<=n; i++) dq.push_back(i);
    
    for(int i=0; i<m; i++) {
        int key = v[i];
        if(dq.front() == key) dq.pop_front();
        else {
            char direction = decideDirection(key);
            if(direction == 'L') {
                while(1) {
                    if(dq.front() == key) {
                        dq.pop_front();
                        break;
                    }
                    moveLeft(dq);
                    ans++;
                }
            } else if(direction == 'R') {
                while(1) {
                    if(dq.front() == key) {
                        dq.pop_front();
                        break;
                    }
                    moveRight(dq);
                    ans++;
                }

            }
        }
    }
    cout << ans;
    return 0;
}
