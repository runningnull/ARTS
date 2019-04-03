#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int reverse(int n, int r) {
	int result = 0;
	while (n != 0) {
		result = result*r + n%r;
		n /= r;	
	}
	return result;
}

int main() {
	int a, b;
	while (cin >> a) {
		if (a < 0) {
			return 0;
		}
		cin >> b;
		if (isPrime(a) && isPrime(reverse(a, b))) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
} 
