#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int t[20], p[20];
int ans = -1;


/*
    day : 현재 날짜
    sum : 금액의 합
*/
void go(int day, int sum) {
    // 불가능한 경우
    if(day > n+1) return ;
    
    // 정답을 찾은 경우
    if(day == n+1) {
        ans = max(ans, sum);
        return ;
    }
    
    // 다음 경우 호출
    go(day + t[day], sum + p[day]);
    go(day + 1, sum);
}

int main() {

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> t[i] >> p[i];    
   
    go(1, 0);
    cout << ans;
   
    return 0;
}