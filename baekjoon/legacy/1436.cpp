#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    long long int num = 0;
    int cnt = 0, n;
    cin >> n;
    while(1) {
        if(cnt == n) {
            cout << num;
            break;
        }
        num++;
        string tmp = to_string(num);
        if(tmp.find("666")!=string::npos) cnt++;
    }
    return 0;
}