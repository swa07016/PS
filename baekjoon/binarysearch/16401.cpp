#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> snacks(N);
    for (int i = 0; i < N; i++) {
        cin >> snacks[i];
    }

    int left = 1, right = *max_element(snacks.begin(), snacks.end());
    int max_length = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long count = 0;
        for (int snack : snacks) {
            count += snack / mid;
        }

        if (count >= M) {
            max_length = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << max_length;
    return 0;
}
