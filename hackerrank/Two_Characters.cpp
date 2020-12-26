#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
int ascii[27];


int check(int i, int j, string s) {
    vector<char> keys;
    keys.push_back(i+97);
    keys.push_back(j+97);
    string tmp = "";
    int cnt = 1;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i]==keys[0] || s[i]==keys[1]) tmp += s[i];
    }
    
    int chk=1;
    char t_a = tmp[0];
    char t_b = tmp[1];
    
    for(int i=0; i<tmp.size(); i=i+2) if(tmp[i]!=t_a)chk=-1;
    for(int i=1; i<tmp.size(); i=i+2) if(tmp[i]!=t_b)chk=-1;
    if(chk==1 && tmp[0]!=tmp[1]) return tmp.size(); 
    
    else return 0;
}

// Complete the alternate function below.
int alternate(string s) {
    int max_v = -1;
    for(int i=0; i<s.size(); i++) ascii[s[i]-97]++;
    for(int i=0; i<26; i++) {
        for(int j=i+1; j<27; j++) {
            if(ascii[i] && ascii[j]) {
                int tmp = check(i, j, s);
                if(tmp && (max_v < tmp)) max_v=tmp; 
            }
        }
    }
    if(max_v != -1) return max_v;
    else return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
