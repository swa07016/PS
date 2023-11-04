#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int nA, nB, input;
set<int> setA;
vector<int> duplicateList;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> nA >> nB;
    for(int i=0; i<nA; i++) {
        cin >> input;
        setA.insert(input);
    }

    for(int i=0; i<nB; i++) {
        cin >> input;
        if(setA.find(input) != setA.end()) duplicateList.push_back(input);
    }

    if(duplicateList.size() == setA.size()) {
        cout << "0";
        return 0;
    }

    sort(duplicateList.begin(), duplicateList.end());
    cout << setA.size() - duplicateList.size() << "\n";

    for(int i=0; i<duplicateList.size(); i++) {
        int elem = duplicateList[i];
        auto iter = setA.find(elem);
        setA.erase(iter);
    }

    for(auto iter = setA.begin(); iter != setA.end(); iter++) {
        cout << *iter << " ";
    }

    return 0;
}