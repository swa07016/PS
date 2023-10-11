#include <iostream>

using namespace std;

int prefixSum[310][310], board[310][310];
int m, n, ans;


// 23247
/*
    1) 완전 탐색으로 사각형의 양 끝점을 잡아서 만들어보는 방법은 최대 6중포문이 생기므로 무조건 시간초과가 난다.
    2) 2차원 누적합을 이용해 풀어보자

    prefixSum[a][b] : (1, 1) ~ (a, b) 까지의 누적합
    prefixSum[a][b] = prefixSum[a-1][b] + prefixSum[a][b-1] - prefixSum[a-1][b-1] + data[a][b] <- 이 식은 그림을 그려보면 쉽다.

    [참고] https://nahwasa.com/entry/%EB%88%84%EC%A0%81-%ED%95%A9prefix-sum-2%EC%B0%A8%EC%9B%90-%EB%88%84%EC%A0%81%ED%95%A9prefix-sum-of-matrix-with-java
*/
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;

    // 입력
    for(int i=1; i<=m; i++) 
        for(int j=1; j<=n; j++) 
            cin >> board[i][j];
        
    // 누적 합 계산
    for(int i=1; i<=m; i++) 
        for(int j=1; j<=n; j++) 
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + board[i][j];
    
    // for(int i=1; i<=m; i++) {
    //     for(int j=1; j<=n; j++) 
    //         cout << prefixSum[i][j] << " ";
    //     cout << "\n";
    // }

    // (i, j) ~ (k, l) 누적합을 구함. (k, l)이 증가하는 방향이니 만약 10을 넘으면 중지
    for(int i=1; i<=m; i++) { 
        for(int j=1; j<=n; j++) {
            for(int k=i; k<=m; k++) {
                for(int l=j; l<=n; l++) {
                    int rectSum = prefixSum[k][l] - prefixSum[k][j-1] - prefixSum[i-1][l] + prefixSum[i-1][j-1];
                    if(rectSum == 10) ans++;
                    if(rectSum > 10) break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}