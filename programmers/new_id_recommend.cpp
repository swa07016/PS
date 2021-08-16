#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    // step1
    string ans = "";
    for(int i=0; i<new_id.size(); i++) {
        if( 'A' <= new_id[i] && new_id[i] <= 'Z') 
            new_id[i] += ('a' - 'A');
    }  
    // step2
    for(int i=0; i<new_id.size(); i++) {
        char key = new_id[i];
        if('a' <= key && key <= 'z' || '0' <= key && key <= '9' || key == '-' || key == '_' || key == '.')
            ans += key;
    }
    // step3
    string new_ans = "";
    for(int i=0; i<ans.size(); i++) {
        char key = ans[i];
        if(key == '.') {
            for(int j=i+1; j<ans.size(); j++){
                if(ans[j] != '.') break;
                if(ans[j] == '.') ans[j] = 'X';
            }
        }
    }
    for(int i=0; i<ans.size(); i++) if(ans[i] != 'X') new_ans += ans[i];
    // step4
    if(new_ans[0] == '.') new_ans = new_ans.substr(1);
    if(new_ans[new_ans.size() - 1] == '.') new_ans = new_ans.substr(0, new_ans.size()-1);
    // step5
    if(new_ans.size() == 0) new_ans = "a";
    // step6
    if(new_ans.size() >= 16) {
        new_ans = new_ans.substr(0, 15);   
        if(new_ans[new_ans.size() - 1] == '.') new_ans = new_ans.substr(0, new_ans.size()-1);
    }
    // step7
    if(new_ans.size() <= 2) {
        int key = new_ans[new_ans.size() - 1];
        while(new_ans.size() <= 2) new_ans += key;
    }
    return new_ans;
}