#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int n, ans = -1;

/*
    문제에서 주어진 식의 값을 반환
*/
int getResult(vector<int> v) {
    int ret = 0;
    for(int i=1; i<n; i++) {
        ret += abs(v[i-1] - v[i]);
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++) cin >> v[i];
    
    // 첫 순열
    sort(v.begin(), v.end());
    
    /*
        첫 순열부터 마지막 순열까지
        각 순열에서 식의 값을 계산해
        최댓값을 갱신해줌.
    */
    do { 
        ans = max(ans, getResult(v));
    } while(next_permutation(v.begin(), v.end())); 
    
    cout << ans;
    return 0;
}
