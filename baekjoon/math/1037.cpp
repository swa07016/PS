#include <iostream>
#include <cmath>

using namespace std;
int N, min_v = 987654321, max_v = -1;
int input;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    /* 
        진약수를 오름차순으로 나열했을 때 양 끝 값을 곱하면
        답을 구할 수 있음
    */
    for(int i=0; i<N; i++) {
        cin >> input;
        min_v = min(min_v, input);
        max_v = max(max_v, input);
    }
    
    cout << min_v * max_v;
    return 0;
}
