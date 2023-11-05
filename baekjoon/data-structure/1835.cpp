#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N; // 카드의 개수 입력 받음

    vector<int> cards(N + 1); // 1부터 시작하기 위해 N+1 크기의 벡터 생성

    // 역순으로 배열 구성
    for (int i = N; i > 0; --i) {
        cards[i] = i; // 현재 숫자를 해당 위치에 할당
        // i-1번만큼 가장 뒤로 옮기는 과정
        for (int j = 0; j < i; ++j) {
            int temp = cards[N]; // 배열의 마지막 원소를 temp에 임시 저장
            // 카드를 뒤에서부터 앞으로 한 칸씩 옮김
            for (int k = N - 1; k >= i; --k) {
                cards[k + 1] = cards[k];
            }
            cards[i] = temp; // temp에 저장했던 마지막 원소를 앞으로 옮김
        }
    }

    // 카드 순서 출력
    for (int i = 1; i <= N; ++i) {
        cout << cards[i] << endl; // i번째 카드 출력
    }

    return 0;
}
