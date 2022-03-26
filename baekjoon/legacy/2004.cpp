#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
long long int n, m;

pair<long long int, long long int> count(long long int num) {
    long long int two_cnt = 0, five_cnt = 0;
    
    for(long long int i=2; i<=num; i*=2) two_cnt += num/i;
    for(long long int i=5; i<=num; i*=5) five_cnt += num/i;
    
    pair<long long int, long long int> ret;
    ret = make_pair(two_cnt, five_cnt);
    
    return ret;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cout << min(count(n).first - count(n-m).first - count(m).first, count(n).second - count(n-m).second - count(m).second);
    return 0;
}