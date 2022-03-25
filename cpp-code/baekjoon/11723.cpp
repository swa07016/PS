#include <iostream>
#include <string>

using namespace std;
int m, x;
string cmd;
bool num[21];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> cmd;
        if(cmd!="all" && cmd!="empty") cin >> x;
        
        if(cmd == "add") {
            if(!num[x]) num[x] = true; 
        } else if(cmd == "remove") {
            if(num[x]) num[x] = false;
        } else if(cmd == "check") {
            if(num[x]) cout << "1\n";
            else cout << "0\n";
        } else if(cmd == "toggle") {
            if(num[x]) num[x] = false;
            else num[x] = true;
        } else if(cmd == "all") {
            for(int i=1; i<=20; i++) num[i] = true;
        } else if(cmd == "empty") {
            for(int i=1; i<=20; i++) num[i] = false;
        }
    } 
    return 0;
}
