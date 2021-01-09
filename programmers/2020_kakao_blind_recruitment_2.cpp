#include <string>
#include <vector>

using namespace std;

bool isCorrectString(string p) {
    vector<char> check;
    for(int i=0; i<p.size(); i++) {
        if(p[i] == '(') check.push_back('(');
        else if(p[i] == ')'){
            if(check.size() && check.back() == '(') check.pop_back();
        }
    }
    if(check.size() == 0) return true;
    else return false;
}

bool isBalancedString(string p) {
    int openBracket = 0, closeBracket = 0;
    for(int i=p.size()-1; i>=0; i--) {
        if(p[i] == '(') openBracket++;
        if(p[i] == ')') closeBracket++;
    }
    if((openBracket && closeBracket) && ( openBracket == closeBracket )) return true;
    return false;
}

int cutIndex(string p) {
    for(int i=0; i<p.size(); i++) {
        string u = p.substr(0, i+1);
        if(isBalancedString(u)) return i;
    }
}

string solution(string p) {
    if(p=="") return "";
 
    int cutIdx = cutIndex(p);
    string u = p.substr(0, cutIdx+1);
    string v = "";
    if(cutIdx+1 == p.size()) v = "";
    else v = p.substr(cutIdx+1);
    if(isCorrectString(u)){
        return u + solution(v);
    } else {
        string tmp = "";
        tmp += '(';
        tmp += solution(v);
        tmp += ')';
        u = u.substr(1, u.size()-2);
        for(int i=0; i<u.size(); i++) {
            if(u[i] == '(') tmp += ')';
            else tmp += '(';
        }
        return tmp;
    }
}