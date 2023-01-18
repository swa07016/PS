#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
vector<pair<int, int> > field;
int k;
int maxHeight = -1, maxWidth = -1;
int direction, dist;
int area;
bool isDiff = false;
const int ANGLE_CNT = 6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    for(int i=0; i<6; i++) {
        cin >> direction >> dist;
        field.push_back(make_pair(direction, dist));
    }
    for(int i=0; i<6; i++) {
        if(field[i].first == 3 || field[i].first == 4) maxHeight = max(maxHeight, field[i].second);
        if(field[i].first == 1 || field[i].first == 2) maxWidth = max(maxWidth, field[i].second);
    }
    area = maxHeight * maxWidth;
    for(int i=0; i<6; i++) {
        if(field[(i+1)%ANGLE_CNT].first == field[(i+3)%ANGLE_CNT].first) {
            if(field[i%ANGLE_CNT].first == field[(i+2)%ANGLE_CNT].first) {
                area -= (field[(i+1)%ANGLE_CNT].second * field[(i+2)%ANGLE_CNT].second);
                isDiff = true;
                break;
            } else {
                area -= (field[(i+2)%ANGLE_CNT].second * field[(i+3)%ANGLE_CNT].second);
                isDiff = true;
                break;
            }
        }
    }
    
    cout << area*k;
    return 0;
}