#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int dat[21];

int main(void) {
	fastio;

	int M;
	cin >> M;

	unordered_set<int> mySet;

	string cmd;
	int x;
	for (int i = 0; i < M; i++) {
		cin >> cmd;

		if (cmd == "add") {
			cin >> x;

			mySet.insert(x);
			dat[x] = 1;
		}
		else if (cmd == "remove") {
			cin >> x;

			mySet.erase(x);
			dat[x] = 0;
		}
		else if (cmd == "check") {
			cin >> x;

			if (dat[x] == 1) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (cmd == "toggle") {
			cin >> x;

			if (dat[x] == 1) {
				mySet.erase(x);
				dat[x] = 0;
			}
			else {
				mySet.insert(x);
				dat[x] = 1;
			}
		}
		else if (cmd == "all") {
			for (int i = 1; i <= 20; i++) {
				mySet.insert(i);
				dat[i] = 1;
			}
		}
		else if (cmd == "empty") {
			mySet.clear();
			memset(dat, 0, sizeof(dat));
		}
	}

	return 0;
}