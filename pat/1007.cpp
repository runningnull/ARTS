#include <iostream>
#include <cmath>

using namespace std;

#define N 10000+5
#define MIN_VALUE -1<<30

int main() {
	int n, v[N], maxx = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		maxx = max(maxx, v[i]);
	}
	if (maxx < 0) {
		cout << 0 << " " << v[0] << " " << v[n-1] << endl;
	} else {
		int result = MIN_VALUE, mleft=0, mright=0, tmp = 0, left=0, right=0;        
		for (int i = 0; i < n; i++) {
			if (tmp + v[i] > 0) {
				tmp += v[i];
				right = i;
			} else {
				tmp = 0;
				left = right = i+1;
			}
			if (result < tmp) {
				result = tmp;
				mleft = left;
				mright = right;
			}
		}
		cout << result << " " << v[mleft] << " " << v[mright] << endl;		
	}
	
	return 0;
}
/*
10
-10 1 2 3 4 -5 -23 3 7 -21
10
10 1 2 3 4 -5 23 3 7 21
10
-10 -1 -2 -3 -4 -5 -23 -3 -7 -21
10
-10 1 2 3 4 -10 7 7 -7 -21
3
-1 0 0
3
0 0 0
6
-2 11 -4 13 -5 -2
*/
