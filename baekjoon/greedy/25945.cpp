#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, total;
vector<int> containers;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    containers.resize(n);

    for(int i=0; i<n; i++) {
        cin >> containers[i];
        total += containers[i];
    }
 
    int avg = total / n;
    int ans1 = 0, ans2 = 0;

    // avg 보다 작은 개수 vs avg + 1보다 높은 개수 중 큰 녀석을 찾으면 된다.   
    for(int i=0; i<n; i++) {
        if(containers[i] < avg) ans1 +=  avg - containers[i];
        if(containers[i] > avg + 1) ans2 += containers[i] - (avg + 1);
    }

    cout << max(ans1, ans2);

    return 0;
}
