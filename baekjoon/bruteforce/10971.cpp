#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int n, ans = INT_MAX;
vector<vector<int>> w;

/*
    외판원이 모든 도시를 순회하는 비용을 반환
    모든 도시가 연결되어있지 않은 경우에 INT_MAX 반환
*/
int getTotalPathCost(vector<int> v) {
    bool isValid = true;
    int totalCost = 0;
    
    // 모든 도시가 연결되어 있는지 검사
    if(!w[v.back()][v.front()]) isValid = false;
    for(int i=0; i<n-1; i++) {
        int start = v[i],
            end = v[i+1];
        if(!w[start][end]) isValid = false;
    }
    if(!isValid) return INT_MAX;
    
    /*
        모든 도시가 연결되어 있으니,
        외판원이 순회하는 비용 계산
    */
    for(int i=0; i<n-1; i++) {
        int start = v[i],
            end = v[i+1];
        totalCost += w[start][end];
    } totalCost += w[v.back()][v.front()];

    return totalCost;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    w.resize(n, vector<int>(n));
    vector<int> city(n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> w[i][j];

    for(int i=0; i<n; i++) city[i] = i;
    

    // 모든 경로에 대해 최솟값 계산
    do {
        ans = min(ans, getTotalPathCost(city));
    } while(next_permutation(city.begin(), city.end()));
    
    cout << ans;
    return 0;
}
