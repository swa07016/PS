#include <iostream>
#include <vector>

using namespace std;
int fibonacci[46];
int n, input;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    fibonacci[1] = 1;
    for(int i=2; i<=45; i++) fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> input;
        int sum = 0;
        vector<int> ans;
        for(int j=45; j>=1; j--) {
            int fibo = fibonacci[j];
            if(sum + fibo <= input) {
                sum += fibo;
                ans.push_back(fibo);
            }
        }

        for(int j=ans.size()-1; j>=0; j--) {
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}