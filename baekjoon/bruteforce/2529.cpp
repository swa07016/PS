#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>

using namespace std;
int k;
vector<char> op;
long long max_v = -1, min_v = LONG_LONG_MAX;
string max_s, min_s;

/*
    주어진 부등호 관계를 만족하는 지 검사
*/
bool isValid(string num) {
    for(int i=0; i<num.size()-1; i++) {
        if(op[i] == '<') {
            if(num[i] > num[i+1]) return false;
        } else {
            if(num[i] < num[i+1]) return false;
        }    
    }    
    return true;
}

/*
    k+1개의 수들의 가능한 순열을 탐색하며
    문제의 조건을 만족하는 경우 최댓값, 최솟값을 갱신
    

    ex) v = {0, 1, 2} 라면 아래와 같이 탐색
            0 1 2
            0 2 1
            1 0 2
            1 2 0
            2 0 1
            2 1 0
*/
void searchPermutation(vector<int> v) {
    do {
        string num_str = "";
        for(int i=0; i<v.size(); i++) num_str += to_string(v[i]);
        if(isValid(num_str)) {
            if(atoll(num_str.c_str()) > max_v) {
                max_s = num_str;
                max_v = atoll(num_str.c_str());
            } 
            if(atoll(num_str.c_str()) < min_v) {
                min_s = num_str;
                min_v = atoll(num_str.c_str());
            }
        }   
    } while(next_permutation(v.begin(), v.end()));
}

/*
    k+1개의 수를 선택해주는 함수
    선택된 k개의 수로 만들 수 있는 순열을
    탐색하기 위해 searchPermutation를 호출해준다.
*/

void solve(vector<int> selected) {
    do {
        vector<int> tmp;
        for(int i=0; i<=9; i++) if(selected[i]) tmp.push_back(i);
        
        searchPermutation(tmp);
        
    } while(prev_permutation(selected.begin(), selected.end()));
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> k;
    op.resize(k);
    for(int i=0; i<k; i++) cin >> op[i];             

    vector<int> num(10);    
    for(int i=0; i<k+1; i++) num[i] = 1;
    
    solve(num);
    cout << max_s << "\n" << min_s;
          
    return 0;
}