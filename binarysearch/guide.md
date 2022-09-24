# Binary Search
## 이분탐색 개념
이분탐색이란 ***정렬***되어 있는 배열에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로 확인하는 대신 탐색 범위를 절반으로 줄여나며 찾는 탐색 방법이다.         
배열의 모든 수를 탐색하는 선형탐색의 시간 복잡도는 O(N)이고 이분탐색은 O(lgN)이다.       
두 가지 이상의 수를 찾아야하는 문제에서 선형탐색은 시간초과를 종종 유발하는데, 이럴 때 이분탐색을 사용한다면 해결할 수 있을 것이다.          
           
이분탐색을 구현하기 위해 기본적으로 세 가지의 변수가 필요하다.(세 변수의 값의 범위는 조건에 따라 달라진다.)         
> 1. 배열의 시작점인 st       
> 2. 배열의 끝점인 en      
> 3. st와 en의 중간인 mid            
#### 구현     
          
```cpp
  int st = 0;
  int en = N - 1;
  while (st <= en) {//(4)
	  int mid = (en + st) / 2;
	  if (arrN[mid] < arrM[i]) st = mid + 1;//(1)
	  else if (arrN[mid] > arrM[i]) en = mid - 1;//(2)
	  else break;
  }
```    
          
> (1). 찾고자하는 수가 arr[mid]보다 더 작다면 st를 mid + 1로 옮긴다. 
> (2). 찾고자하는 수가 arr[mid]보다 더 크다면 en를 mid - 1로 옮긴다. 
> (3). mid를 찾은 시점이다.       
> (4). 만약 st가 en보다 커진다면 수가 존재하지 않는 것으므로 while문을 종료한다.     
          
### binary_search
C++ algorithm 헤더에 binary_search 함수를 제공해주는데, binary_search(array.begin, array.end, target)의 형태를 띠고 있고 위의 코드와 거의 동일하게 동작한다.         
[수 찾기](https://www.acmicpc.net/problem/1920)문제를 풀어보자.         
           
## 찾고자하는 수가 두 개 이상일 경우     
target을 찾았을 때 배열은 이미 정렬이 되어 있으니 target의 왼쪽과 오른쪽을 선형탐색으로 모두 확인한다면 target의 개수만큼 비례하기 때문에 시간초과가 날 수 있다.         
이를 해결하기 위해 target을 가장 왼쪽에 있는 target과 수가 같은 인덱스에 넣어주거나 target보다 큰 수가 처음으로 등장하는 index에 값을 삽입하여(right shift 개념)          
배열의 오름차순을 유지한다는 생각을 이용해야한다. 이것을 이용하여 (rightmost + 1) - (leftmost) = target의 개수를 구할 수 있게된다.          
그렇다면 이분탐색을 두 번 사용하여 leftmost와 rightmost + 1 인덱스를 구하여야한다.      
          
### 두 가지 경우       
> 1. target이 배열에 존재할 때               
> 2. target이 배열에 존재하지 않을 때         
               
(2.): 삽입할 자리가 배열의 index N-1에 있을 수 있기에 en을 index N에 두어야 한다.               
### leftmost        
> 1. arr[mid]가 target보다 크거나 같을 때 en을 mid로 초기화 해준다.                 
> 2. arr[mid]가 target보다 작을 때 st을 mid + 1로 초기화 해준다.                
> 3. 결과적으로 en은 leftmost target을 tracking하고 st은 target보다 작은 수를 만난다면 mid + 1을 해주며, 가장 왼쪽에 위치했을 때 이후로 움직이지 않는다.          
 
### rightmost        
> 1. arr[mid]가 target보다 클 때 en을 mid로 초기화 해준다.     
> 2. arr[mid]가 target보다 크거나 작을 때 st을 mid + 1로 초기화 해준다.        
> 3. 결과적으로 st은 rightmost target을 tracking하고 en은 target보다 큰 수를 만난다면 mid을 해줌으로써 가장 오른쪽에 위치했을 때 이후로 움직이지 않는다.             
               
st가 mid보다 한 칸 더 움직이는 기능을 하고, en은 mid자리에 놓여진다. 둘의 조건 차이는 거의 없어 보인다.            
st와 en은 arr[mid]가 target과 같아졌을 때에 생각만 잘하면 되기 때문이다. leftmost를 찾을 땐, 같을 때 en을 움직이고 rightmost는 반대로 st을 움직인다.         
왜냐하면 st와 en이 같은 수를 가지게 하기 위함이다. leftmost는 target보다 한 칸 앞에있는 수를 만나면 +1을 해주며 target을 찾는 순간 st는 움직이지 않는다.        
반대로 rightmost + 1은 target보다 큰 수일 때만 en으로 초기화 시켜주면 된다.              
그 이후 target 범위 내에 접근했을 때 자연스럽게 st는 leftmost에, en은 rightmost + 1에 존재할 것이다.        

### 구현
```cpp
  while (st < en) {//leftmost
	  int mid = (st + en) / 2;
	  if (arr[mid] >= v) en = mid;
	  else st = mid + 1;
  }
```
              
### upper_bound, lower_bound          
C++ algorithm 헤더에 upper_bound, lower_bound 함수를 제공해주는데, 두 함수의 매개변수는(array.begin, array.end, target)의 형태를 띠고 있다.       
위의 코드와 동일하게 동작한다.         
[숫자 카드 2](https://www.acmicpc.net/problem/10816)문제를 풀어보자.        
