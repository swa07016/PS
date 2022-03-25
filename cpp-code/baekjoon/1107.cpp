#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;
int N, M;
int result = INT_MAX;

int check(int num, vector<bool>& btn) {
    if(num == 100) return abs(100-N);
    string strNum = to_string(num);
    for(int i=0; i<strNum.size(); i++) {
        int idx = strNum[i] - '0';
        if(!btn[idx]) return -1;
    }
    return (int)strNum.size() + abs(N-atoi(strNum.c_str()));
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<bool> btn(10, true);
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int tmp;
        cin >> tmp;
        btn[tmp] = false;
    }
    for(int i=0; i<=N+abs(100-N); i++) {
        int ret = check(i, btn);
        if(ret!=-1) result = min(result, ret);
    }
    cout << result;
    return 0;
}