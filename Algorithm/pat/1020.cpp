#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 30+5
struct Node{
	int index, value;
};

int a[N], b[N];
vector<Node> v;

bool cmp(Node a, Node b) {
	return a.index < b.index;
}

void dfs(int pos, int s, int e, int l) {
	if (s > e) return;
	int i = s;
	while (i < e && b[i] != a[pos]) i++;
	v.push_back({l, a[pos]});
	dfs(pos+i-e-1, s, i-1, 2*l+1);
	dfs(pos-1, i+1, e, 2*l+2);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	dfs(n-1, 0, n-1, 0);
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			cout << v[i].value;
		} else {
			cout << " " << v[i].value;
		}
		
	}
	return 0;
}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/
