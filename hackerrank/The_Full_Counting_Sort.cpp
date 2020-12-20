#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countSort function below.
void countSort(vector<vector<string>> arr) {
    vector<vector<string>> v(1000001);
    int max_n = -1;
    for(int i=0; i<=(arr.size()-1)/2; i++) {
        arr[i][1]="-";
    }
    for(int i=0; i<arr.size(); i++) {
        int idx = atoi(arr[i][0].c_str());
        v[idx].push_back(arr[i][1]);
        if(max_n < atoi(arr[i][0].c_str())) max_n = atoi(arr[i][0].c_str());   
    } 
    for(int i=0; i<=max_n; i++) {
        if(v[i].size()) {
            for(int j=0; j<v[i].size(); j++) cout << v[i][j] << " ";
        }
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
