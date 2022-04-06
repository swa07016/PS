#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int ans = INT_MAX;
int n;
int capability[25][25];

/*
    두 팀의 능력치의 차이를 반환
*/
int getCapabilityDifference(vector<int> start, vector<int> link) {
    int start_total = 0, link_total = 0;
    for(int i=0; i<start.size()-1; i++) {
        for(int j=i+1; j<start.size(); j++) {
             int a = start[i], b = start[j];
             start_total += (capability[a][b] + capability[b][a] );   
        }
    }
    
    for(int i=0; i<link.size()-1; i++) {
        for(int j=i+1; j<link.size(); j++) {
             int a = link[i], b = link[j];
             link_total += (capability[a][b] + capability[b][a] );   
        }
    }
   

    return abs(start_total - link_total);
}

/*
    가능한 팀 조합들에 대해
    능력치 차이를 갱신해줌.
*/
void makeTeamCombination(vector<int> selected) {
     do {
         vector<int> start, link;
         for(int i=0; i<n; i++) {
             if(selected[i]) start.push_back(i+1);
             else link.push_back(i+1);
         }
         ans = min(ans, getCapabilityDifference(start, link)); 
     } while(prev_permutation(selected.begin(), selected.end()));
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) cin >> capability[i][j];
    
    for(int k = 1; k<=n/2; k++) {
        vector<int> selected(n, 0); 
        for(int i=0; i<k; i++) selected[i] = 1;

        makeTeamCombination(selected);     
    }
    cout << ans;
    
    return 0;
}