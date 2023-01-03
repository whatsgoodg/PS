# HashTable
HashTable을 이용한 PS에 집중하여 포스팅합니다.                   
[HashTable](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#hash-table) 참고.                           
**`Linear Probing`**               
충돌 발생 시 오른쪽으로 한 칸씩 이동하는 방법.              
>* Cache hit ratio가 높다.(공간적 지역성)
>* Clustering이 생겨 성능에 영향을 준다: 충돌이 많이 발생될수록 Linear probing의 횟수가 더 많아진다.
                
**`Quadratic Probing`**             
충돌 발생 시 오른쪽으로 n^2(n=1,2,..) 칸씩 이동하는 방법
>* Cache hit ratio가 괜찮다. 
>* Clustering을 어느정도 회피할 수 있다. 충돌 발생 시, 무조건적으로 Clustering이 발생하지 않음.
                
**`Double Hashing`**
충돌 발생 시 이동할 칸의 수를 새로운 해시 함수로 계산하는 방식
>* Clustering을 효과적으로 피할 수 있다.
>* Cache hit ratio가 낮다.
       
## STL
`예제코드`              
* [unordered_set](https://github.com/whatsgoodg/PS/blob/main/hashtable/unorder_set.cpp)               
* [unordered_multiset](https://github.com/whatsgoodg/PS/blob/main/hashtable/unorder_multiset.cpp)                 
* [unordered_map](https://github.com/whatsgoodg/PS/blob/main/hashtable/unorder_map.cpp)     

## STL을 이용한 문제
굉장히 간단하니 코드만 보자.
### [7785](https://www.acmicpc.net/problem/7785)      
```cpp
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<string> s;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while(n--){
    string name, log;
    cin >> name >> log;
    if(log == "enter") s.insert(name);
    else s.erase(name);
  }
  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());
  for(auto x : ans) cout << x << '\n';
}
```
### [1620](https://www.acmicpc.net/problem/1620) 
```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> s2i;
string i2s[100005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> i2s[i];
    s2i[i2s[i]] = i;
  }
  while(m--){
    string query;
    cin >> query;
    if(isdigit(query[0]))
      cout << i2s[stoi(query)] << '\n';
    else
      cout << s2i[query] << '\n';
  }
}
```

## Implementation       
삼성 코딩 테스트에선 STL을 사용할 수 없기 때문에 해시 테이블을 따로 구현해야한다. 이 때 고려해야할 _**조건**_ 을 알아보자           
**`삽입의 최대 횟수`** : 삽입의 최대 횟수는 해시 테이블에 들어가는 원소의 최대 개수이다.                 
그러므로 해시 테이블의 크기(capacity)를 잘 고려하여 구현해야 한다.                            
**`load factor`** (원소의 개수 / 테이블의 크기)를 **작게** 유지하면 충돌이 덜 일어나 시간 복잡도가 좋아진다 하지만, cache hit ratio와 공간 복잡도가 좋지 않아진다.            
반대로 **크게** 유지한다면 시간 복잡도가 나빠진다.          
**`Chaining`** 을 구현할 때 충돌 발생을 감수하더라도 공간의 효율성을 위해 load factor를 **1 이하**로 두어야 한다.                     
**`Open addressing`** 을 구현할 때 각 인덱스에 반드시 하나의 원소가 들어가기 때문에 load factor를 **0.75 이하**로 두어야 한다.                      
**`요약`** 하여 Chaining은 테이블의 크기를 **최대 삽입 횟수**로, Open addressing은 테이블의 크기를 **최대 삽입 횟수 * 1.33**으로 두는게 좋다.                
> <u>하지만 대개 **두 배**를 잡아준다.(공간 복잡도는 널널하기 때문, 그러나 크기가 5천만이 넘어간다면 2배는 효율적이지 않다.)</u>               
### 정수에 대한 해시 함수
```cpp
const int M = 1000003;
int my_hash(int x){
  return (M + x % M) % M;
}
```
테이블의 크기 M은 소수여야 좋다. 위 처럼 처리해주는 이유는 key 값이 **음수**일 때를 처리해주기 위함이다.        
(mod 연산의 성질을 생각해보자.)            
### 문자열에 대한 해시 함수                    
```cpp
const int M = 1000003;
int hash(string& s){
  int h = 0;
  for(auto x : s) h += x;
  return h % M;
}
``` 
<u>_충돌이 굉장히 많이 일어나는 함수이다. 왜냐하면 아스키코드 값이 자체가 작기 때문에 특정 범위안에서만 돈다._</u>                    
               
```cpp
const int M = 1000003;
const int a = 1000;
int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}
```
<u> my_hash("abc")=('a' x 1000^2 + 'b' x 1000^1 + 'c' x 1000^0) % M </u>                           
위와 같이 진법처럼 가중치를 둬 값이 충분히 커지게 만들어 테이블에 잘 퍼지게 할 수 있다.                 
(a*M을 고려하여 오버플로우를 주의하자.)               
                      
### Chaining
구현을 하기 위해 이전에 구현했던 [list](https://github.com/whatsgoodg/PS/blob/main/list/1406.cpp)를 사용해야 한다.     
**`Chaining`** 구현은 조금 까다롭다. 위의 리스트와 조금 다르게 구현을 해야한다. 만약 **table의 크기 만큼** 리스트를 만든다면 메모리로 감당이 안 된다.             
그렇기 때문에 하나의 리스트로 모든 충돌을 제어해야 한다. **`리스트`** 의 **크기는 최대 삽입 횟수**, **`테이블`** 의 크기는 **`load factor`** 을 고려하여 정한다.      
**`테이블`** 은 아래의 이미지와 같다.               
                   
![image](https://user-images.githubusercontent.com/86244920/210324010-29a86314-9478-4855-8c8c-82c200b6e186.png)                      
                  
**`테이블`** 엔 세 가지 값이 존재한다.             
>1. 리스트의 주소(배열 index)          
>2. entry(key, value)    
                       
실제 구현은 테이블에 같은 해시값을 가진 원소들의 list의 주소(첫 번째 노드의 배열 인덱스)가 저장되어 있다.      
그리고 **`list`** 는 <u> pre, nxt, entry(key, val)</u> 의 형태로 관리한다.   
그렇다면 **`load factor`** 을 고려하여 table의 크기와 나머지 list의 크기를 잡아주면 된다. 
                    
**table을 head라 칭하겠다.**
#### find(key)
>* table의 head에 저장된 list의 배열을 통해 list를 순회하며 key값과 동일한 노드의 주소(배열의 인덱스)를 반환한다.        
                   
#### insert(key, value)
>* 같은 key를 가진 노드가 존재한다면 value만 수정한다.
>* 삽입은 **insertFront** 방식을 따른다.
>1. 원소가 한 개 이상 있을 시, 노드를 이어주고 새로운 노드의 주소를 head에 저장한다.
>3. 리스트가 비어있다면 새로운 노드의 주소를 head에 저장한다.
           
#### erase(key)
>* key가 없다면 함수를 종료한다.
>* 이전노드 -> 다음노드, 이전노드 <- 다음노드를 처리한다.
>* 만약 삭제하려는 노드가 head에 있다면 head를 수정한다.
                
[**소스코드**](https://github.com/whatsgoodg/PS/blob/main/hashtable/chaining.cpp)                
            
### Open Addressing     
**`Linear probing`** 을 통해 구현했기 때문에 굉장히 간단하다.          
              
[**소스코드**](https://github.com/whatsgoodg/PS/blob/main/hashtable/openaddressing.cpp)              
