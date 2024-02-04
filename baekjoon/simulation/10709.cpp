#include <iostream>
#include <string>

using namespace std;
int h, w;
string tmp;
// index 1, 1부터 사용
char cloud[110][110];
int answer[110][110];

void init() {
    for(int i=0; i<=h; i++) {
        for(int j=0; j<=w; j++) {
            cloud[i][j] = '.';
            answer[i][j] = -1;
        }
    }
}

bool notExistCloud() {
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) if(cloud[i][j] == 'c') return false;
    }

    return true;
}

void updateAnswer(int currentTime) {
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            if(answer[i][j] == -1 && cloud[i][j] == 'c') answer[i][j] = currentTime; 
        }
    }
}

void moveCloud() {
    for(int i=1; i<=h; i++) {
        for(int j=w; j>=0; j--) {
            cloud[i][j+1] = cloud[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;

    init();

    for(int i=1; i<=h; i++) {
        cin >> tmp;
        for(int j=1; j<=w; j++) {
            cloud[i][j] = tmp[j-1];
        }
    }

    int currentTime = 0;
    while(true) {
        if(notExistCloud()) break;

        updateAnswer(currentTime);
        moveCloud();
        currentTime++;
    }

    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) cout << answer[i][j] << " ";
        cout << "\n";
    }

    return 0;
}