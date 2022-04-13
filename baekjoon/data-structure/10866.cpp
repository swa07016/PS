#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque <int> dq;
int n, tmp;
string a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push_back") {
			cin >> tmp;
			dq.push_back(tmp);
		}
		else if (a == "push_front") {
			cin >> tmp;
			dq.push_front(tmp);
		}
		else if (a == "pop_front") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (a == "pop_back") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (a == "size") cout << dq.size() << "\n";
		else if (a == "empty") {
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (a == "front") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << "\n";
		}
		else if (a == "back") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << "\n";
		}
	}
	return 0;
}
