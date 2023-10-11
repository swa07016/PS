#include <iostream>
#include <algorithm>

using namespace std;
int n;
int member[10010];
int ans = 987654321;


// 20044
/*
    한 팀은 2명으로 구성되고, 팀의 코딩역량은 그 둘의 코딩역량의 합으로 결정된다.
    문제의 목표는 팀 코딩역량들의 최솟값이 가장 작은 경우를 만들어야 한다.

    sol) 쉽게 생각해보면 멤버 코딩 역량의 오름차순으로 정렬을 해주고 양 끝 애들끼리 팀을 짝지어주면 된다..
*/
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<2*n; i++) cin >> member[i];

    sort(member, member + 2*n);

    for(int i=0; i<n; i++) {
        ans = min(ans, member[i] + member[2*n - i - 1]);
    }

    cout << ans;
    return 0;
}