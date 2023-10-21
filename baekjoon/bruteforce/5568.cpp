#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
vector<int> cards;
vector<int> selects;
set<string> integers;

vector<string> makeStringVector() {

    vector<string> ret;
    for(int i=0; i<n; i++) {
        if(selects[i] == 1) ret.push_back(to_string(cards[i]));
    }

    return ret;
}

void print() {
    for(int i=0; i<n; i++) {
        cout << selects[i] << " ";
    }
    cout << "\n";
}

string makeString(vector<string> a){
    string ret = "";
    
    for(int i=0; i<a.size(); i++) {
        ret += a[i];
    }
    return ret;
}

void insertCommand(vector<string> integer) {

    sort(integer.begin(), integer.end());

    do { 
        string result = makeString(integer);
        if(integers.find(result) == integers.end()) {
        integers.insert(result);
    }
    } while(next_permutation(integer.begin(), integer.end()));

    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    cards.resize(n);
    selects.resize(n);

    // 카드 입력
    for(int i=0; i<n; i++) {
        cin >> cards[i];
    }

    // select 선택 초기화
    for(int i=0; i<k; i++) selects[i] = 1;

    sort(cards.begin(), cards.end());


    do {


        vector<string> integer = makeStringVector();
    
        // integer로 나온거 순열돌려서 insert해주어야 함.
        insertCommand(integer);

    }
    while(prev_permutation(selects.begin(), selects.end()));

    cout << integers.size();

    return 0;
}