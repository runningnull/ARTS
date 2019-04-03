#include <iostream>

using namespace std;

int main() {
	int n, m, result = 0, index = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (index < m) {
			result += 6*(m-index)+5;
		} else {
			result += 4*(index-m)+5;
		}
		index = m;
	}
	cout << result << endl;
	return 0;
}
