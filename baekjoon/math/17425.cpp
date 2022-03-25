#include <iostream>
#include <cmath>
#define Long long long

using namespace std;
int t, n, pre_f;
int MAX = 1000000;
Long g[1000010];


void setG() {
    /*
        [1, MAX]구간의 수 i가 있을 때, 
        i의 배수에 해당하는 인덱스(i*1, i*2, i*3, ...)에 누적해준다.
        ex) i=2이면, g[2] += 2, g[4] += 2, g[6] +=2, ...
        아래 2중 for문을 마쳤을 때, 임의의 자연수 i의
        g[i] 값은 문제에서 설명하는 i의 약수의 합인 f(i)임.
    */
    for(Long i=1; i <= MAX; i++) 
        for(int j=1; i*j<=MAX; j++) 
            g[i*j] += i;
    
    /*
        원하는 g(i) = f(1) + f(2) + ... + f(i)이므로 아래 계산 수행.
    */
    for(Long i=2; i<=MAX; i++) g[i] += g[i-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    setG();
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        cout << g[n] << "\n";
    }

    return 0;
}
