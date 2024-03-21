#include <iostream>
#include <algorithm>

using namespace std;
int n;
int num[2010];
int ans;

bool isPossible(int key, int keyIndex) {
    int s = 1, e = n;
    if(s == keyIndex) s++;
    if(e == keyIndex) e--;
    while(s < e) {
        int curr = num[s] + num[e];
        if(curr == key) return true;
        if(curr > key) {
            e--;
            if(e == keyIndex) e--;
        }
        if(curr < key) {
            s++;
            if(s == keyIndex) s++;
        }
    }       
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> num[i];
    sort(num+1, num+1+n);

    for(int i=1; i<=n; i++) {
        if(isPossible(num[i], i)) ans++;
    }

    cout << ans;
    return 0;
}