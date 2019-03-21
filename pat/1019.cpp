#include <iostream> 

using namespace std;

#define N 10000+5

int main() {
	
	int n, m;
	cin >> n >> m;
	int cnt = 0, num[N];
	while (n > 0) {
		num[cnt++] = n%m;
		n /= m;
	}
	bool flag = true;
	for (int i = 0; i <= cnt/2; i++) {
		if (num[i] != num[cnt-i-1]) {
			flag = false;break;
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	for (int i = cnt-1; i > 0; i--) {
		cout << num[i] << " ";
	}
	cout << num[0] << endl;
	return 0;
} 
