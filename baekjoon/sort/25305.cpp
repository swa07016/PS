#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int score[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> score[i];
    sort(score, score+n);
    cout << score[n-k];
    return 0;
} 