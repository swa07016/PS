#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
int n;
vector<int> num;
int max_v = INT_MIN, min_v = INT_MAX;

/*
    연산자 배열이 주어졌을 때 식의 값 계산
*/
int calc(vector<int> selected) {
    int result = num[0];
    for(int i=1; i<num.size(); i++) {
        int oper = selected[i-1];
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

/*
    n-1 길이의 연산자 배열을 만들어서
    식의 값을 계산한 후 최댓값, 최솟값을 갱신
*/
void go(int pl, int mi, int mu, int di, vector<int> op) {
    if(op.size() == n-1) {
        int result = calc(op);
        max_v = max(max_v, result);
        min_v = min(min_v, result);
        return ;
    }
    if(pl-1 >= 0) {
        op.push_back(0);
        go(pl-1, mi, mu, di, op);
        op.pop_back();
    }
    if(mi-1 >= 0) {
        op.push_back(1);
        go(pl, mi-1, mu, di, op);
        op.pop_back();
    }
    if(mu-1 >= 0) {
        op.push_back(2);
        go(pl, mi, mu-1, di, op);
        op.pop_back();
    }
    if(di-1 >= 0) {
        op.push_back(3);
        go(pl, mi, mu, di-1, op);
        op.pop_back();
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int pl, mi, mu, di;
    
    cin >> n;
    num.resize(n);
    for(int i=0; i<n; i++) cin >> num[i];
    
    cin >> pl >> mi >> mu >> di;
    
    vector<int> v;
    go(pl, mi, mu, di, v);
    
    cout << max_v << "\n" << min_v;
    return 0;
}
