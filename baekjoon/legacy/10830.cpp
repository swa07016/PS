#include <iostream>
#include <vector>

using namespace std;
int n;

vector<vector<int>> I() {
    vector<vector<int>> tmp;
    tmp.resize(n);
    for(int i=0; i<n; i++) {
        tmp[i].resize(n);
        tmp[i][i] = 1;
    }
    return tmp;
}

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> tmp;
    tmp.resize(n);
    for(int i=0; i<n; i++) {
        tmp[i].resize(n);
        for(int j=0; j<n; j++) {
            int num = 0;
            for(int k=0; k<n; k++) num += (A[i][k]*B[k][j])%1000;
            tmp[i][j] = num%1000;
        }
    }
    return tmp;
}

vector<vector<int>> solve(vector<vector<int>> matrix, long long int b) {
    vector<vector<int>> ret = I();
    while(b > 0) {
        if(b%2!=0) {
            ret = multiply(ret, matrix);
            b--;
        }
        matrix = multiply(matrix, matrix);
        b = b/2;
    }
    return ret;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long int b;
    vector<vector<int>> matrix;
    cin >> n >> b;
    matrix.resize(n);
    for(int i=0; i<n; i++) {
        matrix[i].resize(n);
        for(int j=0; j<n; j++) cin >> matrix[i][j];
    }
    vector<vector<int>> ret = solve(matrix, b);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << ret[i][j] << " ";
        cout << "\n";
    }
    return 0;
}