#include <iostream>

using namespace std;

int otable[300][300];
int ntable[300][300];

/*
    테두리찾기가 핵심

*/
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M, R;
    cin >> N >> M >> R;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> otable[i][j];
        }
    }

    //배열 복사
    copy(&otable[0][0], &otable[299][300], &ntable[0][0]);

    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            // 모든 부분이 회전하므로 따로 확인할 필요 X
            if(false) continue;

            // 테두리 찾기
            // 0, 0, N-1, M-1
            int l = min(min(y, N-1-y), min(x, M-1-x));
            int mx = l, my = l, Mx = M - 1 - l, My = N - 1 - l;
        
            // 회전양 줄이기
            int b = max(1, (My - my + Mx - mx) * 2);
            int r = R % b;

            // 진짜 돌리기
            int ny = y, nx = x;
            while(r > 0) {
                if (ny == my) {
                    if(nx - mx < r) {
                        r -= nx - mx;
                        nx = mx;
                        
                    } else {
                        nx -= r;
                        r = 0;
                    }
                }
                if(nx == mx) {
                    if(My - ny < r) {
                        r -= My - ny;
                        ny = My;
                    } else {
                        ny += r;
                        r = 0;
                    }
                }
                if(ny == My) {
                    if(Mx - nx < r) {
                        r -= Mx - nx;
                        nx = Mx;
                    } else {
                        nx += r;
                        r = 0;
                    }
                }
                if(nx == Mx) {
                    if(ny - my < r) {
                        r -= ny - my;
                        ny = my;
                    } else {
                        ny -= r;
                        r = 0;
                    }
                    
                }



            }
            // 대입
            ntable[ny][nx] = otable[y][x];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << ntable[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}