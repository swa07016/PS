#include <iostream>

using namespace std;

int leftSum, rightSum;
int stone, n;
int diff, ans;

int weight[7] = { 1, 2, 5, 10, 20, 50, 100 };

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n;
    
    cin >> stone; leftSum += stone;
    cin >> stone; rightSum += stone;

    for(int i=2; i<n; i++) {
        cin >> stone;

        if(leftSum == rightSum) leftSum += stone;
        else {
            if(leftSum < rightSum) leftSum += stone;
            else rightSum += stone;
        }
        
    }
    diff = abs(leftSum - rightSum);

    for(int i=6; i>=0; i--) {
        int w = weight[i];
        while(diff >= w) {
            diff -= w;
            ans++;
        }
    }

    cout << ans;

    return 0;
}