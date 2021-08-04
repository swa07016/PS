#include <iostream>
#include <vector>
#include <climits>

using namespace std;
vector<int> v;
int n, input;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.push_back(INT_MIN);
    for(int i=0; i<n; i++) {
        cin >> input;
        if(v.back() < input) v.push_back(input);
        else {
            auto iter = lower_bound(v.begin(), v.end(), input);
            *iter = input;    
        }
    }
    cout << v.size()-1;
    return 0;
}
