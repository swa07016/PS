#include <iostream>
#include <cstring> // memset을 사용하기 위해 추가

using namespace std;
const int MAX_N = 100010;
int n;
int num[MAX_N];
bool exist[MAX_N]; // 해당 숫자가 현재 부분 수열에 존재하는지 체크
long long ans = 0; // 가능한 경우의 수 (답이 클 수 있으므로 long long 사용)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];

    int s = 0, e = 0;
    exist[num[0]] = 1; // 첫 번째 숫자를 포함시킴

    while(s < n && e < n) {
        // e를 가능한 만큼 오른쪽으로 이동
        while(e + 1 < n && !exist[num[e + 1]]) {
            e++;
            exist[num[e]] = 1;
        }

        // [s, e] 구간의 모든 부분 구간이 유효하므로, 경우의 수 추가
        // e - s + 1은 현재 [s, e] 구간에 포함된 서로 다른 숫자의 개수
        ans += (e - s + 1);

        // s를 오른쪽으로 한 칸 이동시키고, s가 가리키던 숫자를 exist 배열에서 제거
        exist[num[s]] = 0;
        s++;
    }

    cout << ans << "\n";

    return 0;
}
