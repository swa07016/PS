#include <iostream>

using namespace std;

int memo[110][110][110];

int w(int a, int b, int c) {
    int& ret = memo[a+50][b+50][c+50];
    if(a<=0 || b<=0 || c<=0) return ret = 1;
    if(ret) return ret;
    if(a>20 || b>20 || c>20) return ret = w(20, 20, 20);
    if(a<b && b<c) return ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else return ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b, c;
    while(1) {
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
    return 0;
}