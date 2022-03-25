#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;
vector<vector<int>> questions;
bool visited[10];
int result;

bool check(vector<int>& nums) {
    string num = to_string(nums[0]*100 + nums[1]*10 + nums[2]);
    for(int j=0; j<n; j++) {
        string key = to_string(questions[j][0]);
        int strike = 0, ball = 0;
        for(int k=0; k<3; k++) {
            if(num[k] == key[k]) strike++;
            for(int h=0; h<3; h++) {
                if(h!=k && key[h]==num[k]) ball++;
            }
        }
        if(strike != questions[j][1] || ball != questions[j][2]) return false;
    }
    return true;
}

void dfs(vector<int>& nums, int depth) {
    if(depth == 3) {
        if(check(nums)) result++;
        return ;
    }
    for(int i=1; i<=9; i++) {
        if(!visited[i]) {
            nums.push_back(i);
            visited[i] = true;
            dfs(nums, depth+1);
            nums.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    questions.resize(n);
    for(int i=0; i<n; i++) {
        int question, strike, ball;
        cin >> question >> strike >> ball;
        questions[i].push_back(question);
        questions[i].push_back(strike);
        questions[i].push_back(ball);
    }
    vector<int> nums;
    dfs(nums, 0);
    cout << result;
    return 0;
}