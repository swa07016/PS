#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, input;
vector<int> t;
priority_queue<int, vector<int>, greater<int> > consents;

bool compare(int a, int b) {
    return a > b;
}

/*
    
    1 4 4 8 1
    8 4 4 1 1
    
    내림차순 정렬하는 이유?? 노는 콘센트를 최소화하기 위해
    만약에 오름차순이나 정렬을 안하면 마지막쯤엔 하나의 콘센트만 일하고 
    나머지 애들은 하나의 콘센트가 일하는거 지켜보면서 놀고있음.

    4 8
    8 8
    9 1 -> 1 9
    2 9

    ans) 9
*/
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> input;
        t.push_back(input);
    }

    for(int i=0; i<m; i++) consents.push(0);
    
    sort(t.begin(), t.end(), compare);
    
    for(int i=0; i<t.size(); i++) {
        int needTime = t[i];

        int lessBusyConsent = consents.top(); consents.pop();
        consents.push(needTime + lessBusyConsent);
    }

    while(consents.size() > 1) consents.pop();
    cout << consents.top();
    return 0;
}