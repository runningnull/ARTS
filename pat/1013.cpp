#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define N 1000+2

bool vis[N], map[N][N];
int n, des;

void initial() {
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			map[i][j] = map[j][i] = false;
		}
	}
}

void dfs(int pos) {
	vis[pos] = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && map[pos][i] && i!=pos) {
			dfs(i);
		} 
	}
}

int main() {
	int m, k, a, b;
	initial();
//	cin >> n >> m >> k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
//		cin >> a >> b;
		scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = true;
	}
	for (int i = 0; i < k; i++) {
		cin >> des;
		memset(vis, false, sizeof(vis));
		int ans = 0;
		vis[des] = true;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && j != des) {
				dfs(j);
				ans++;
			}
		}
//		cout << (ans-1) << endl;
		printf("%d\n", ans-1);
	}
	return 0;
} 
