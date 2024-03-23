#include <iostream>
#include <algorithm>

using namespace std;

int x;
int n;
int num[1000010];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(cin >> x) {
        bool found = false;
        x = x*10000000; // 나노로 변환
        cin >> n;

        // 입력
        for(int i=1; i<=n; i++) cin >> num[i];
        sort(num+1, num+1+n);
        
        int s = 1, e = n;
        while(s < e) {
            int curr = num[s] + num[e];
            
            if(curr == x) {
                cout << "yes " << num[s] << " " << num[e] << "\n";
                found = true;
                break;
            }

            if(curr < x) s++;
            if(curr > x) e--;
        }

        if(!found) cout << "danger" << "\n";
    }

    return 0;
}