#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[10010];
long long int ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) cin >> num[i];
    sort(num, num+n);

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int a = num[i];
            int b = num[j];
            int key = -(a+b);

            // key를 만족하는 원소의 개수 구하기
            auto upper = upper_bound(num + j + 1, num + n, key) - num;
            auto lower = lower_bound(num + j + 1, num + n, key) - num;
            ans += (upper - lower);
        }
    }

    cout << ans;

    return 0;
}