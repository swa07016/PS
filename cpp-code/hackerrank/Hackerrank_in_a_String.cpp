#include <bits/stdc++.h>

using namespace std;
int chk[10];



// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string key = "hackerrank";
    string str = s;
    string tmp = "";
    for(int i=0; i<key.size(); i++) {
        for(int j=0; j<str.size(); j++) {
            if(str[j] == key[i]) {
                tmp += key[i];
                if(j!=str.size()-1) str = str.substr(j+1);
                else str = "";
                break;
            }
        }
    }
    if(tmp == key) return "YES";
    else return "NO";
} 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
