#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> B;
vector<long long int> A;
long long int minB, maxB;

bool check(long long int nx) {
    if (minB <= nx && nx <= maxB && find(B.begin(), B.end(), nx) != B.end() && find(A.begin(), A.end(), nx) == A.end()) {
        A.push_back(nx);
        return true;
    }
    return false;
}

bool dfs(long long int x) {
    if (x % 3 == 0) {
        if (check(x / 3)) {
            return dfs(x / 3);
        }
        if (check(x * 2)) {
            return dfs(x * 2);
        }
    } else {
        if (check(x * 2)) {
            return dfs(x * 2);
        }
    }
    return A.size() == B.size();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    long long int n, input;
    cin >> n;
    for (long long int i = 0; i < n; ++i) {
        cin >> input;
        B.push_back(input);
    }

    minB = *min_element(B.begin(), B.end());
    maxB = *max_element(B.begin(), B.end());

    for (long long int x : B) {
        A.clear();
        A.push_back(x);
        if (dfs(x)) {
            for (long long int a : A) {
                cout << a << " ";
            }
            break;
        }
    }

    return 0;
}
