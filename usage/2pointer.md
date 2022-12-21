# Two Pointer
`투 포인터`란 배열에서 이중 반복문으로 **O(N^2)**에 처리하는 작업을 2개의 포인터로 **O(N)**에 처리하는 알고리즘이다.           
투 포인터 알고리즘은 index하나 차이로 정답과 오답을 오가는 디테일이 요구되는 알고리즘이다.
`투 포인터`로 `이분탐색` 문제를 해결할 수 있는 경우도 많다. ex) 수 찾기, 숫자 카드2, 세 수의 합 등
반대로 `투 포인터` 문제를 `이분탐색`으로 해결할 수 있는 경우도 많다.
이번 알고리즘의 경우 이분탐색으로도 해결해보는 생각을 가지는게 좋다. 
이론적인 내용보단 `구현`에 중점을 둘 것이다. 

## [수 고르기](https://www.acmicpc.net/problem/2230)
이 문제는 `이분탐색`으로 바로 해결할 수 있다.(투 포인터와 이분탐색은 오름차순 `정렬`이 필요하다.)
배열 전체를 돌며 각각의 원소 x마다 x+M에 대해 lowwer_bound() 함수를 사용하거나 따로 구현하여 해결하면 된다.
`투 포인터`로 풀이하는 경우는 indexing을 관리할 두 개의 변수가 필요하다: `st`, `en`

![image](https://user-images.githubusercontent.com/86244920/208840727-8bd5cd31-444f-4264-9eed-ccfeff7ea38f.png)

위의 이미지를 보면 st와 en은 index 0에서 시작한다. 투 포인터로 처리하기 위한 조건은 아래와 같다.
> 각 st에 대해 arr[en] - arr[st]가 m 이상이 되는 최초의 en의를 찾은 뒤 arr[en + 1], arr[en + 1], ... ,arr[N-1]을 탐색할 필요가 없다.(**M 이상의 최소값이기 때문이다.**)
위의 조건을 바탕으로 아래와 같은 조건이 도출된다.
>1. arr[en] - arr[st]가 M보다 **작은 경우** en을 **오른쪽으로 한 칸 이동한다.**
>2. arr[en] - arr[st]가 M보다 **크거나 같은 경우** 대소비교를 통해 답을 업데이트하고 **st을 오른쪽으로 한 칸 이동한다.**
>3. en이 N과 같을 경우 답을 출력하고 프로그램을 종료한다.(en이 N과 같아졌다면 더 이상 비교할필요가 없다.)

위와 같은 방법으로 투 포인터를 구현하면 된다. O(N^2)으로 수행되는 반복문을 st와 en을 사용하여 O(N)에 처리할 수 있다.
(정렬을 사용했기 때문에 정확히 O(NlogN)이다.)
### 정답코드
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];
int ans = 2000000001;
int en;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	for (int st = 0; st < N; st++) {//3.2
		while (en < N && arr[en] - arr[st] < M) en++; //1
		if (en == N) break;//2
		ans = min(ans, arr[en] - arr[st]);//3.1
	}
	cout << ans;
}
```

## [부분합](https://www.acmicpc.net/problem/1806)
위의 문제를 해결했다면 이번 문제는 좀 쉬울 것이다.
조건은 아래와 같다.
>1. 배열의 index 0부터 부분합이 S보다 작을 경우 en을 오른쪽으로 한 칸 이동하고 이동했을 때의 원소를 부분합에 더한다.
>2. S보다 같거나 클 경우 최소 길이를 업데이트하고 st를 오른쪽으로 한 칸 이동한다.
>**(st 기존 위치의 원소 값을 부분합에서 빼고 난 뒤 이동한다.)**
>3. en이 N과 같고 부분합이 S보다 작을 경우 답을 출력하고 프로그램을 종료한다.
### 정답코드
```cpp
#include <iostream>
#include <utility>
using namespace std;

int N, S;
int arr[100000];
int ans = 100000;
int sum;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int en = 0;
	sum = arr[en];
	for (int st = 0; st < N; st++) { //2.3
		while (en < N && sum < S) { //1
			en++;
			if (en != N) sum += arr[en];
		}
		if (en == N) break; //3
		ans = min(ans, en - st + 1); //2.1
		sum -= arr[st]; //2.2
	}
	if (ans == 100000) cout << 0;
	else cout << ans;
}	
```
