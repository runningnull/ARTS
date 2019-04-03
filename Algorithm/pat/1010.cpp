#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
#define ll long long

ll cal(char ch) {
	if (ch >= '0' && ch <= '9') {
		return (ch-'0');
	} else {
		return (ch-'a'+10);
	}
}

ll getNum(string a, ll radix) {
	ll result = 0;
	for (auto ch : a) {
		result *= radix;
		result += cal(ch);
		if (result < 0) {
			return -1;
		}
	}
	return result;
}

int main() {
	string n1, n2;
	ll tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (radix < 2) {
		cout << "Impossible" << endl;
		return 0;
	}
	ll a, b;
	if (tag == 2) {
		string tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	a = getNum(n1, radix);
	ll left = 2, right = a+1;
	for (auto ch : n2) {
		if (cal(ch) > left) {
			left = cal(ch)+1;	
		}
	}
	while (left <= right) {
		long long mid = (left+right) >> 1;
		b = getNum(n2, mid);
		if (a == b) {
			cout << mid << endl;
			return 0;
		}
		if (b == -1 || a < b) {
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	cout << "Impossible" << endl;
	return 0;
}

/*
12 14 1 10
110 110 1 2
12 c 1 10
12 c 2 10
8 8 1 6
*/
