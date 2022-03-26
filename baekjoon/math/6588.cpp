#include <iostream>

using namespace std;


bool prime[1000010];
int MAX = 1000000;

/* 에라토스테네스의 체를 이용한 prime배열 초기화
    prime[i] == true : 소수 아님
    prime[i] == false : 소수임
*/
void setPrimeNumbers() {
    prime[0] = prime[1] = true;
    for(int i=2; i*i<=MAX; i++) {
        if(!prime[i]) for(int j=i+i; j<=MAX; j+=i) prime[j] = true;
    }
}

/*
    가능한 두 홀수 소수의 조합이 나오면 출력,
    없으면 "Goldbach's conjecture is wrong." 출력
*/
void printGoldBach(int n) {
    for(int i=3; i<=n; i++) {
        if(!prime[i] && !prime[n-i]) {
            cout << n << " = " << i << " + " << n-i << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    setPrimeNumbers();
    
    int n;
    while(true) {
        cin >> n;
        if(n==0) break;
        printGoldBach(n);
    }

    return 0;
}
