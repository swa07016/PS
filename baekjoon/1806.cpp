#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int n, m;
vector<int> num;
int result = INT_MAX;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    num.resize(n);
    for(int i=0; i<n; i++) cin >> num[i];
    int s=0, e=0, sum=0;
    while(e <= n) {
        if(sum >= m) {
            result = min(result, e-s);
            sum -= num[s++];
        }
        else if(sum < m) sum += num[e++];
    }
    if(result!=INT_MAX) cout << result;
    else cout << "0";
    return 0;
}