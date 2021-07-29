#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
long long int M;
vector<long long int> tree;

long long int cutTreeHeight(int k) {
    long long int ret = 0;
    for(int i=0; i<N; i++) if(tree[i] > k) ret += (tree[i]-k);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    tree.resize(N);
    for(int i=0; i<N; i++) cin >> tree[i];
    
    long long int L = 1;
    long long int R = *max_element(tree.begin(), tree.end());
    long long int middle = (L+R)/2;
    long long int ans = 0;
    
    while(L<=R) {
        middle = (L+R)/2;
        if(cutTreeHeight(middle) >= M){
            ans = max(ans, middle);
            L = middle + 1;
        }
        if(cutTreeHeight(middle) < M) R = middle - 1;
    }
    cout << ans;
    
    return 0;
}
