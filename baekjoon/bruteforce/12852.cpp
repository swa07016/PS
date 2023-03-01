#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
bool visited[1000010];
int n;
int ansDist;
vector<int> ansVector;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    queue<pair<int, vector<int> > > q; // data, distance
    vector<int> v;
    v.push_back(n);
    q.push(make_pair(n, v));
    visited[n] = true;

    while(!q.empty()) {
        int x = q.front().first;
        vector<int> numVector = q.front().second;
        q.pop();

        if(x == 1) {
            ansDist = numVector.size()-1;
            ansVector = numVector;
            break;
        }

        if(x % 3 == 0 && !visited[x/3]) {
            vector<int> newVector(numVector);
            newVector.push_back(x/3);
            q.push(make_pair(x/3, newVector));
            visited[x/3] = true;
        }

        if(x % 2 == 0 && !visited[x/2]) {
            vector<int> newVector(numVector);
            newVector.push_back(x/2);
            q.push(make_pair(x/2, newVector));
            visited[x/2] = true;
        }

        if(!visited[x-1]) {
            vector<int> newVector(numVector);
            newVector.push_back(x-1);
            q.push(make_pair(x-1, newVector));
            visited[x-1] = true;
        }
    }

    cout << ansDist << "\n";
    for(int i=0; i<ansVector.size(); i++) {
        cout << ansVector[i] << " ";
    }

    return 0;
}