#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> A;
vector<char> opers;
bool visited[11];
int min_v = 1000000000, max_v = -1000000000;

int calculate(vector<char>& o) {
    int ret = A[0];
    for(int i=1; i<n; i++) {
        if(o[i-1] == '+') ret += A[i];
        if(o[i-1] == '-') ret -= A[i];
        if(o[i-1] == '*') ret *= A[i];
        if(o[i-1] == '/') ret /= A[i];
    }
    return ret;
}

void dfs(vector<char>& v, int depth) {
    if(depth == n-1) {
        int result = calculate(v);
        max_v = max(max_v, result);
        min_v = min(min_v, result);
        return;
    }
    for(int i=0; i<n-1; i++) {
        if(!visited[i]) {
            visited[i] = true;
            v.push_back(opers[i]);
            dfs(v, depth+1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    for(int i=0; i<4; i++) {
        int tmp;
        cin >> tmp;
        if(i==0) for(int j=0; j<tmp; j++) opers.push_back('+'); 
        if(i==1) for(int j=0; j<tmp; j++) opers.push_back('-');
        if(i==2) for(int j=0; j<tmp; j++) opers.push_back('*');
        if(i==3) for(int j=0; j<tmp; j++) opers.push_back('/');
    }
    vector<char> v;
    dfs(v, 0);
    cout << max_v << "\n" << min_v;
    return 0;
}