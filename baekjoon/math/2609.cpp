#include <iostream>
#include <cmath>

using namespace std;

// 유클리드 호제법
int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, g;
    cin >> a >> b;
    g = gcd(a, b);
    /*
        g : a, b의 최대공약수일 때,
        최소공배수 = g*(a/g)*(b/g)를 이용
    */
    cout << g << "\n" << g*(a/g)*(b/g);

    return 0;
}
