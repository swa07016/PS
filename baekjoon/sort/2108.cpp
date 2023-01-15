#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int n, sumV;
int d[500010], dP[4010], dM[4010];
int minV = 5000, maxV = -5000;

int getMostFrequentValue() {
    int key = -1;
    int res;
    vector<int> v;
    for(int i=0; i<=4000; i++) if(dP[i] > key) key = dP[i];
    for(int i=1; i<=4000; i++) if(dM[i] > key) key = dM[i];
    for(int i=0; i<=4000; i++) if(dP[i] == key) v.push_back(i);
    for(int i=1; i<=4000; i++) if(dM[i] == key) v.push_back(i*(-1));

    if(v.size() == 1) return v[0];
    sort(v.begin(), v.end());
    return v[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        d[i] = tmp;
        sumV += tmp;
        minV = min(minV, tmp);
        maxV = max(maxV, tmp);
        if(tmp >= 0) dP[tmp]++;
        else dM[tmp*(-1)]++;
    }

    sort(d, d+n);

    cout << (int)round((double)sumV/n) << "\n";
    cout << d[n/2] << "\n";
    cout << getMostFrequentValue() << "\n";
    cout << maxV - minV << "\n";
    return 0;
}