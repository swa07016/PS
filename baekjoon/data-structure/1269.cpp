#include <iostream>
#include <set>

using namespace std;
int a, b, cnt;
set<int> setA, setB;
int input, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;
    for(int i=0; i<a; i++) {
        cin >> input;
        setA.insert(input);
    }
    for(int i=0; i<b; i++) {
        cin >> input;
        setB.insert(input);
    }
    res = setA.size() + setB.size();
    for(auto iter = setB.begin(); iter != setB.end(); iter++) {
        if(setA.find(*iter) != setA.end()) cnt++;
    }
    res -= cnt; cnt=0;
    for(auto iter = setA.begin(); iter != setA.end(); iter++) {
        if(setB.find(*iter) != setB.end()) cnt++;
    }
    res -= cnt;
    cout << res;
    return 0;
}