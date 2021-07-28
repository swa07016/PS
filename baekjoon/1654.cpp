#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long int> Lan;
int n, k;

long long int cutLanCount(long long int len) {
    long long int ret = 0;
    for(int i=0; i<Lan.size(); i++) {
        ret += (Lan[i]/len);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    for(int i=0; i<k; i++) {
        int tmp;
        cin >> tmp;
        Lan.push_back(tmp);
    }
    
    long long int R = *max_element(Lan.begin(), Lan.end());    
    long long int L = 1;
    long long int M = (R+L)/2;
    long long int ans = 0;
    while(L<=R) {
        M = (R+L)/2;
        if(cutLanCount(M) >= n){
            if(ans < M) ans = M;
            L = M+1;  
        } 
        if(cutLanCount(M) < n) R = M-1;
    }
    cout << ans;
    return 0;
}