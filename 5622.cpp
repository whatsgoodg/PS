#include <iostream>
#include <string>
using namespace std;


int main() {
	string a;
	cin >> a;

	int sum = 0;
	for (char i : a) {
		int temp = i - 65 //using ASCII

		if (temp < 3) sum += 3; //three letters in one dial
		else if (temp < 6) sum += 4;
		else if (temp < 9) sum += 5;
		else if (temp < 12) sum += 6;
		else if (temp < 15) sum += 7;
		else if (temp < 19) sum += 8; //when there are four
		else if (temp < 22) sum += 9;
		else if (temp < 26) sum += 10;
	}
	cout << sum << endl;
}
