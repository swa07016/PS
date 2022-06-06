#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
long long int ans = -1;
int n;
vector<string> words;
vector<int> num(30);
set<int> idxs;

/*
    단어를 숫자로 변환해주는 함수
    ex) GCF -> 783
*/
long long int convert(string s) {
    long long int w = 1;
    long long int res = 0;
    for(int i=s.size()-1; i>=0; i--) {
        long long int n = num[s[i] - 'A'];
        res += n*w;
        w *= 10;
    }
    return res;
}


/*
    알파벳 대문자별 숫자를 배정해주는 함수
*/
void setNum(vector<int> selected) {
    int i=0;
    for(auto iter = idxs.begin(); iter != idxs.end(); iter++) {
        int idx = *iter;
        num[idx] = selected[i++];
    }
}

/*
    1. 단어들에 존재하는 알파벳의 개수만큼 숫자를 고른다(selected vector)
        - 고른 숫자들을 이용해 알파벳 별로 숫자를 배정해준다.
          (setNum)
    2. 알파벳 별 숫자를 이용해 최댓값을 갱신해준다.
*/
void solve(vector<int> selected) {
    do {
        long long int sum = 0;
        setNum(selected);
        for(int i=0; i<words.size(); i++) {
            sum += convert(words[i]);
        }
        ans = max(ans, sum);
    } while(next_permutation(selected.begin(), selected.end()));
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            if(idxs.find(s[j] - 'A') == idxs.end())
                idxs.insert(s[j] - 'A');
        }
        words.push_back(s);
    }
    
    vector<int> v(10);
    for(int i=0; i<idxs.size(); i++) v[i] = 1;
    
    do {
        vector<int> selected;
        for(int i=0; i<v.size(); i++) 
            if(v[i]) selected.push_back(i);
        solve(selected);
    } while(prev_permutation(v.begin(), v.end()));

    cout << ans;

    return 0;
}
