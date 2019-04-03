#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define N 100+5

vector<int> vv[N];
int n, maps[N], cnt = 0;

void dfs(int pos, int level) {
	cnt = max(cnt, level);
	if (vv[pos].size() == 0 ) {
		maps[level]++;
		return;
	}
	for (auto& it : vv[pos]) {
		dfs(it, level+1);
	}
}

int main() {
	int m;
	cin >> n >> m;
	int a, b, c;
	memset(maps, 0, sizeof(maps));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			cin >> c;
			vv[a].push_back(c);
		}
	}
	dfs(1, 0);
	for (int i = 0; i < cnt; i++) {
		cout << maps[i] << " ";
	}
	cout << maps[cnt] << endl;
	return 0;
}

/*
2 1
01 1 02
*/
