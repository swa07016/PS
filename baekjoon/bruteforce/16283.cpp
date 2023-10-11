#include <iostream>

using namespace std;

int a, b, n, w;
int sheep = -1;
int goat = -1;

int main () {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> a >> b >> n >> w;
    
    for(int i=1; i<n; i++) {
        int pSheep = i;
        int pGoat = n-i;

        int requiredW = pSheep * a + pGoat * b;
        if(requiredW == w) {
            if(sheep != -1) { // 이전에 이미 해를 찾은 경우..
                cout << "-1";
                return 0;
            }
            else {
                sheep = pSheep;
                goat = pGoat;
            }
        }
    }

    if(sheep == -1) cout << "-1";
    else cout << sheep << " " << goat;

    return 0;
}