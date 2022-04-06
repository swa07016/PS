#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<char> input;
int L, C;


/*
    문제의 조건을 만족하는지 여부 반환
        1) 최소 한 개의 모음과 최소 2개의 자음으로 구성
        2) 오름차순
*/
bool isValidPassword(string password) {
    int moeum = 0, jaeum = 0;
    for(int i=0; i<L; i++) {
         char c = password[i];
         if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') moeum++;
         else jaeum++;       
    }
    if(moeum >= 1 && jaeum >= 2) return true;
    else return false;
}

/*
    C개의 문자들 중에 L개를 골라서 암호를 만들고,
    해당 암호가 문제의 조건을 만족하면 출력

    input = { a, c, i, s, t, w }
    selected = { 1, 1, 1, 1, 0, 0 }
    일 때, acis 출력
*/
void printPasswordList(vector<bool> selected) {
    do {
         string password = "";
         for(int i=0; i<C; i++) if(selected[i]) password += input[i];
             
         if(isValidPassword(password)) {
             cout << password << "\n";    
         }
             
     } while(prev_permutation(selected.begin(), selected.end()));        
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> L >> C;
    input.resize(C);
    for (int i = 0; i < C; i++) cin >> input[i];
    sort(input.begin(), input.end());

    vector<bool> v(C, false);
    for(int i=0; i<L; i++) v[i] = true; 
    printPasswordList(v);
       

    return 0;
}