#include <iostream>
#include <algorithm>

using namespace std;

#define N 10000+5
 
struct Node {
	string name;
	string in;
	string out;
};

bool cmpIn(Node& a, Node& b) {
	return a.in < b.in;
}

bool cmpOut(Node& a, Node& b) {
	return a.out > b.out;
}

int main() {
	int n;
	cin >> n;
	Node node[N];
	for (int i = 0; i < n; i++) {
		cin >> node[i].name >> node[i].in >> node[i].out;
	}
	sort(node, node+n, cmpIn);
	cout << node[0].name << " ";
	sort(node, node+n, cmpOut);
	cout << node[0].name << endl;
	return 0;
} 
