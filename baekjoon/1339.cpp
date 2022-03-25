#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;
int result = -1;
bool alphabetChk[26];
vector<string> words;
vector<char> alphabet;
bool visited[10];

int findIdx(char key) {
    for(int i=0; i<alphabet.size(); i++) if(alphabet[i]==key) return i;
}

int calc(vector<int>& v) {
    vector<int> nums;
    int alphaNum[26] = {0};
    int sum = 0;
    
    for(int i=0; i<v.size(); i++) {
        alphaNum[alphabet[i]-65] = v[i];
    }
    
    for(int i=0; i<words.size(); i++) {
        int t=1;
        for(int j=words[i].size()-1; j>=0; j--) {
            sum += (alphaNum[words[i][j]-65]*t);
            t*=10;
        }
    }
    
    return sum;
}

void dfs(int m, int depth, vector<int>& v) {
    if(depth == m) {
        result = max(result, calc(v));
        return ;
    }
    
    for(int i=0; i<10; i++) {
        if(!visited[i]) {
            v.push_back(i);
            visited[i] = true;
            dfs(m, depth+1, v);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n;
    words.resize(n);
    for(int i=0; i<n; i++) cin >> words[i]; 
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<words[i].size(); j++) alphabetChk[words[i][j]-65] = true;
    }
    
    for(int i=0; i<26; i++) {
        if(alphabetChk[i]) {
            char c = i+65;
            alphabet.push_back(c);
        }
    }
    
    vector<int> v;
    dfs(alphabet.size(), 0, v);
    cout << result;
    return 0;
}