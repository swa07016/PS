#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
char matrix[20][20];
int ans[15];

void print() {
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}

int getSum(int start, int end) {
    int sum = 0;
    for(int i=start; i<=end; i++) sum += ans[i];
    return sum;
} 

/*
    index번째 수까지 결정되었을 때
    현재 수열이 부호 행렬을 만족하는지 여부를 반환
*/
bool isValid(int index) {
    for(int i=1; i<=index; i++) {
        for(int j=i; j<=index; j++) {
            int sum = getSum(i, j);
            if(sum < 0 && matrix[i][j] != '-') return false;
            if(sum > 0 && matrix[i][j] != '+') return false;
            if(sum == 0 && matrix[i][j] != '0') return false;

        } 
    }
    return true;
}

/*
    정답을 찾으면 해당 수열을 출력하고 종료
    matrix[index][index] 는 index번째 수의 부호임을 
    이용하여 index번째 수를 결정해 준다.
*/
void go(int index) {
    // 정답을 찾은 경우
    if(index == n + 1) {
        print();
        exit(EXIT_SUCCESS);
        return ;
    }

    if(matrix[index][index] == '0') {
        ans[index] = 0;
        if(isValid(index)) go(index + 1);
    }
    if(matrix[index][index] == '-') {
        for(int i=-1; i>=-10; i--) {
            ans[index] = i;
            if(isValid(index)) go(index + 1);
        }
    }
    if(matrix[index][index] == '+')  {
        for(int i=1; i<=10; i++) { 

            ans[index] = i;
            if(isValid(index)) go(index + 1);
        }
    }   
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string input;
    cin >> n;
    cin >> input;    
      
    int y = 1, x = 1;                    
    for(int i=0; i<input.size(); i++) {
        if(x>n) {
            y++;
            x = y;
        }
        matrix[y][x] = input[i];    
        x++;
    }                   
    go(1);
   
    return 0;
}