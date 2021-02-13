#include <iostream>

using namespace std;
int n, two_cnt, five_cnt;

void count(int num) {
    while(num%2==0) {
        two_cnt++;
        num = num/2;
    }
    while(num%5==0) {
        five_cnt++;
        num = num/5;
    }
    return ;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) count(i);
    if(two_cnt && five_cnt) {
        two_cnt < five_cnt ? cout << two_cnt : cout << five_cnt;
    } else cout << 0;
    return 0;
}