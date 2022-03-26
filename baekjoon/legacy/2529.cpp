#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int k;
vector<char> arr;
bool visited[10];
vector<string> results;

string make_string(vector<int>& v) {
    string tmp = "";
    for(int i=0; i<k+1; i++) tmp += to_string(v[i]);
    return tmp;
}

bool check(vector<int>& v) {
    for(int i=1; i<k+1; i++) {
        if(arr[i-1] == '<') {
            if(v[i-1] > v[i]) return false;
        }
        if(arr[i-1] == '>') {
            if(v[i-1] < v[i]) return false;
        }
    }
    return true;
}


void dfs(vector<int>& v, int depth) {
    if(depth == k+1) {
        if(check(v)) {
            results.push_back(make_string(v));
        }
        return ;
    }
    for(int i=0; i<=9; i++) {
        if(!visited[i]) {
            v.push_back(i);
            visited[i] = true;
            dfs(v, depth+1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> k;
    for(int i=0; i<k; i++) {
        char tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    vector<int> v;
    dfs(v, 0);
    if(results.size() == 1) cout << results[0] << "\n" << results[0];
    else cout << results[results.size()-1] << "\n" << results[0];
    return 0;
}