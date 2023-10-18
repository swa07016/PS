#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(int a, int b) const {
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

priority_queue<int, vector<int>, Compare > absHeap;
int n, input;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> input;
        if(input == 0) {
            if(absHeap.empty()) cout << "0\n";
            else {
                cout << absHeap.top() << "\n";
                absHeap.pop();
            }
        }
        else absHeap.push(input);
    }

    return 0;
}