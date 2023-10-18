#include <iostream>
#include <cmath>

using namespace std;
int n;
int answer[4];
int ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i=0; i<=223; i++) {
        for(int j=0; j<=223; j++) {
            for(int k=0; k<=223; k++) {
                for(int t=0; t<=223; t++) {
                    int candidate = i*i + j*j + k*k + t*t;
                    if(candidate == n) {
                        if(i != 0) ans++;
                        if(j !=0) ans++;
                        if(k!=0) ans++;
                        if(t!=0) ans++;
                        cout << ans;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}