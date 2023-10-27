#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T;
int n;

class Applicant {
public:
    int documentRank;
    int interviewRank;
    Applicant() {}
    Applicant(int d, int i) : documentRank(d), interviewRank(i) {}
};

bool compare(const Applicant& a, const Applicant& b) {
    return a.documentRank < b.documentRank;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n;
        vector<Applicant> applicantList(n);
     
        for(int i = 0; i < n; i++) {
            int d, in;
            cin >> d >> in;
            applicantList[i] = Applicant(d, in);
        } 

        sort(applicantList.begin(), applicantList.end(), compare);

        int ans = 1;  // 첫 번째 지원자는 반드시 선발됩니다.
        int key = applicantList[0].interviewRank;  // 첫 번째 지원자의 면접 순위를 key로 설정

        for(int i = 1; i < n; i++) {
            if(applicantList[i].interviewRank < key) {
                ans++;
                key = applicantList[i].interviewRank;  // key 갱신
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
