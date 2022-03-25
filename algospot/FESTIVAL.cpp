#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int c;
    cin >> c;
    for(int i=0; i<c; i++) {
        int n, l;
        vector<double> v;
        double min_a=1000000.0;
        cin >> n >> l;
        
        for(int j=0; j<n; j++) {
            double tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        
        for(int j=l; j<=n; j++) {
            int length = j;
            for(int k=0; k<n-length+1; k++) {
                double sum_t = 0.0;
                for(int m=k; m<k+length; m++) sum_t+=v[m];
                double avg = sum_t/length;
                if(avg < min_a) min_a = avg;
            }
        }
        cout << fixed;
        cout.precision(11);
        cout << min_a << "\n";
    }
    
    return 0;
}