#include <iostream>
#include <algorithm>

using namespace std;

#define N 24

struct Node {
	string name;
	int month, day, hour, minute;
	string status;
};

bool cmp(Node a, Node b) {
	if (a.name != b.name) {
		return a.name > b.name;
	}
	if (a.month != b.month) {
		return a.month < b.month;
	}
	if (a.day != b.day) {
		return a.day < b.day;
	}
	if (a.hour != b.hour) {
		return a.hour < b.hour;
	}
	if (a.minute != b.minute) {
		return a.minute < b.minute;
	}
}

int main() {
	int rate[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &rate[i]);
	}
	int n;
	Node node[1005];
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d:%d %s", node[i].name, &node[i].month, &node[i].day, &node[i].hour, &node[i].minute, &node[i].status);
	}
	sort(node, node+n, cmp);
	Node tmp = node[0];
	for (int i = 1; i < n; i++) {
		if (node[i].name != tmp.name || tmp.status == "off-line") {
			tmp = node[i];
		} else {
			if (node[i].status == "off-line") {
				
			} else {
				tmp = node[i];
			}
		}
	}
	return 0;
}
