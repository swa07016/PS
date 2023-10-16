#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    // 잃어버린 학생과 여벌을 가진 학생을 정렬합니다.
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 잃어버린 학생 중에서 여벌을 가진 학생을 찾아 제거합니다.
    for(int i=0; i<lost.size(); i++) {
        for(int j=0; j<reserve.size(); j++) {
            if(lost[i] == reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }
    
    // 잃어버린 학생에게 체육복을 빌려줍니다.
    // 이 때 바로 앞 번호나 바로 뒷 번호의 학생만 체육복을 빌려줄 수 있습니다.
    for(int i=0; i<lost.size(); i++) {
        for(int j=0; j<reserve.size(); j++) {
            if((reserve[j] == lost[i] - 1 || reserve[j] == lost[i] + 1) && lost[i] != -1 && reserve[j] != -1) {
                lost[i] = -1;  // 체육복을 빌린 학생 표시
                reserve[j] = -1;  // 체육복을 빌려준 학생 표시
                break;
            }
        }
    }
    
    // 아직 체육복을 받지 못한 학생의 수를 카운트합니다.
    int remain = 0;
    for(int i=0; i<lost.size(); i++) {
        if(lost[i] != -1) remain++;
    }
    
    // 전체 학생 수에서 체육복을 받지 못한 학생 수를 뺀 값을 반환합니다.
    return n - remain;
}
