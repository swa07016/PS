#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k;

/*
    c++ prev_permutation을 이용해서 combination을 구현하는 문제.
    
    1) select vector에 0과 1을 섞어서 넣어준다.
        1 : 선택하고자 하는 원소
        0 : 선택하지 않고자 하는 원소
        - 이 과정은 [1, 1, 1, 1, 1, 1, 0, 0]으로 
          세팅된 벡터의 순열을 순회(prev_permutation 사용)
          하며 가능한 조합을 구할 수 있다.
          
    2) select[i]가 1이면 출력 대상 vector의 값 v[i]를 출력해준다.
        ex) select : [1, 1, 1, 1, 1, 0,  0,  1]
                 v : [1, 2, 3, 5, 8, 13, 21, 34]
            output : 1 2 3 5 8 34
*/
void print(vector<int> v, vector<int> select) {
    do {
        for(int i=0; i<k; i++) 
            if(select[i]) cout << v[i] << " ";
        
        cout << "\n";
    } while(prev_permutation(select.begin(), select.end()));
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    while(true) {
        cin >> k;
        if(k == 0) break;
        
        vector<int> v(k);
        vector<int> select(k, 0);
        
        for(int i=0; i<k; i++) cin >> v[i];
        for(int i=0; i<6; i++) select[i] = 1;
        
        print(v, select);
        cout << "\n";
    }
    return 0;
}
