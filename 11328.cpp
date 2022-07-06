#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		bool flag = 1;
		int alph[26]{};
		int alph2[26]{};

		string str; cin >> str;
		for (int j = 0; j < str.size(); j++) alph[str[j] - 97]++;

		string str2; cin >> str2;
		if (str.size() != str2.size()) {
			cout << "Impossible" << "\n";
			continue;
		}
		for (int j = 0; j < str2.size(); j++) alph2[str2[j] - 97]++;

		for (int j = 0; j < str2.size(); j++) if (alph[str[j] - 97] != alph2[str[j] - 97]) flag = false;
		if (flag) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}
	
}
