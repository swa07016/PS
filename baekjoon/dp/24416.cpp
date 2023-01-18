#include <iostream>

using namespace std;
int f[41];
int cntFib, cntFibonacci;

int fib(int n) {
    if(n ==1 || n==2) {
        cntFib++;
        return 1;
    }
    else return (fib(n-1) + fib(n-2));
}

int finbonacci(int n) {
    f[1] = f[2] = 1;
    for(int i=3; i<=n; i++) {
        cntFibonacci++;
        f[i] = f[i-1] + f[i-2];
    } 
    return f[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    fib(n); finbonacci(n);
    cout << cntFib << " " << cntFibonacci;
    return 0;
}