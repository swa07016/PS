#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
int n, k;
vector<int> answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; i++) q.push(i);
    int iter = 1;
    while(!q.empty()) {
        if(iter%k == 0) {
            int tmp = q.front();
            q.pop();
            answer.push_back(tmp);
        }
        else {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        iter++;
    }
    cout << "<";
    for(int i=0; i<n; i++) if(i!=n-1)cout << answer[i] << ", ";
    cout << answer[n-1] << ">";
    return 0;
}
