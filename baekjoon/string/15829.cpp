#include <iostream>
#include <string>

using namespace std;
int L;
string str;
long long int ans;

int toInt(char s) {
    return s - 'a' + 1;
}

const int MOD = 1234567891;

// 15829
/*
    NOTE - ans에서 곱할때 a와 r^i를 곱할때 int 범위를 벗어날 수 있으므로 long long int로 해주어야한다.
    
    - 나머지 연산의 성질도 알고있으면 좋다..
    - (A+B)%M = (A%M + B%M) % M
    - (AXB)%M = (A%M X B%M) % M
    - (A-B)%M = (A%M - B%M + M) % M → 이렇게 하면 음수가 안 나옴

*/
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> L >> str;
    for(int i=0; i<L; i++) {
        long long int a = toInt(str[i]);
        long long int rI = 1;
        for(int j=0; j<i; j++) rI = ((rI % MOD) * 31) % MOD;

        ans += ((a % MOD) * (rI % MOD)) % MOD;

    }

    cout << ans % MOD;

    return 0;
}