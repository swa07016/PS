#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> maxHeap;
int n, input;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> input;
        if(input == 0) {
            if(maxHeap.empty()) cout << "0\n";
            else {
                cout << maxHeap.top() << "\n";
                maxHeap.pop();
            }
        }
        else maxHeap.push(input);
    }

    return 0;
}