#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> num;
bool visited[21];
int result;

void dfs(int curr, int depth, int goal, int sum, vector<bool>& check) {
    if(depth == goal) {
        check[sum] = true;
        return ;
    }
    
    int start = curr + 1;
    
    for(int i=start; i<n; i++) {
        int next = i;
        if(!visited[next]) {
            visited[next] = true;
            dfs(next, depth+1, goal, sum+num[next], check);
            visited[next] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    num.resize(n);
    int maxV = 0;
    for(int i=0; i<n; i++) {
        cin >> num[i];
        maxV += num[i];
    }
    sort(num.begin(), num.end());
    
    vector<bool> check(maxV+1, false);
    for(int i=1; i<=n; i++) {
        dfs(-1, 0, i, 0, check);
    }
    
    for(int i=1; i<=maxV; i++) {
        if(!check[i]) {
            result = i;
            break;
        }
    }
    if(!result) cout << maxV+1;
    else cout << result;
    return 0;
}