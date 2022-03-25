#include <iostream>
#include <cmath>

using namespace std;

int n, input, ans;

// 소수 판정 함수
bool isPrime(int k) {
    if(k == 1) return false;
    for(int i=2; i*i<=k; i++) if(k%i == 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> input;
        if(isPrime(input)) ans++;        
    }
    
    cout << ans;
    return 0;
}
