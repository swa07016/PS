#include <iostream>

using namespace std;

int parking[101];
int price[4];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int start, end;
    for(int i=1; i<=3; i++) {
        cin >> price[i];
    }

    for(int i=0; i<3; i++) {
        cin >> start >> end;
        for(int j=start; j<end; j++) {
            parking[j]++;
        }
    }

    for(int i=1; i<=100; i++) {
        int p = price[parking[i]];
        ans += (parking[i]*p);
    }

    cout << ans;

    return 0;
}