#include <iostream>

using namespace std;
int t;

/*
    sum : 현재까지의 합
    cnt : 만들어진 방법의 개수
    n : 주어진 정수
*/
int go(int sum, int cnt, int n) {
    // 정답을 찾은 경우
    if(sum == n) return 1;
    // 불가능한 경우
    if(sum > n) return 0;

    // 다음 경우 호출
    for(int i=1; i<=3; i++) {
       cnt += go(sum+i, 0, n); 
    }  
    return cnt;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        cout << go(0, 0, n) << "\n";
    }
    
    return 0;
}
