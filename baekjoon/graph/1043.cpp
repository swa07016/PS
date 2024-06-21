#include <iostream>
#include <vector>

using namespace std;

int n, m;
int p;
int person;
int ans;
int tp;

vector<int> trueP;
int parent[60];
vector<vector<int> > party;



int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int px = find(x);
    int py = find(y);

    if(px == py) return;
    parent[py] = px;
}

bool isUnion(int x, int y) {
    return find(x) == find(y);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // parent 초기화
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) 
        parent[i] = i;

    cin >> tp;
    for(int i=1; i<=tp; i++)  {
        cin >> person;
        trueP.push_back(person);
    }
        
    for(int i=1; i<=m; i++) {
        cin >> p;
        vector<int> v(p+1);
        for(int j=1; j<=p; j++) 
            cin >> v[j];
        
        party.push_back(v);
    }
    
    // 연관관계 있는 사람들끼리 그룹짓기
    for(int i=0; i<m; i++) {
        for(int j=1; j<party[i].size() - 1; j++) {
            Union(party[i][j], party[i][j+1]);
        }
    }
    
    for(int i=0; i<m; i++) {
        bool isPossible = true;
        for(int j=1; j<party[i].size(); j++) {
            for(int k=0; k<trueP.size(); k++) {
                if(isUnion(trueP[k], party[i][j])) {
                    isPossible = false;
                    break;
                }

                if(!isPossible) break;
            }
        }
        if(isPossible) ans++;
    }

    cout << ans;
    return 0;
}