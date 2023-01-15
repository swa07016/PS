#include <iostream>

using namespace std;
int piece[6] = {1, 1, 2, 2, 2, 8};
int input;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i=0; i<6; i++) {
        cin >> input;
        cout << piece[i] - input << " ";
    }

    return 0;
}