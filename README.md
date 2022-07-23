# For Coding Test
There will be codse for BackJoon wrritten in C++<br>
The names of files will be the problem number<br>
Codes will be explained by comments if a problem is considered easy<br>
If it's considered hard, codes will be explained with an extra file<br>
Algorithms are going to be written in Data Structur & Algorithms repo<br>

  # 1. Elementary usage of data structure in PS    
  ## 자료구조, 알고리즘의 기초 사용    
  * [Array](https://github.com/whatsgoodg/Codes_for_tests/blob/main/usage/array.md)    
  * [List](https://github.com/whatsgoodg/Codes_for_tests/blob/main/usage/list.md)    
  * [Stack, Queue, Deque](https://github.com/whatsgoodg/Codes_for_tests/blob/main/usage/stack%2Cqueue%2Cdeque.md)    
  * [BFS](https://github.com/whatsgoodg/Codes_for_tests/blob/main/usage/bfs.md)   
  <br><br><br>
  
# 2. Basic tips
## Let's use bits/stdc++.h 
 gcc 계열의 컴파일러를 사용하지 않는다면 따로 설정을 해주어야 하지만 매우 간단하다.<br>
 굳이 헤더를 모두 작성할 필요 없이 한 줄로 간결하게 끝낼 수 있다.<br>
 컴파일 시간이 좀 늘어날지 몰라도 코딩 테스트에선 이점을 얻을 수 있다.<br>
  
  ## ios::sync_with_stdio(0)
  간단히 cout과 scanf를 같이 사용한다면 순서에 맞게 출력이 되어야 하므로 C++ stream과 C stream는 동기화가 이루어진다.<br>
  이것을 끊어줌으로써 시간 복잡도 측면에서 이득이다.<br> 
  이후에 scanf나 printf를 사용하면 안 된다.<br>
  
  ## cin.tie(0)
  C++에서 입력 후에 출력 순서를 맞추어 주기 위해 cin을 받기 전에 cout 버퍼를 모두 비워준다.<br>
  이러한 flush는 시간이 상당히 걸리기에, 이것을 cin과 cout의 tie를 풀어준다.<br>
  같은 맥락으로 endl는 절대 사용하지 않는다.<br>
  
  ## Up to 100,000,000 times per a second
  (C++ 언어로 알고리즘 문제를 해결할 때 약 1초 제한에 1억번의 연산까지 가능하다는 소리를 많이 듣는다. 이는 넉넉히 잡은 것으로 1억 6천만번의 시간도 가능하다곤 한다.
  1번의 연산은 반복문 한 번 반복으로 예시를 들겠다.(반복문 안의 다른 연산은 무시한다))    
      
  알고리즘 문제를 해결할 때 아무런 생각없이 모든 문제를 이중 반복문으로만 해결하다가, 실버 또는 골드 이상 문제(백준)를 맞딱뜨렸을 때, 시간초과로 당황한 적이 있다. 알고리즘 구현을     하는 순서가 잘못된 것이였다.    
  문제를 읽고 테스트 케이스의 개수를 아예 무시를 해버리고 시간 복잡도에 대한 생각을 하지 않았기 때문에 높은 수준의 문제를 해결할 수 없었다. 이를 해결하기 위해 약 1초에 1억번이란 말을 이해해보자. 구현을 하기전에 짚고 넘어가야 하는 것이 있다.
      
  테스트 케이스의 개수이다. 반복문이 한 번 연산하는데 걸리는 시간을 ***1 unit***이라 하겠다. 반복문 하나(O(N))를 N(테스트 케이스 개수)번 반복한다면 N unit이 걸린다. 만약 N이 2억이라면 시간초과로 문제를 해결하지 못할 것이다. 
  똑같은 예시로 N이 12,000일 때, 이중 반복문(O(N^2))을 실행한다면 144,000,000 unit이 걸리기에 이 또한 시간초과가 발생할 것이다.    
  이렇게 테스트 케이스의 개수를 고려한다면 어떤 자료구조(알고리즘)를 사용해야할 지 또는 기존에 생각한 구현이 틀리다는 것에 많은 도움을 준다.     
  1초에 대한 최대 크기:    
  * O(N): 1억    
  * O(N^2): 1만
  * O(N^3): 470<br><br><br>
   
  # 3. Useful Functions
  ## max_element (ForwardIterator first, ForwardIterator last)
  <algorithm> header에 있는 함수이다.<br>
  first: begin을 가리키는 iterator(주소)를 인자로 전달한다.<br>
  last: end를 가리키는 iterator(주소)를 인자로 전달한다.<br>
  return: 가장 큰 원소를 가리키는 iterator를 반환한다.<br>
  동일한 원소가 두 개 이상 저장되어 있다면 가장 첫 번째의 원소를 가리키는 iterator를 반환한다.<br>
  size < 1 경우, end를 가리키는 iterator를 반환한다.<br>
 
  ## fill (ForwardIterator first, ForwardIterator last, val v)
  <algorithm> header에 있는 함수이다.<br>
  container의 [first, last) 범위에 있는 모든 원소를 v로 초기화하는 함수이다.<br>
  첫 번째, 두 번째 인자는 위의 함수와 동일하다.<br>
  return: (x) <br>
