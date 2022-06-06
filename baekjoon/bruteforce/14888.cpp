#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int n;
vector<int> num;
vector<int> op;
int max_v = INT_MIN, min_v = INT_MAX;

int calc() {
    int result = num[0];
    for(int i=1; i<num.size(); i++) {
        int oper = op[i-1];
        switch(oper) {
            case 0:
                result += num[i];
                break;
            case 1: 
                result -= num[i];
                break;
            case 2:
                result *= num[i];
                break;
            case 3:
                result /= num[i];
                break;
            default:
                break;
        }
    }
    return result;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    num.resize(n);
    for(int i=0; i<n; i++) cin >> num[i];
    for(int i=0; i<4; i++) {
        int tmp;
        cin >> tmp;
        for(int j=0; j<tmp; j++) op.push_back(i);
    }
    
    do {
        int result = calc();
        max_v = max(max_v, result);
        min_v = min(min_v, result);
    } while(next_permutation(op.begin(), op.end()));
    
    cout << max_v << "\n" << min_v;
    return 0;
}
