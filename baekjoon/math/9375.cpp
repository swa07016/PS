#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for(int i=0; i<t; i++) {
        map<string, vector<string> > clothes;
        cin >> n;
        for(int j=0; j<n; j++) {
            string name, type;
            cin >> name >> type;
            auto iter = clothes.find(type);
            if(iter == clothes.end()) {
                vector<string> tmp;
                tmp.push_back(name);
                clothes.insert(make_pair(type, tmp));
            } else {
                iter->second.push_back(name);
            }
        }
        int result = 1;
        for(auto iter = clothes.begin(); iter != clothes.end(); iter++) {
            result *= (iter->second.size()+1);
        }
        cout << result-1 << "\n";
    }
    return 0;
}