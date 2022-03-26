#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int tmp, sum;

void print() {
    sort(v.begin(), v.end());
    for(int i=0; i<7; i++) cout << v[i] << "\n";
    return ;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    v.resize(9);
    for(int i=0; i<9; i++) {
        cin >> tmp;
        sum += tmp;
        v[i] = tmp;
    }
    
    
    /*
        sum = 9명의 난쟁이들의 키의 합
        난쟁이가 아닌 2명을 찾는 법
        : 9명에서 2명을 뺐을 때 100이면 그 2명은 일곱난쟁이가 아님.
    */
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<9; j++) {
            if(sum - (v[i] + v[j]) == 100) {
                v[i] = v[j] = 987654321;
                print();
                return 0;
            }
        }
    }
    
    return 0;
}
