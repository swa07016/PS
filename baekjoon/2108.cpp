#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int n;
vector<int> arr;
int positive[4001], negative[4001];

double average() {
    int sum = 0;
    for(int i=0; i<n; i++) sum+=arr[i];
    double d_sum = sum;
    return round(d_sum/n);
}

int median() {
    return arr[n/2];
}

int mode() {
    int max_cnt = -1;
    vector<int> modes;
    for(int i=0; i<n; i++) {
        if(arr[i] < 0) {
            negative[abs(arr[i])]++;
        }
        else {
            positive[arr[i]]++;
        }
    }
    for(int i=0; i<=4000; i++) {
        if(positive[i] > max_cnt) max_cnt = positive[i];
        if(negative[i] > max_cnt) max_cnt = negative[i];
    }
    for(int i=0; i<=4000; i++) {
        if(positive[i] == max_cnt) modes.push_back(i);
        if(negative[i] == max_cnt) modes.push_back(i*(-1));
    }
    if(modes.size()==1) return modes[0];
    
    sort(modes.begin(), modes.end());
    return modes[1]; 
}

int range() {
    int max_v = -1, min_v = 987654321;
    for(int i=0; i<n; i++) {
        if(arr[i] > max_v) max_v = arr[i];
        if(arr[i] < min_v) min_v = arr[i];
    }
    return max_v - min_v;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    cout << average() << "\n";
    cout << median() << "\n";
    cout << mode() << "\n";
    cout << range();
    return 0;
}