#include <iostream>
#include <unordered_map>
using namespace std;

void unordered_map_example() {
	//(key, value) 형태의 entry 삽입.
	unordered_map<string, int> m;
	m["hi"] = 123;
	m["bkd"] = 1000;
	m["gogo"] = 165; // ("hi", 123), ("bkd", 1000), ("gogo", 165)
	cout << m.size() << '\n'; // 3
	m["hi"] = -7;  // ("hi", -7), ("bkd", 1000), ("gogo", 165)
	if (m.find("hi") != m.end()) cout << "hi in m\n";
	else cout << "hi not in m\n";
	m.erase("bkd"); // ("hi", 123), ("gogo", 165)
	for (auto e : m)  
		cout << e.first << ' ' << e.second << '\n';
}
