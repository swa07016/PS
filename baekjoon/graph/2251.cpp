#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int A, B, C;
vector<int> capa(3);
vector<int> ans;
set<vector<int> > visited;

vector<int> nextState(int from, int to, vector<int> state) {
    // 0 -> 1
    vector<int> currState(state);
    int prevToState = currState[to];
    currState[to] = min(currState[from] + currState[to], capa[to]);
    currState[from] -= abs(currState[to] - prevToState);
    return currState;
}
 
void setNextState(vector<int> state, queue<vector<int> >& q) {
    visited.insert(state);
    q.push(state);
}

void bfs() {
    queue<vector<int> > q;

    vector<int> v(3);
    v[0] = 0, v[1] = 0, v[2] = C;
    q.push(v);
    visited.insert(v);

    while(!q.empty()) {
        vector<int> curr = q.front();
        int a = q.front()[0];
        int b = q.front()[1];
        int c = q.front()[2];
        q.pop();

        if(a == 0) {
            if(find(ans.begin(), ans.end(), c) == ans.end()) ans.push_back(c);
        }

        if(a != 0) {
            vector<int> nS = nextState(0, 1, curr);
            if(visited.find(nS) == visited.end()) setNextState(nS, q);
            nS = nextState(0, 2, curr);
            if(visited.find(nS) == visited.end()) setNextState(nS, q);
        }

        if(b != 0) {
            vector<int> nS = nextState(1, 0, curr);
            if(visited.find(nS) == visited.end()) setNextState(nS, q);
            nS = nextState(1, 2, curr);
            if(visited.find(nS) == visited.end()) setNextState(nS, q);
        }

        if(c != 0) {
            vector<int> nS = nextState(2, 0, curr);
            if(visited.find(nS) == visited.end()) setNextState(nS, q);
            nS = nextState(2, 1, curr);
            if(visited.find(nS) == visited.end()) setNextState(nS, q);
        }
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> A >> B >> C;
    capa[0] = A; capa[1] = B; capa[2] = C;

    bfs();

    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}