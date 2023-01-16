#include <iostream>

using namespace std;
int n, k;
int d[500010];
int tmp[500010];
int cnt = 0;

// A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int A[], int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while (i <= q) // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    while (j <= r)  // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    i = p; t = 1;
    while (i <= r) {
        A[i++] = tmp[t++];
        cnt++;
        if(cnt == k) {
            cout << A[i-1];
            break;
        } 
    }  // 결과를 A[p..r]에 저장
}


void merge_sort(int A[], int p, int r) { // A[p..r]을 오름차순 정렬한다.
    if (p < r) {
        int q = (p + r) / 2;       // q는 p, r의 중간 지점
        merge_sort(A, p, q);      // 전반부 정렬
        merge_sort(A, q + 1, r);  // 후반부 정렬
        merge(A, p, q, r);        // 병합
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> d[i];
    merge_sort(d, 0, n-1);
    if(cnt < k) cout << "-1";
    return 0;
}