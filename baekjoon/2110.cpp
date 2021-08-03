#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, c;
vector<int> house;
int ans;

bool setRouter(int k) {
    int L = house[0];
    int cnt = 1;
    for(int i=1; i<n; i++) {
        int R = house[i];
        if(R - L >= k) {
            cnt++;
            L = R;
        }
    }
    if(cnt >= c) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    house.resize(n);
    for(int i=0; i<n; i++) cin >> house[i];
    sort(house.begin(), house.end());
    
    int L = 1;
    int R = house[n-1] - house[0];
    
    while(L <= R) {
        int M = (L+R)/2;
        if(setRouter(M)) {
            ans = max(ans, M);
            L = M + 1;
        } else R = M - 1;
    }
    
    cout << ans;
    return 0;
}