#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
int n;
vector<int> scv;
set<string> visited;

class Node {
public:
    vector<int> hp;
    int dist;
    Node(vector<int> hp, int dist) {
        this->hp = hp;
        this->dist = dist;
    }
};

bool isComplete(vector<int> hpList) {
    for(int i=0; i<hpList.size(); i++) {
        if(hpList[i] > 0) return false; 
    }
    return true;
}

vector<int> getPermuVectorBySize(int size) {
    vector<int> v;
    for(int i=1; i<=size; i++) v.push_back(i);
    return v;
}

int getLoseHpBySeq(int seq) {
    if(seq == 1) return 9;
    if(seq == 2) return 3;
    if(seq == 3) return 1;
}

string vToString(vector<int> v) {
    string s = "";
    for(int i=0; i<v.size(); i++) s += to_string(v[i]); 
    return s;
}

void solve() {
    

    queue<Node> q;
    q.push(Node(scv, 0));
    visited.insert(vToString(scv));

    while(!q.empty()) {
        vector<int> currentHp = q.front().hp;
        int currentDist = q.front().dist;
        q.pop();

        if(isComplete(currentHp)) {
            cout << currentDist;
            break;
        }
        
        vector<int> permu = getPermuVectorBySize(currentHp.size());

        do {
            vector<int> v = currentHp;
            for(int i=0; i<permu.size(); i++) {
                v[i] -= getLoseHpBySeq(permu[i]);
                if(v[i] < 0) v[i] = 0;
            }

            if(visited.find(vToString(v)) == visited.end()) {
                q.push(Node(v, currentDist+1));
                visited.insert(vToString(v));
            }
        } while(next_permutation(permu.begin(), permu.end()));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        scv.push_back(tmp);
    }
    solve();

    return 0;
}