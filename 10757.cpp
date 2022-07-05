#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	string b;
	cin >> a >> b;

	if (a.size() < b.size()) { //number that has bigger size is 'a'
		string tmp = a;
		a = b;
		b = tmp;
	}
	string sum = "";
	char ten = '0';
	//when units become tens, it is needed to be added to next ones 
	for (int i = b.size() - 1, j = a.size() - 1; i > -1; i--, j--) { //adds size of 'b' times 	 
		int plus = a[j] - 48 + b[i] - 48 + ten - 48;
		ten = plus / 10 + 48;
		char one = plus % 10 + 48;
		sum = one + sum;
	}
	for (int i = a.size() - b.size() - 1; i > -1; i--) { //adds size of 'a' - size of 'b' times
		int plus = a[i] - 48 + ten - 48;
		ten = plus / 10 + 48;
		char one = plus % 10 + 48;
		sum = one + sum;
	}

	if (ten - 48 > 0) //when (size of 'a')-digit number becomes (size of 'a' + 1)-digit number
		sum = ten + sum;

	cout << sum << endl;
}
