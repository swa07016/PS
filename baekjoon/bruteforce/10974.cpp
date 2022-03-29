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
    
    for(int i=0; i<n; i++) v[i] = i+1;
    
    // 순열 출력
    do { 
        for(int i=0; i<n; i++)
            cout << v[i] << " ";
        cout << "\n";
    } while(next_permutation(v.begin(), v.end())); 
    return 0;
}
