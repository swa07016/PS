#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> num;
int result;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    num.resize(n);
    for(int i=0; i<n; i++) cin >> num[i];
    int s=0, e=0, sum=0;
    while(e <= n) {
        if(sum >= m) sum -= num[s++];
        else if(sum < m) sum += num[e++];
        if(sum == m) result++;
    }
    cout << result;
    return 0;
}
