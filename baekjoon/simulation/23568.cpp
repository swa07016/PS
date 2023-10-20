#include <iostream>
#include <vector>

using namespace std;

class Triple {
public:
    int ii;
    char jj;
    int kk;
    Triple(int i, char j, int k){
        this->ii = i;
        this->jj = j;
        this->kk = k;
    }
};

int current;
int i, k;
char j;
int n;

vector<Triple> triples;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int t=0; t<n; t++) {
        cin >> i >> j >> k;
        triples.push_back(Triple(i, j, k));
    } 

    cin >> current;

    while(!triples.empty()) {
        for(int t=0; t<triples.size(); t++) {
            if(triples[t].ii == current) {
                if(triples[t].jj == 'L') {
                    current -= triples[t].kk;
                } else {
                    current += triples[t].kk;
                }
                triples.erase(triples.begin() + t);
                break;
            }
        }
    }

    cout << current << "\n";

    return 0;
}
