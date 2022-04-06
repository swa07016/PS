#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, s;
vector<int> input;
int ans;

/*
    고른 수들의 인덱스를 이용하여 수열의 합을 반환
*/
int getSum(vector<int> v) {
    int sum = 0;
    for(int i=0; i<v.size(); i++) sum += input[v[i]];
    return sum;    
}

/*
    index : 고른 수의 개수
    v : 고른 수들의 인덱스를 저장
*/
void go(int index, vector<int> v) {
        // 정답을 찾은 경우
        if(index != 0 && getSum(v) == s) ans++;
        
        // 불가능한 경우
        if(index == n + 1) return ;
        
        // 다음 경우 호출

        int start = v.empty() ? 0 : v.back();
        for(int i=start+1; i<=n; i++) {
            v.push_back(i);
            go(index + 1, v);
            v.pop_back();
        }       
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;   
    input.resize(n+1);   
    for(int i=1; i<=n; i++) cin >> input[i];
    
    vector<int> v;
    go(0, v);
    
    cout << ans;
    return 0;
}