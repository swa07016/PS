#include <iostream>
#include <string>
#include <deque>
using namespace std;
string cmd;
int t;
int n;
deque <int> dq;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> cmd;
		cin >> n;
		char tmp;
		cin >> tmp;
		for (int j = 1; j <= n; j++) {
			int num;
			if (j == n) cin >> num;
			else {
				cin >> num;
				cin >> tmp;
			}
			dq.push_back(num);
		}
		cin >> tmp;
	
		int flag = 1;
		int chk = 1;
		for (int j = 0; j < cmd.size(); j++) {
			if (cmd[j] == 'R') flag *= -1;
			else if (cmd[j] == 'D') {
				if (dq.empty()) { cout << "error"; chk = -1; break; }
				else {
					if (flag == 1)dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (chk == 1) {
			if (flag == 1) {
				cout << "[";
				for (int j = 0; j < dq.size(); j++) {
					if (j == dq.size() - 1)cout << dq[j];
					else cout << dq[j] << ",";
				}
				cout << "]";
			}
			else {
				cout << "[";
				for (int j = dq.size()-1; j >= 0; j--) {
					if (j == 0)cout << dq[j];
					else cout << dq[j] << ",";
				}
				cout << "]";
			}
		}
		cout << "\n";
		dq.clear();
	}
	return 0;
}