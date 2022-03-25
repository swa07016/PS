#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
vector<string> description;
vector<string> uid;
map<string, string> user;
vector<string> answer;

vector<string> solution(vector<string> record) {
    for(int i=0; i<record.size(); i++) {
        string pivot = record[i];
        int space1, space2;
        for(int j=0; j<pivot.size(); j++) if(pivot[j] == ' ') { space1 = j; break; }
        for(int j=pivot.size()-1; j>=0; j--) if(pivot[j] == ' ') { space2 = j; break; }
        string cmd = pivot.substr(0, space1);
        string id = pivot.substr(space1+1, space2-space1-1);
        string name = pivot.substr(space2+1);

        if(cmd == "Enter") {
            uid.push_back(id);
            description.push_back("님이 들어왔습니다.");
            user[id] = name;
        }
        if(cmd == "Leave") {
            uid.push_back(id);
            description.push_back("님이 나갔습니다.");
        }
        if(cmd == "Change") {
            user[id] = name;    
        }    
    }
    for(int i=0; i<uid.size(); i++) {
        answer.push_back(user[uid[i]] + description[i]);
    }
    
    return answer;
}