#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int a, b;
//	cout << "input" << endl;
	cin >> a >> b;
	int sum = a + b;
	string tmp;
	stringstream ss;
	ss << sum;
	ss >> tmp;
	string result = "";
	int cnt = 1;
//	cout << sum << endl;
	for (int i = tmp.size()-1; i >= 0; i--) {
		result = tmp[i] + result;
		if (cnt % 3 == 0 && i != 0 && tmp[i-1] != '-') {
			result = "," + result; 
		}
		cnt++;
	}
	cout << result << endl;
	return 0;
} 
