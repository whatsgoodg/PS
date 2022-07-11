#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	S.push({100000001, 0});

	for (int i = 1; i <= n; i++) { 
		int v; 
		cin >> v;
		while (S.top().first < v) S.pop(); //새로운 값이 들어왔을 때마다 스택에 있는 이보다 작은 수들을 전부 삭제
		cout << S.top().second << " ";
		S.push({ v, i });//새로운 값 삽입
	}
	
}
//처음 실수: stack을 이용할 때 biggest라는 변수를 다뤄 stack을 계속 업데이트(push)를 한다면 
//[가장큰값, top] 범위의 값만 탐색하게 했다. 정답의 while(S.top() < height) S.pop()은 동일 했기에 
//시간초과가 나지 않을거라 생각했다. 근데 만약 "가장 큰 값"보다 더 큰 값이 들어오지 않는다면
//스택엔 가장 큰 값이 들어오기 이전엔 pop을 하지 않기에
// 배열을 이용하여 시간복잡도 n^2을 이용하는 것이랑 다를게 없는 것이다. 
//*풀이
//새로운 값이 들어올 때 마다 스택안에 있는 이보다 작은 값들을 그냥 계속 삭제해준다. 
//그럼 이보다 크거나 같은 값이 top에 남을텐데 그 값이 곧 레이저를 수신 받는 최초의 탑이 될 것이다.
//그리고 삭제된 값은 중요하지 않다 어차피 새로 들어오는 값보다 작은 값들을 삭제한 것이기 때문이다.(그럼 임의의 탑의 레이저를 수신할 최초의 탑들은 유지가 되겠지.)
