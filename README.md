# For Coding Test
There will be codse for BackJoon wrritten in C++<br>
The names of files will be the problem number<br>
Codes will be explained by comments if a problem is considered easy<br>
If it's considered hard, codes will be explained with an extra file<br>
Algorithms are going to be written in Data Structur & Algorithms repo<br>
*소소한 팁들을 제공해주는 README로, 자료구조 개념(구현 소스코드), 심화 알고리즘(ex. DFS, BFS)는 블로그나 다른 repo에 업로드 됩니다.<br><br><br>

# 1. Basic tips
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
  
  
  
  
  # 2. Elementary usage of data structure in PS    
  자료구조를 이용한 알고리즘을 사용할 때 가장 기본적인 것들을 기록해 놓을 것이다.
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
  [소스코드](https://github.com/whatsgoodg/Codes_for_tests/blob/main/5397.cpp)<br><br>
  
  ## Stack, Queue, Deque     
  이 세 개의 자료구조를 이용하는 문제들은 다 비슷해 보이기 때문에, 문제들을 통해 세 가지의 차이점을 파악하는게 좋아 보인다.     
  ### Stack     
  Stack을 이용하여 괄호, 연산 등을 활용한 문제들은 Stack에 대한 이해(FILO)를 공고히 할 수 있겠지만, 골드 이상 문제를 풀 땐 좀 다른 것 같다.       
  [2493](https://www.acmicpc.net/problem/2493)문제를 읽어보자.     
  이 문제는 선형적으로 값이 들어오고, 들어오는 값마다 ***왼쪽***에 레이저를 쏜다. 그리고 새로운 값보다 큰 탑***만*** 만나면 되기 때문에    
  Stack(왼쪽)에 있어야 할 값은 ***지금까지 들어왔던 값 들의 내림차순 배열이다.***     
  예제를 보면 9가 가장 큰 포탑이여도 4가 들어왔을 땐 그냥 4보다 큰 7이 레이저를 맞는 것을 볼 수 있다.    
  새로운 값(맨 오른쪽 탑)이 들어왔을 때 Stack top이 새로운 값보다 작지 않다면 아무 동작 없이 모두 stack에 push한다.     
  하지만 만약 새로운 값이 stack의 top보다 크다면 새로운 값보다 stack안의 작은 값들을 모두 삭제한다.    
  새로운 값(탑)이 stack에 들어온다면 이 보다 작은 탑들은 레이저를 절대 맞지 않기 때문이다.     
  이렇게 Stack의 원소보다 ***큰 값***이 들어올 때마다 업데이트를 시켜줘야 하는 구현이 떠오를 때 stack을 사용하면 될 것 같다.
  ***P.S.***: Pair 사용과 인풋 케이스의 범위의 사용을 정확하게 이해할 수 있는 문제이다.    
  ***힌트 코드***     
  ```cpp     
     for (int i = 1; i <= N; i++) {     
       int height;     
       cin >> height;    
       while (tower.top() < height) tower.pop();    
       tower.push(i);       
     }     
  ```    
  [6198](https://www.acmicpc.net/problem/6198), [17298](https://www.acmicpc.net/problem/17298)문제도 이와 거의 비슷한 문제이다.<br>
  ### Queue    
  Queue는 아직 모르겠다.<br>
  ### Deque
  Deque를 사용해야 할 지 말 지에 대한 생각은 나름 Stack과 Queue보다는 나은 것 같다. Deque는 선형적으로 들어온 값들이 reverse가 되거나
  맨 뒤의 원소가 맨 앞으로 가야하는 상황이 발생할 때 필요하다.

  
  
  
  
  

  
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
