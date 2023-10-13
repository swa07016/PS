#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 13335
/*
    n : 트럭의 개수
    w : 다리의 길이
    L : 다리의 최대하중
*/
int n, w, L;
queue<int> trucks;
vector<int> bridge;
int ans = 1;


// 다리에 트럭을 진입시킬 수 있는지 판단하는 함수
bool isPossible(int x) {
    int total = 0;
    for(int i=0; i<w; i++) total += bridge[i];
    if(total + x > L) return false; // x를 다리에 두었을 때 L을 초과하면 안된다...
    return true;    
}   

// 다리에 트럭을 진입시키는 함수
void insert(int x) {
    bridge[w-1] = x;
}

// 다리에 존재하는 트럭을 단위 길이씩 이동시키는 함수
void move() {
    for(int i=1; i<w; i++) {
        bridge[i-1] = bridge[i];
    }
    bridge[w-1] = 0;
    ans++;
}

// 다리에 남아있는 트럭을 이동시키는 함수 (필요한 단위 시간을 추가해준다..)
void postMove() {
    int position = -1;
    for(int i=w-1; i>=0; i--) {
        if(bridge[i]) {
            position = i;
            break;
        }
    }

    if(position != -1) ans += (position + 1);
}

int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> w >> L;
    bridge.resize(w);

    for(int i=0; i<n; i++) {
        int input;
        cin >> input; 
        trucks.push(input);
    }

    while(!trucks.empty()) {
        int truck = trucks.front();
        if(isPossible(truck)) {
            trucks.pop();
            insert(truck);        
        }
        move();
    }

    // 트럭을 다리에 다 넣었으면 다리에서 트럭이 다 탈출할때까지의 시간을 더해주어야 함.
    postMove();

    cout << ans;

    return 0;
}