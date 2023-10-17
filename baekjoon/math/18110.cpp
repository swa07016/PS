#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> levelList;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    if(n == 0) {
        cout << "0";
        return 0;
    }

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        levelList.push_back(input);
    }

    int exceptedCount = round(n * 0.15);

    sort(levelList.begin(), levelList.end());

    int sumOfGoodLevel = 0;
    for(int i=exceptedCount; i<n-exceptedCount; i++) 
        sumOfGoodLevel += levelList[i];

    cout << round(sumOfGoodLevel / (double)(n - exceptedCount * 2));

    return 0;
}