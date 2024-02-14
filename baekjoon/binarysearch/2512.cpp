#include <iostream>

using namespace std;

int n, maxBudget = -1, minBudget = 100001;
int requestedBudget[10010];
int totalBudget, ans;

long long int sumOfBudget(int limitBudget) {
    long long int ret = 0;
    for(int i=1; i<=n; i++) {
        if(requestedBudget[i] < limitBudget) ret += requestedBudget[i];
        else ret += limitBudget;
    }

    return ret;
}

/*
    이분 탐색 시간복잡도) log N
    예산 합) long long 써야할 듯
*/
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> requestedBudget[i];
        maxBudget = max(maxBudget, requestedBudget[i]);
        minBudget = min(minBudget, requestedBudget[i]);
    }
    cin >> totalBudget;

    if(sumOfBudget(maxBudget) <= totalBudget) {
        cout << maxBudget;
        return 0;
    }

    int start = 1;
    int end = maxBudget;
    while(start <= end) {
        int mid = (start + end)/2;
        long long int budgetSum = sumOfBudget(mid);
        
        // cout << start << " " << end << " " << budgetSum << "\n";
        
        if(budgetSum <= totalBudget) start = mid + 1;
        else end = mid - 1;
    }
    cout << end;

    return 0;
}