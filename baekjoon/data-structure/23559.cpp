#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
vector<pair<int, int>> v;
/*
    1. 기본적으로 모두 1000짜리 선택
    2. A, B의 차이가 큰것을 기준으로 정렬 (4000원 더 썼을 때, 값어치가 커지는 것 기준)
    3. 예산이 남아있는 동안 A로 업그레이드 가능하면 해주기.
*/
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
	cin >> n >> x;
	v.resize(n); 

	int sum = 0;  // 최종적으로 선택한 메뉴들의 맛의 합
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;  // 각 날짜의 5000원, 1000원짜리 메뉴의 맛 입력
		sum += v[i].second;  // 기본적으로 모든 날짜에 1000원짜리 메뉴를 선택한다고 가정하고 맛의 합을 더함
        x -= 1000;  // 예산에서 1000원씩 차감
	}

    // 5000원짜리와 1000원짜리 메뉴의 맛 차이를 기준으로 내림차순 정렬
	sort(v.begin(), v.end(), [](const pair<int, int> a, const pair<int, int> b) {
		return abs(a.first - a.second) > abs(b.first - b.second);
	});
	
    // 더 맛있는 메뉴로 업그레이드 가능한지 검사
	for (int i = 0; i < n; i++) {
		if (x >= 4000 && v[i].first - v[i].second >= 0) {  // 추가 예산이 충분하고, 5000원짜리가 더 맛있다면
			x -= 4000;  // 예산에서 4000원 차감 (1000원은 이미 차감했으므로 5000원 메뉴로 변경 시 4000원만 추가로 필요)
			sum += v[i].first - v[i].second;  // 맛의 합에 차이만큼 추가
		}
	}

	cout << sum;  // 최대 맛의 합 출력
}
