#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;
int n, game;
int board[130][130];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

void initBoard() {
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) board[i][j] = 0;   
}

void fillBoard() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> board[i][j];
    }
}

bool safe(int a, int b) {
    return (0<=a && a<n) && (0<=b && b <n);
}

void solve() {
    int dist[130][130];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) dist[i][j] = INT_MAX;
    }

    // <currDist, currNode>
    priority_queue<
        pair<int, pair<int, int> >,
        vector<pair<int, pair<int, int> > >, 
        greater<pair<int, pair<int, int> > >
    > q;

    dist[0][0] = 0;
    q.push(make_pair(
        0,
        make_pair(0, 0)
    ));

    while(!q.empty()) {
        int currDist = q.top().first;
        int currNodeY = q.top().second.first;
        int currNodeX = q.top().second.second;
        q.pop();
        
        if(dist[currNodeY][currNodeX] < currDist) continue;

        for(int i=0; i<4; i++) {
            int nextNodeY = currNodeY + dy[i];
            int nextNodeX = currNodeX + dx[i];

            if(!safe(nextNodeY, nextNodeX)) continue;

            int newDist = dist[currNodeY][currNodeX] + board[nextNodeY][nextNodeX];
            if(newDist < dist[nextNodeY][nextNodeX]) {
                dist[nextNodeY][nextNodeX] = newDist;
                q.push(make_pair(
                    newDist, make_pair(nextNodeY, nextNodeX)
                ));
            }
        }
    }
    cout << "Problem " + to_string(game) + ": " << board[0][0] + dist[n-1][n-1] << "\n";
}

int main() {

    while(true) {
        game++;
        cin >> n;
        if(n == 0) break;
        
        fillBoard();

        solve();

        initBoard();
    }

    return 0;
}