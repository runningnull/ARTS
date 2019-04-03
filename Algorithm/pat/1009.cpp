#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define N 1000000+5
#define ZERO 1e-7
float a[N], b[N];

int main() {
	
	int n;
	cin >> n;
	int tmp_a;
	double tmp_b;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++) {
		cin >> tmp_a >> tmp_b;
		a[tmp_a] = tmp_b;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp_a >> tmp_b;
		for (int j = 0; j < N; j++) {
			b[tmp_a+j] += tmp_b*a[j];
		}
	}
	int cnt = 0;
	for (int i = N-1; i >= 0; i--) {
		if  (fabs(b[i]) > ZERO) {
			cnt++;
		}
	}
	printf("%d", cnt);
	for (int i = N-1; i >= 0; i--) {
		if  (fabs(b[i]) > ZERO) {
			printf(" %d %.1f", i, b[i]);
		}
	}
	printf("\n");
	return 0;
}
