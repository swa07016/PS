#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    int num = n;
    int cnt = 0;
    int k = 0;
    while(num) {
        k = num%10;
        num = num/10;
        if(k==0) continue;
        if(n%k == 0 )cnt++;
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
