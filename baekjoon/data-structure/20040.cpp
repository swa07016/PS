#include <iostream>

using namespace std;
int n, m;
int a, b;
int parent[500010];
int ans = -1;

// 20040
/*
    n개의 점이 있고 m개의 간선 정보가 주어질 때,
    몇 번째 간선을 연결했을 때, 사이클이 생기는 지 파악하는 문제이다.

    방법)
    1. 입력된 간선들을 연결할 때마다 DFS를 이용해 정점들에 대해 사이클 여부를 판별해보기 <- O(n * m) 복잡도이므로 무조건 시간초과가 난다.
    2. 입력된 간선 (a, b)에 대해 find(a)와 find(b)가 같으면 이전 간선들에 의해 a, b가 연결되어있는 상태이므로 여기서 a와 b를 연결하는
       간선을 추가하면 사이클이 생겨버린다. <- Union-find 알고리즘을 활용해 이를 구현해보자

*/

int find(int x) {
    if(parent[x] == x) return parent[x]; 
    return parent[x] = find(parent[x]); // 경로 압축.. 이걸 하지 않으면 시간초과..
}

void Union(int x, int y) { // union 예약어가 있어서,, 첫글자를 대문자로..

    int px = find(x);
    int py = find(y);

    if(px != py) parent[px] = py; // x의 부모가 y의 부모를 가리키게 하면 된다.
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
     
    for(int i=0; i<n; i++) parent[i] = i; // 자기 자신을 루트 노드로 초기화..

    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        if(ans == -1) { // 정답을 아직 못 찾았다면..
            if(find(a) == find(b)) ans = i;
            Union(a, b);
        }
    }

    if(ans == -1) cout << "0";
    else cout << ans;

    return 0;
}