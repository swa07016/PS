#include <iostream>
#include <stack>
#include <utility>

using namespace std;
int n;
int tower[500010];
stack<pair<int, int> > s; // index, height
int result[500010];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i=0; i<n; i++) cin >> tower[i];

    s.push(make_pair(n-1, tower[n-1]));

    for(int i=n-2; i>=0; i--) {
        int height = tower[i];
        int idx = i;

        while(true) {
            if(s.empty()) break;
            if(s.top().second > height) {
                s.push(make_pair(idx, height));
                break;
            }
            if(s.top().second < height) {
                result[s.top().first] = idx+1;
                s.pop();
            }
        }

        if(s.empty()) s.push(make_pair(idx, height));
    }

    for(int i=0; i<n; i++) cout << result[i] << " ";

    return 0;
}