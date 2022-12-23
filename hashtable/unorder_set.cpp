#include <iostream>
#include <unordered_set>
using namespace std;

void unordered_set_example() {
	//중복 x
	unordered_set<int> s;
	//insert: pair 반환 first: 인자로 들어간 값의 iter, second: true or false(new or already)
	s.insert(-10); s.insert(100); s.insert(15); // {-10, 100, 15} 
	s.insert(-10); // {-10, 100, 15}    
	cout << s.erase(100) << '\n'; // {-10, 15}, return 1
	cout << s.erase(20) << '\n'; // {-10, 15}, return 0
	if (s.find(15) != s.end()) cout << "15 in s\n"; //return end if no element else iter to it
	else cout << "15 not in s\n";
	cout << s.size() << '\n'; // 2
	//count 
	cout << s.count(50) << '\n'; //if it's in returns 1 otherwise 0
	for (auto e : s) cout << e << ' '; //삽입한 순서로 출력x 해시의 특성 
	cout << '\n';
}
