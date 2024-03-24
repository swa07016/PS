#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n);
    for (int i = 0; i < n; ++i) {
        cin >> sushi[i];
    }

    // 해시 맵으로 윈도우 내의 스시 종류 관리
    unordered_map<int, int> count;
    int uniqueSushi = 0; // 윈도우 내 고유 스시 종류 수
    int maxUnique = 0; // 최대 고유 스시 종류 수

    // 초기 윈도우 설정
    for (int i = 0; i < k; ++i) {
        if (count[sushi[i]]++ == 0) uniqueSushi++;
    }
    maxUnique = uniqueSushi + (count[c] == 0); // 쿠폰 스시를 포함한 경우 고려

    // 슬라이딩 윈도우 이동
    for (int i = 1; i < n; ++i) {
        // 윈도우에서 제외되는 스시 처리
        if (--count[sushi[i - 1]] == 0) uniqueSushi--;

        // 새로 포함되는 스시 처리
        int newSushiIndex = (i + k - 1) % n; // 원형으로 순회
        if (count[sushi[newSushiIndex]]++ == 0) uniqueSushi++;

        // 쿠폰 스시 포함 여부 확인
        int currentUnique = uniqueSushi + (count[c] == 0);
        maxUnique = max(maxUnique, currentUnique);
    }

    cout << maxUnique;

    return 0;
}
