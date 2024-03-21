#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;
long long int n;
long long int sol[100010]; // 용액 배열
long long int s, e;
long long int ansS, ansE, ansM, bestDiff = LLONG_MAX;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> sol[i];

    sort(sol+1, sol+1+n);

    for(int i=1; i<=n; i++) { // 3개 중 하나는 고정해두고서 수행
        long long int keyIndex = i;
        long long int select = sol[keyIndex];

        s = 1;
        e = n;
        if(s == keyIndex) s++;
        if(e == keyIndex) e--;

        while(s < e) {
            long long int curr = sol[s] + sol[e] + select;
            if(abs(curr) < bestDiff) {
                bestDiff = abs(curr);
                ansS = s;
                ansM = keyIndex;
                ansE = e;
            }

            if(curr == 0) break;
            if(curr < 0) s++;
            if(curr > 0) e--;
             
            if(s == keyIndex) s++;
            if(e == keyIndex) e--;
        }
    }

    vector<int> answer;
    answer.push_back(sol[ansS]); answer.push_back(sol[ansM]); answer.push_back(sol[ansE]);
    sort(answer.begin(), answer.end());
    for(int i=0; i<3; i++) 
        cout << answer[i] << " ";
    return 0;
}