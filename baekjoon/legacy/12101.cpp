#include <iostream>
#include <vector>

using namespace std;
int n, k, cnt;

void dfs(vector<int>& v, int sum) {
    if(sum > n) return ;
    if(sum == n) {
        cnt++;
        if(cnt == k) {
            for(int i=0; i<v.size(); i++) {
                if(i==v.size()-1) cout << v[i];
                else cout << v[i] << "+";
            }
            exit(EXIT_SUCCESS);
        }
        return ;
    }
    for(int i=1; i<=3; i++) {
        v.push_back(i);
        dfs(v, sum+i);
        v.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<int> v;
    dfs(v, 0);
    if(cnt == 0 || cnt<k) cout << "-1";
    return 0;
}
