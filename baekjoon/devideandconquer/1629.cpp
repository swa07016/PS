#include <iostream>

using namespace std;

/*
    1. INT_MAX의 제곱은 long long int 범위에 들어온다.
    2. a^5 = a^2 * a^3으로 쪼갤 수 있다.
    3. (A * B) % M = ((A % M) * (B % M)) % M;
*/
long long int solve(int a, int b, int c) {
    // 종료조건
    if(b == 1)
        return a % c;

    // 지수가 짝수라면
    if(b % 2 == 0)
        return ((solve(a, b/2, c) % c) * (solve(a, b/2, c) % c)) % c;

    // 지수가 홀수라면
    else
        return ((solve(a, b/2, c) % c) * (solve(a, b/2 + 1, c) % c)) % c;
}

int main() {
    int a, b, c;

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> a >> b >> c;

    cout << solve(a, b, c);

    return 0;
}