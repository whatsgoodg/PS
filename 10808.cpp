#include <iostream>
using namespace std;

int main() {

	string word;
	cin >> word;
	
	int alphabet[26]{};
	
	for (char i : word) alphabet[i - 97]++;
	for (int i : alphabet) cout << i << " ";

}
