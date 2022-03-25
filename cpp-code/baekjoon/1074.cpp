#include <iostream>
#include <cmath>

using namespace std;
int n, r, c, cnt;


void solve(int y, int x, int size) {
    if(size==1) {
        if(y==r && x==c) {
            cout << cnt;
            exit(0);
        }
        ++cnt;
        return ;
    }
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            int ny = y + (size/2)*i;
            int nx = x + (size/2)*j;
            if((ny<=r && r<ny+size/2) && (nx<=c && c<nx+size/2)) solve(ny, nx, size/2);
            else cnt += (size/2)*(size/2);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> r >> c;
    int size = pow(2, n);
    solve(0, 0, size);
    return 0;
}
