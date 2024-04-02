#include <iostream>
#include <string>

using namespace std;

int n;

bool isPrime(string str) {
    int num = atoi(str.c_str());
    if(num == 1) return false;

    for(int i=2; i*i <= num; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

void go(string str) {
    // 종료 조건
    if(str.size() == n) {
        cout << str << "\n";
        return ;
    }

    // 다음 숫자 붙이기
    for(int i=0; i<=9; i++) {
        string next = str + to_string(i);
        if(isPrime(next)) go(next);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=2; i<=9; i++) {
        if(isPrime(to_string(i)))
            go(to_string(i));
    }


    return 0;
}