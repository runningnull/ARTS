#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

#define N 2000+5
#define map unordered_map

struct Node {
	int c,m,e,a;
};

bool cmpc(Node a, Node b) {
	return a.c > b.c;
}

bool cmpm(Node a, Node b) {
	return a.m > b.m;
}

bool cmpe(Node a, Node b) {
	return a.e > b.e;
}
bool cmpa(Node a, Node b) {
	return a.a > b.a;
}
int minn(int a, int b, int c, int d) {
	return min(min(a, b), min(c, d));
}

int main() {
	int n,m;
	cin >> n >> m;
	Node node[N];
	string name;
	map<string , Node> pmap;
	for (int i = 0; i < n; i++) {
		cin >> name >> node[i].c >> node[i].m >> node[i].e;
		node[i].a = (node[i].c + node[i].m + node[i].e) / 3;
//		cout << node[i].a << endl;
		pmap[name] = node[i];
	} 
	map<int, int> cmap;
	map<int, int> mmap;
	map<int, int> emap;
	map<int, int> amap;
	sort(node, node+n, cmpc);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (cmap.find(node[i].c) == cmap.end()) {
			cmap[node[i].c] =cnt;
		}
		cnt++;
	}
	cnt = 1;
	sort(node, node+n, cmpm);
	for (int i = 0; i < n; i++) {
		if (mmap.find(node[i].m) == mmap.end()) {
			mmap[node[i].m] = cnt;	
		}
		cnt++;
	}
	cnt = 1;
	sort(node, node+n, cmpe);
	for (int i = 0; i < n; i++) {
		if (emap.find(node[i].e) == emap.end()) {
			emap[node[i].e] = cnt;
		}
		cnt++;
	}
	cnt = 1;
	sort(node, node+n, cmpa);
	for (int i = 0; i < n; i++) {
		if (amap.find(node[i].a) == amap.end()) {
			amap[node[i].a] = cnt;
		}
		cnt++;
	}
	string str;
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (pmap.find(str) != pmap.end()) {
			Node p = pmap[str];
			int rc = cmap[p.c];
			int rm = mmap[p.m];
			int re = emap[p.e];
			int ra = amap[p.a];
			int mm = minn(rc, rm, re, ra);
 			if (ra == mm) {
				cout << ra << " A" << endl;
			} else if (rc == mm) {
				cout << rc << " C" << endl;
			} else if (rm == mm) {
				cout << rm << " M" << endl;
			} else if (re == mm) {
				cout << re << " E" << endl;
			}
		} else {
			cout << "N/A" << endl;
		}
	}
	return 0;
}
