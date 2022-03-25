#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int S;
bool visited[10000][10000];

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    visited[1][0] = true;
    int t = 0;
    
    while(!q.empty()) {
        int qs = q.size();
        for(int i=0; i<qs; i++) {
            int currCnt = q.front().first;
            int currClip = q.front().second;
            q.pop();
            
            if(currCnt == S) {
                cout << t;
                return ;
            }
            
            // oper1
            if(!visited[currCnt][currCnt]) {
                q.push(make_pair(currCnt, currCnt));
                visited[currCnt][currCnt] = true;
            }
            //oper2
            if(currClip && !visited[currCnt+currClip][currClip]) {
                q.push(make_pair(currCnt+currClip, currClip));
                visited[currCnt+currClip][currClip] = true;
            }
            //oper3
            if(currCnt-1>=0 && !visited[currCnt-1][currClip]) {
                q.push(make_pair(currCnt-1, currClip));
                visited[currCnt-1][currClip] = true;
            }
        }
        t++;
    }
    
    return ;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> S;
    bfs();
    return 0;
}