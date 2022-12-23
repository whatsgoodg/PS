#include <iostream>
#include <unordered_set>
using namespace std;

void unordered_multiset_example() {
	//set과의 차이는 중복 허용
	unordered_multiset<int> ms;
	ms.insert(-10); ms.insert(100); ms.insert(15); // {-10, 100, 15}
	ms.insert(-10); ms.insert(15);// {-10, -10, 100, 15, 15}
	cout << ms.size() << '\n'; // 5
	for (auto e : ms) cout << e << ' ';
	cout << '\n';
	cout << ms.erase(15) << '\n'; // {-10, -10, 100}, 2 중복된 원소 모두 삭제
	ms.erase(ms.find(-10)); // {-10, 100} 하나만 삭제할 때
	ms.insert(100); // {-10, 100, 100}
	cout << ms.count(100) << '\n'; // 2
}
