#include <iostream>
#include <string>

using namespace std;

int main() {
	string sNum;
	cin >> sNum;
	int result = 0;
	for (auto ch : sNum) {
		result += ch - '0';
	}
	string enums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string sResult = to_string(result);
	bool flag = false;
	for (auto ch : sResult) {
		if (!flag) {
			flag = true;
			cout << enums[ch-'0'];
		} else {
			cout << " " << enums[ch-'0'];
		}
	}
	cout << endl;
	return 0;
}
