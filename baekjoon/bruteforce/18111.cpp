#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int n, m;
int b;
int board[510][510];
vector<pair<int, int> > answerList;

const int INVENTORY_MAX_SIZE = 64000000;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

// 18111
/*
    땅의 높이를 x로 맞출때 필요한 비용을 중의 최소값을 찾아보자.
    x : 0~maxHeight
*/
int main() {
    
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> b;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) 
            cin >> board[i][j];
    }

    // maxPossiableHeight를 구해주어야 맞음.. 256까지 무턱대고 탐색하면 70퍼정도에서 틀림..
    /*
        지형의 높이를 균등하게 맞추기 위해서는 평균 높이 이상으로 설정할 수 없다. 
        만약 평균 높이보다 더 높게 설정하려 한다면, 
        그 높이에 맞추기 위한 블록의 수가 총 블록의 개수를 초과하게 된다.
    */
    int totalBlocks = b;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) 
            totalBlocks += board[i][j];
    }
    int maxPossibleHeight = totalBlocks / (n * m);


    for(int t=0; t<=maxPossibleHeight; t++) {
        int amountOfBlock = b;
        int keyHeight = t;
        int sec = 0;
        bool isPossible = true;

        // 블록을 제거하여 인벤토리에 블록을 늘리는 것이 먼저
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] > keyHeight) {
                    int diff = board[i][j] - keyHeight;
                    sec += diff * 2;
                    amountOfBlock += diff;
                }
            }
        }


        if(amountOfBlock > INVENTORY_MAX_SIZE) amountOfBlock = INVENTORY_MAX_SIZE;

        // 인벤토리의 블록들로 높이가 낮은것들을 채워줌.
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] < keyHeight) {

                    // 가용할 수 있는 블럭이 남지 않았으면
                    if(amountOfBlock <= 0) {
                        isPossible = false;
                        break;
                    }

                    int diff = keyHeight - board[i][j];
                    sec += diff;
                    amountOfBlock -= diff;
                }
            }
        }

        if(isPossible) {
            answerList.push_back(make_pair(sec, keyHeight));
        }
    }

    sort(answerList.begin(), answerList.end(), compare);

    cout << answerList[0].first << " " << answerList[0].second;

    return 0;
}