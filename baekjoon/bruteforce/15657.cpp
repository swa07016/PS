#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<int> input;

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
    
    /* 
        고른 수열은 비내림차순이어야 하므로
        현재 수열의 가장 마지막에 있는 수에 해당하는 
        인덱스부터 고르도록 start변수 초기화
    
        find 함수는 반복자를 반환하므로 
        반복자 - input.begin()로 인덱스를 가져옴 
    */
    int start = v.empty() ? 0 
                : find(input.begin(), input.end(), v.back()) - input.begin();
    
    for(int i=start; i<n; i++) {
        v.push_back(input[i]);
        go(v, cnt+1);
        v.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    input.resize(n);
    for(int i=0; i<n; i++) cin >> input[i];
    sort(input.begin(), input.end());
    
    vector<int> v;        
    go(v, 0);

    return 0;
}
