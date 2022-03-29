#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool visited[10];

// 수열을 공백으로 구분해서 출력해 줌
void print(vector<int> v) {
    for(int i=0; i<m; i++) cout << v[i] << " ";
    cout << "\n";
}

/*
    문제의 조건을 만족하는 수열을 찾음
    v :  현재까지 만들어진 수열
    cnt : 선택한 수의 개수
    cnt == m일 때, 즉 m개 선택했을 떄 수열을 출력해 줌.
*/
void go(vector<int> v, int cnt) {
    // 정답을 찾은 경우
    if(cnt == m) {
        print(v);
        return ;
    } 

    for(int i=1; i<=n; i++) {
        v.push_back(i);
        go(v, cnt+1);
        v.pop_back();    
    }
    return ;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    vector<int> v;
    go(v, 0);
    
    return 0;
}
