#include <iostream>
#include <cmath>

using namespace std;

#define N 3

int main() {
	double a, b, c, result = 1;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (a >= b && a >= c) {
			cout << "W ";
		} else if (b >= a && b >= c) {
			cout << "T ";
		} else if (c >= a && c >= b) {
			cout << "L ";
		}
		result *= max(a, max(b, c));
	}
	result = (result * 0.65 -1) * 2;
	printf("%.2f\n", result);
	return 0;
}
