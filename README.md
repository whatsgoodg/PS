# For Coding Test
There will be codse for BackJoon wrritten in C++<br>
The names of files will be the problem number<br>
Codes will be explained by comments if a problem is considered easy<br>
If it's considered hard, codes will be explained with an extra file<br>
Algorithms are going to be written in Data Structur & Algorithms repo<br>
*자료구조나 자료구조를 이용한 유용한 방법, 알고리즘들은 Data Structur and Algorithms repo에 commit 됩니다.<br><br><br>

# Basic tips for Setup
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
  같은 맥락으로 endl는 절대 사용하지 않는다.<br><br>
  
  # 2. How to use data structure 
  ## Array
  알고리즘 문제를 해결할 때, 필자처럼 프로그래밍 언어 문법만 배우고 코딩 테스트라는 사전 지식 없이 선형 자료구조인 배열을 하나만 이용하여 처음부터 끝까지 원소를 탐색하며   
  조건에 맞는 소스코드를 작성했을 것이다. 예를 들어, 백준 [10808](https://www.acmicpc.net/problem/10808)번을 해결할 반복문을 보자. 
   ```cpp    
      for(int i = 0; i < 26; i++){    
          for(int j = 0; j < str.size(); j++){    
              if(str[j] == i + 97) cnt++;    
          }    
          cout << cnt << " ";    
          cnt = 0;    
      }    
  ```    
      
  알파벳 개수를 출력하는 문제로 이중 배열을 사용하여 시간 복잡도가 O(26 * N)가 걸리는 것을 볼 수 있다.   
  배열과 반복문 문법만 안일하게 사용하여 벌어진 실수이다. 이것을 O(N)으로 해결할 수 있는 방법이 있다.   
  
  ```cpp    
     char alphabet[26]{};    
     for(int i = 0; i < str.size(); i++){    
         alphabet[str[i] - 97]++    
     }    
  ```    
      
  바로 이렇게 배열 하나만 더 만들어주는 것이다. 공간 복잡도는 조금 늘어날 수 있으나, 
  코딩 테스트에서 요구하는 공간 복잡도를 넘길 정도는 절대 아니다.(물론 넘기는 경우엔 다른 알고리즘을 요구하는게 분명할거다.)   
  이런 식으로 배열 하나를 더 추가함으로써 문제해결을 손쉽게 할 수 있게 된다.<br><br>
  
  
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
