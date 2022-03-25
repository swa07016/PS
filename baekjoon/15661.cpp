#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> stats;
int min_diff = INT_MAX;

int getDiff(vector<int>& v) {
    int start_sum = 0, link_sum = 0;
    vector<int> start = v;
    vector<int> link;
    for(int i=0; i<n; i++) {
        if(find(start.begin(), start.end(), i)==start.end()) link.push_back(i);
    }
    for(int i=0; i<start.size()-1; i++) {
        for(int j=i+1; j<start.size(); j++) {
            start_sum += (stats[start[i]][start[j]]+stats[start[j]][start[i]]); 
        }    
    }
    for(int i=0; i<link.size()-1; i++) {
        for(int j=i+1; j<link.size(); j++) {
            link_sum += (stats[link[i]][link[j]]+stats[link[j]][link[i]]); 
        }    
    }
    return abs(start_sum - link_sum);
}

void dfs(vector<int>& v, int depth, int goal) {
    if(depth == goal) {
        min_diff = min(min_diff, getDiff(v));
        return ;
    }
    int start = -1;
    if(!v.empty()) start = v.back();
    for(int i=start+1; i<n; i++) {
            v.push_back(i);
            dfs(v, depth+1, goal);
            v.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    stats.resize(n);
    for(int i=0; i<n; i++) {
        stats[i].resize(n);
        for(int j=0; j<n; j++) cin >> stats[i][j];
    }
    vector<int> v;
    for(int i=2; i<=n/2; i++) dfs(v, 0, i);
    cout << min_diff;
    return 0;
}