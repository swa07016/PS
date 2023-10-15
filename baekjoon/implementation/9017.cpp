#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, n, s;


// 9017
/*
    1. 상위 4명의 점수를 합하여 계산
    2. 합산 점수가 가장 낮은 팀이 우승
    3. 주자가 6명 미만인 경우, 탈락

    정렬을 이용해 풀이한다.
*/

class Team {
public:
    int teamNumber;
    vector<int> players;
    int playerCount = 0;

    int getFifthPlayerScore() {
        if(players.size() < 5) return 987654321;
        return players[4];
    }

    int getScore() {
        if(players.size() < 4) return -1;
        return players[0] + players[1] + players[2] + players[3];
    }
};

bool compare(Team& a, Team& b) {
    if(a.getScore() == b.getScore())
        return a.getFifthPlayerScore() < b.getFifthPlayerScore();
    
    return a.getScore() < b.getScore();
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> n;
        vector<Team> teams(n+1);
        vector<int> marking(n+1);
        for(int j=1; j<=n; j++) teams[j].teamNumber = j;
        for(int j=1; j<=n; j++) {
            cin >> s;
            teams[s].playerCount = teams[s].playerCount + 1;
            marking[j] = s;
        }



        for(int j=1; j<=n; j++)
            if(teams[j].playerCount < 6) teams[j].teamNumber = -1;


        int score = 1;
        for(int j=1; j<=n; j++) {
            if(teams[marking[j]].teamNumber != -1) {
                teams[marking[j]].players.push_back(score);
                score++;
            }
        }


        sort(teams.begin() + 1, teams.end(), compare);   

        for(int j=1; j<=n; j++) {
            if(teams[j].teamNumber != -1) {
                cout << teams[j].teamNumber << "\n";
                break;
            }
        }
    }

    return 0;
}