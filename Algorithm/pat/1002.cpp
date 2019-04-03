#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define N 1000+5
#define MIN_VALUE 1e-6


int main() {
	double b, c[N];
	int k, a;
	cin >> k;
	memset(c, 0, sizeof(c));
	
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		c[a] += b;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		c[a] += b;
	}
	int cnt = 0;
	for (int i = N-1; i >= 0; i--) {
		if (fabs(c[i]) > MIN_VALUE) {
			cnt ++;
		}
	}
	printf("%d", cnt);
	for (int i = N-1; i >= 0; i--) {
		if (fabs(c[i]) > MIN_VALUE) {
			printf(" %d %.1lf", i, c[i]); 
		}
	}
	printf("\n");
	return 0;
}

/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5

*/
