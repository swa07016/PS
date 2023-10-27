#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int hp;
    bool existRobot;
    Node(int hp) {
        this->hp = hp;
        this->existRobot = false;
    }
};
int N, K, ans;
vector<Node> belt;

bool isExit() {
    int count = 0;
    for(int i=0; i<2*N; i++) {
        if(belt[i].hp == 0) count++;
    }
    if(count >= K) return true;
    return false;
}

void spinBelt() {
    Node lastNode = belt[2*N-1];

    for(int i=2*N-1; i>=1; i--) {
        belt[i] = belt[i-1];
    }
    belt[0] = lastNode;
}

void popRobot() {
    if(belt[N-1].existRobot) belt[N-1].existRobot = false;
}

void executeStep() {
    // 벨트를 한칸씩 회전시킨다.
    spinBelt();
    
    // 내릴 수 있으면 내리셈
    popRobot();

    // 가장먼저 벨트에 올라간 로봇부터, 이동할 수 있으면 이동하센.
    // 해당 칸에 로봇이 없으며, 해당 칸의 내구도가 1이상이어야 함.
    // 역순으로 탐색해야함.. 왜냐면 가장 먼저 올라간 로봇 먼저 이동시켜야하니까..
    for(int i=N-2; i>=0; i--) {
        if(belt[i].existRobot) { // 이 칸에 존재하면            
            // 다음 칸을 보고 되면 이동시킴
            if(!belt[i+1].existRobot && belt[i+1].hp >= 1) {
                belt[i+1].existRobot = true;
                belt[i+1].hp--;
                belt[i].existRobot = false;
            } 
        }
    }
    
    // 내릴 수 있으면 내리셈
    popRobot();

    // 올릴 수 있으면 로봇을 첫번째 칸에 올림
    if(belt[0].hp >= 1) {
        belt[0].existRobot = true;
        belt[0].hp--;
    } 

    // 종료 체크는 메인에서 따로함~~
}

// 20055
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    for(int i=0; i<2*N; i++) {
        int h;
        cin >> h;
        belt.push_back(Node(h));
    }  
    
    while(true) {
        executeStep();
        ans++;
        if(isExit()) break;
    }

    cout << ans;

    return 0;
}