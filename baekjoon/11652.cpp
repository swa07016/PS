#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<long long int> v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    long long int cnt = 1LL, key = v[0];
    long long int chk = 0LL, result = v[0];
    
    for(int i=1; i<N; i++) {
        if(v[i-1] == v[i]) cnt++;
        else cnt = 1;
        if(cnt > chk){ 
            chk = cnt;
            result = key;
        }
        key = v[i];
    }
    cout << result;
    return 0;
}