#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int x, y;
    cin >> x >> y;
    if(x>0 && y>0) cout << "1";
    else if(x>0 && y<0) cout << "4";
    else if(x<0 && y>0) cout << "2";
    else cout << "3";
    return 0;
}