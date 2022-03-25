#include <iostream>
#include <string>
#include <vector>

using namespace std;
int resultCnt;
int n, m;
vector<string> dna;
string resultDna;

void solve() {
    for(int i=0; i<m; i++) {
        int cnt[4] = {0};
        for(int j=0; j<n; j++) {
            char tmp = dna[j][i];
            switch(tmp){
                case 'A':
                    cnt[0]++;
                    break;
                case 'C':
                    cnt[1]++;
                    break;
                case 'G':
                    cnt[2]++;
                    break;
                case 'T':
                    cnt[3]++;
                    break;
                default:
                    break;
            }
        }
        int max_v = -1, idx;
        for(int j=3; j>=0; j--) {
            if(cnt[j]>=max_v) {
                max_v=cnt[j];
                idx = j;
            }
        }
        if(idx==0) resultDna += 'A';
        if(idx==1) resultDna += 'C';
        if(idx==2) resultDna += 'G';
        if(idx==3) resultDna += 'T';
        resultCnt += (n-max_v);
    }
    return ;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    dna.resize(n);
    for(int i=0; i<n; i++) cin >> dna[i];
    solve();
    cout << resultDna << "\n" << resultCnt;
    return 0;
}