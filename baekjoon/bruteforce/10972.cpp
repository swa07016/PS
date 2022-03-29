#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++) cin >> v[i];
    
    /* 
        다음 순열이 존재하면 출력,
        아니라면 -1 출력
    */
    if(next_permutation(v.begin(), v.end())) 
        for(int i=0; i<n; i++) cout << v[i] << " ";
    else cout << "-1";

    return 0;
}
