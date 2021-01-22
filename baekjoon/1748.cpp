#include <iostream>
#include <cmath>
#include <string>

using namespace std;
string n;
int result;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    int size = n.size();
    result += (atoi(n.c_str()) - (int)pow(10, size-1) + 1)*size;
    size--;
    while(1) {
        result += ((int)pow(10, size) - (int)pow(10, size-1))*size;
        if(size == 0) break;
        size--;
    }
    cout << result;
    return 0;
}
