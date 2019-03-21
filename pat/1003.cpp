//
// Created by lin on 2019-03-05.
//

#include <iostream>
#include <cmath>

using namespace std;

#define N 500+5
#define inf 1<<30

int n, m, c1, c2, r[N], map[N][N];
int routes, dist, cnt;
bool vis[N];

void dfs(int pos, int dis, int p) {
    if (pos == c2) {
        if (dis == dist) {
            routes++;
            cnt = max(cnt, p);
        }
        if (dis < dist) {
            routes = 1;
            dist = dis;
            cnt = p;
        }
        return;
    }
    if (dist < dis) {
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && map[pos][i] != inf) {
            vis[i] = true;
            dfs(i, dis+map[pos][i], p+r[i]);
            vis[i] = false;
        }
    }
}

int main() {
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            map[i][j] = map[j][i] = inf;
        }
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        map[a][b] = map[b][a] = c;
    }
    dist = inf;
    vis[c1] = true;
    dfs(c1, 0, r[c1]);
    cout << routes << " " << cnt << endl;
    return 0;
}
