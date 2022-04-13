#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
string cmd;
queue <int> q;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> cmd;
		if(cmd.compare("push") == 0) {
			int num;
			cin >> num;
			q.push(num);
		}
		if(cmd.compare("pop") == 0) {
			if(q.empty()==true) cout << "-1" << "\n";
			else {
			    cout << q.front() << "\n";
			    q.pop();
			}
		}
		if(cmd.compare("size") == 0) {
			cout << q.size() << "\n";
		}
		if(cmd.compare("empty") == 0) {
			if(q.empty()==true) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		if(cmd.compare("front") == 0) {
			if(q.empty() == true) cout << "-1" <<"\n";
			else cout << q.front() << "\n";
		}
		if(cmd.compare("back") == 0) {
			if(q.empty() == true) cout << "-1" <<"\n";
			else cout << q.back() << "\n";
		}
	}
	return 0;
}
