#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n, cnt;

int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++) {
        char tmp[1010];
        cnt = 0;
        cin >> tmp;
        cout << isPalindrome(tmp) << " " << cnt << "\n";
    }
    return 0;
}