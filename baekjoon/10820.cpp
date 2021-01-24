#include <iostream>
#include <string>

using namespace std;
string str;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    while(1) {
        getline(cin, str);    
        if(!str.size()) break;
        int l = 0, u = 0, n = 0, e = 0;
        for(int i=0; i<str.size(); i++) {
            if('a'<=str[i] && str[i]<='z') l++;
            if('A'<=str[i] && str[i]<='Z') u++;
            if('0'<=str[i] && str[i] <='9') n++;
            if(str[i] == ' ') e++;
        }
        cout << l << " " << u << " " << n << " " << e << "\n";
    }
    return 0;
}
