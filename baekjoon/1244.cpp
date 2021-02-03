#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> switchs;

void boy(int num) {
    for(int i=1; i<=n; i++) {
        if(i%num == 0) switchs[i] = (switchs[i] ? 0 : 1);
    }
    return ;
}

bool safe(int x) {
    return 1<=x && x<=n;
}

void girl(int num) {
    int start = num, end = num;
    while(1) {
        if(switchs[start] != switchs[end]){ 
            start++;
            end--;
            break;
        }
        if(!safe(start-1) || !safe(end+1)) break;
        start--;
        end++;
    }
    for(int i=start; i<=end; i++) switchs[i] = (switchs[i] ? 0 : 1);
    return ;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    switchs.resize(n+1);
    for(int i=1; i<=n; i++) cin >> switchs[i];
    cin >> m;
    for(int i=0; i<m; i++) {
        int gender, num;
        cin >> gender >> num;
        if(gender == 1) boy(num);
        if(gender == 2) girl(num);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        cout << switchs[i] << " ";
        cnt++;
        if(cnt == 20) {
            cout << "\n";
            cnt = 0;
        }
    }
    return 0;
}
