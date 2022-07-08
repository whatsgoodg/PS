# For Coding Test
There will be codse for BackJoon wrritten in C++<br>
The names of files will be the problem number<br>
Codes will be explained by comments if a problem is considered easy<br>
If it's considered hard, codes will be explained with an extra file<br>
Algorithms are going to be written in Data Structur & Algorithms repo<br>
*소소한 팁들을 제공해주는 README로, 자료구조 개념(구현 소스코드), 심화 알고리즘(ex. DFS, BFS)는 블로그나 다른 repo에 업로드 됩니다.<br><br><br>

# 1. Basic tips for Setup
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
  같은 맥락으로 endl는 절대 사용하지 않는다.<br><br><br>
  
  # 2. Primary usage of data structure in PS
  ## Array
  알고리즘 문제를 해결할 때, 필자처럼 프로그래밍 언어 문법만 배우고 코딩 테스트라는 사전 지식 없이    
  선형 자료구조인 배열을 하나만 이용하여 처음부터 끝까지 원소를 탐색하며 조건에 맞는 소스코드를 작성했을 것이다.    
  예를 들어, 백준 [10808](https://www.acmicpc.net/problem/10808)번을 해결할 반복문을 보자.     
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
  
  ## List     
  리스트를 사용한 알고리즘 문제는 그리 많지 않다고 한다. 아마도 다른 자료구조들로 충분히 구현이 가능하기 때문이라고 생각한다.    
  텍스트 편집기를 연상케 하는 문제를 이용하여 STL list(이중연결)를 어느정도 익힐 수 있다. 그럼 문제 [5397](https://www.acmicpc.net/problem/5397)을 보자.    
  굉장히 간단한 문제라고 생각했지만 계속 예외가 나와서 당황한 문제이다. 이미지를 보면 이해가 굉장히 빨라진다.(탭에 그려볼걸..)    
  <img src="https://github.com/whatsgoodg/Codes_for_tests/blob/main/images/LIST.JPG?raw=true"  width="500" height="200"/>     
  위의 사진을 보면 begin은 맨 처음 원소를 가리키는 iterator이다. end는 맨 마지막 원소 **다음**이다.    
  이것은 **past-the-end**라고 불리며 맨 마지막 원소 다음이니 이미지와 같이 노드를 가리키는게 아니다. 마지막 노드 다음을 가리키는 것이다    
  그리고 list가 비어있는 상태엔 begin과 end가 동일하다.    
  ### insert     
  만약 아무 원소도 가지지 않은 list에 반복자를 사용하여 원소를 추가했을시    
  begin에 노드가 추가되고 반복자는 여전히 end를 가리킨다.   
  
  ```cpp    
     list<char> inputs;//empty        
     auto it = inputs.begin();//begin=end    
     inputs.insert(it, 1);    
     cout << *it << endl;//run-error: end는 아무 원소도 가리키지 않으므로 역참조 불가능    
  ```    
 
  이 end를 이용하여 우린 텍스트 에디터 커서의 맨 마지막 자리를 표현해주면 된다.(글자가 입력되고 커서는 여전히 글자 뒤에 존재한다.)    
  ### erase    
  erase는 노드를 삭제하는 연산이다 삭제하고 나서 그 노드를 가리키는 반복자를 초기화 시켜줘야한다.(반복자가 가리키는 노드가 삭제되었으니)      
 erase는 노드가 삭제되었을 때 list의 노드들이 삭제된 노드의 다음 노드부터 한칸 왼쪽으로 shift 되기에 shift 연산 후의 노드의 반복자를 반환한다.  
 
  ```cpp   
     list<int> inputs;  
     inputs.push_back(1);   
     inputs.push_back(2);   
     auto it = inputs.begin();   
     it = inputs.erase(it); //1이 삭제되고 2가 왼쪽으로 shift후 2를 가리키는 iterator 반환후 it 초기화   
  ```    
  **문제풀이**: 커서의 위치를 담당하기 위한 end에 대한 이해, insert는 노드 앞에 삽입되므로 커서의 앞과 삽입되는 경우와 상통       
  커서 앞의 문자가 삭제되므로 반복자에 --연산을 한 후 erase를 통한 삭제와 반복자 초기화(커서 초기화)    
  [소스코드](https://github.com/whatsgoodg/Codes_for_tests/blob/main/5397.cpp)<br><br><br>
  
  
  
  

  
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
