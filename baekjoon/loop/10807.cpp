#include <iostream>

using namespace std;
int d[110];
int n, v;
int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++) cin >> d[i];
    cin >> v;
    for(int i=0; i<n; i++) if(d[i] == v) cnt++;
    cout << cnt; 
    return 0;
}