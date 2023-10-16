#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// 기본적으로 MaxHeap인데 세번 째 인자로 greater<int>를 넣어주면 최소힙으로 사용할 수 있다.
priority_queue<int, vector<int>, greater<int> > minHeap;
int n, x;

// 1927
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;

        if(x == 0) {
            if(minHeap.empty()) cout << "0\n";
            else {
                cout << minHeap.top() << "\n";
                minHeap.pop();
            }
        }

        else {
            minHeap.push(x);
        }
    }

    return 0;
}