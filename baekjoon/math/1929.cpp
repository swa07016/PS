#include <iostream>
#include <cmath>

using namespace std;

int m, n;
bool d[1000010];
int MAX = 1000000;

/* 에라토스테네스의 체를 이용한 d배열 초기화
    d[i] == true : 소수 아님
    d[i] == false : 소수임
*/
void setD() {
    d[0] = d[1] = true;
    for(int i=2; i*i<=MAX; i++) {
        if(!d[i]) for(int j=i+i; j<=MAX; j+=i) d[j] = true;
    }
}

void print() {
    for(int i=m; i<=n; i++) 
        if(!d[i]) cout << i << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> m >> n;
    setD();
    print();
    return 0;
}
