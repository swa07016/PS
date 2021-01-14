#include <iostream>
#include <vector>

using namespace std;
int a, b, c, n;
bool chk;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> n;
    for(int i=0; i<=300; i++) {
        for(int j=0; j<=300; j++) {
            for(int k=0; k<=300; k++) {
                if(a*i + b*j + c*k == n) {
                    cout << "1";
                    exit(0);
                }
            }
        }
    }
    cout << "0";
    return 0;
}