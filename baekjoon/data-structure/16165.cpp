#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
int n, m;
map<string, vector<string> > teamList;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    

    cin >> n >> m;
    string teamName, memberName;
    int memberCount;
    for(int i=0; i<n; i++) {
        cin >> teamName;
        cin >> memberCount;
        for(int j=0; j<memberCount; j++) {
            cin >> memberName;
            teamList[teamName].push_back(memberName);
        }
    }

    string name;
    int type;

    for(auto iter = teamList.begin(); iter != teamList.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }

    for(int i=0; i<m; i++) {
        cin >> name >> type;
        if(type == 1) { 
            for(auto iter = teamList.begin(); iter != teamList.end(); iter++) { 
                if(find(iter->second.begin(), iter->second.end(), name) != iter->second.end()) {
                    cout << iter->first << "\n";
                    break;
                }
            }
        } else { // 해당 팀의 모든 팀원 출력
            vector<string> mList = teamList.find(name)->second;
            for(int j=0; j<mList.size(); j++) {
                cout << mList[j] << "\n";
            }
        }
    }

    return 0;
}