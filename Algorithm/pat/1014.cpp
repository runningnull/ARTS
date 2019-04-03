#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define N 1000+5

struct Node {
	int line;
	int begin_time;
	int end_time;
	int proces_time;
	bool operator<(const Node tmp) const {
		if (tmp.end_time == end_tinme) {
			return tmp.line < line;
		}
		return tmp.end_time < end_time;
	}
};


int main() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	Node node[N];
	for (int i = 0; i < k; i++) {
		cin >> node[i].proces_time;
		if (i < n)
	}
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
//		cout << 
	}
	return 0;
}
