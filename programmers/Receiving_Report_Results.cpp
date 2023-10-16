#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class User {
public:
    string name; // 해당 유저의 이름
    set<string> reportUserList; // 해당 유저가 신고한 사람 목록
    int reportedCount = 0; // 해당 유저가 신고당한 횟수
    User(string name) {
        this->name = name;
    }
    int receivedMail = 0;
};

vector<string> split(string str) {
    int spacePosition = str.find(' ');
    
    vector<string> ret;
    ret.push_back(str.substr(0, spacePosition));
    ret.push_back(str.substr(spacePosition+1));
    
    // 공백 기준으로 문자열을 나누어 반환
    return ret;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<User> userList;
    
    // 유저 인스턴스들 생성
    for(int i=0; i<id_list.size(); i++) {
        userList.push_back(User(id_list[i]));
    }
    
    // 각 유저가 신고한 사람들의 목록을 생성
    for(int i=0; i<report.size(); i++) {
        vector<string> parsedReport = split(report[i]);
        string reporter = parsedReport[0];
        string reportee = parsedReport[1];
        
        for(int j=0; j<id_list.size(); j++) {
            // 신고자의 신고 목록에 reportee를 추가해준다.
            if(userList[j].name == reporter) {
                if(userList[j].reportUserList.find(reportee) == userList[j].reportUserList.end()){
                    userList[j].reportUserList.insert(reportee);
                }
            }
        }
    }
    
    // 각 유저별로 몇 번 신고되었는지 계산
    for(int i=0; i<id_list.size(); i++) {
        string myName = userList[i].name;
        for(int j=0; j<id_list.size(); j++) {
            if(userList[j].reportUserList.find(myName) != userList[j].reportUserList.end()) {
                userList[i].reportedCount++;
            }
        }
    }

    vector<string> stoppedUser;
    
    // k번 이상 신고된 유저를 정지 목록에 추가
    for(int i=0; i<id_list.size(); i++) {
        if(userList[i].reportedCount >= k) {
            stoppedUser.push_back(userList[i].name);
        }    
    }
    
    // 정지된 유저를 신고한 사람들에게 메일 횟수를 증가시킴
    for(int i=0; i<stoppedUser.size(); i++) {
        string stoppedUserName = stoppedUser[i];
        for(int j=0; j<id_list.size(); j++) {
            if(userList[j].reportUserList.find(stoppedUserName) != userList[j].reportUserList.end()) {
                userList[j].receivedMail++;
            }
        }
    }
    
    // 각 유저가 받은 메일의 수를 결과로 반환
    for(int i=0; i<id_list.size(); i++) {
        answer.push_back(userList[i].receivedMail);
    }
    
    return answer;
}
