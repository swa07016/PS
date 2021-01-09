#include <iostream>
#include <string>

using namespace std;
string A, B;
string result;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> A >> B;
    if(A.size() < B.size()) {
        int n = B.size() - A.size();
        for(int i=0; i<n; i++) A = '0' + A;
    }
    if(A.size() > B.size()) {
        int n = A.size() - B.size();
        for(int i=0; i<n; i++) B = '0' + B;
    }
    int carry=0;
    for(int i=A.size()-1; i>=0; i--) {
        int sum = carry + (A[i]-'0') + (B[i]-'0');
        if(sum >= 10) carry = sum/10;
        else carry = 0;
        result += to_string(sum%10);
    }
    if(carry) result += to_string(carry);
    for(int i=result.size()-1; i>=0; i--) cout << result[i];
    return 0;
}
