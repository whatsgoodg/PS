# Stack, Queue, Deque     
  이 세 개의 자료구조는 매커니즘은 비슷하기 때문에, 문제들을 통해 세 가지의 차이점을 파악하는게 좋아 보인다.     
  ## Stack     
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
  [6198](https://www.acmicpc.net/problem/6198), [17298](https://www.acmicpc.net/problem/17298)문제도 이와 거의 비슷한 문제이다. [2493 소스코드](https://github.com/whatsgoodg/Codes_for_tests/blob/main/stack/2493.cpp), [6198 소스코드](https://github.com/whatsgoodg/Codes_for_tests/blob/main/stack/6198.cpp), [17298 소스코드](https://github.com/whatsgoodg/Codes_for_tests/blob/main/stack/17298.cpp)<br>
  ## Stack(brackets)    
  스택의 성질을 이해하기 위한 괄호의 쌍을 이용한 문제들을 많이 풀어보면 좋다.           
  이 내용들은 기본적인 세 가지 예외만 파악하고 있으면 된다. 나머진 ***+α***로, 그리 어렵지 않은 부가적 요소만 생각해 내면 된다.     
  [4949](https://www.acmicpc.net/problem/4949)문제를 보자, 이 문제는 정말 간단하게 생각하면 된다.       
  만약 ***(*** 또는 ***[*** 괄호 차례라면 Stack에 push한다. 그리고 ***)*** 또는 ***]*** 괄호 차례라면 Stack의 top과 비교해       
  적합한 괄호라면 pop을 하고 진행한다. 모든 괄호를 처리하고 나서 Stack이 ***비어***있다면 알맞은 괄호이기에 yes를 출력한다.     
  그렇다면 예외는 잘 보일 것이다.        
  1. Stack이 비어있지 않은 경우     
  2. 적합하지 않은 괄호가 나온 경우     
             
  이 예외만 기억을 잘 하고 있다면 수식과 관련된 문제들은 쉽게 처리할 수 있을 것이다.<br>
  
  ## Queue    
  queue는 선형적으로 값이 들어오고 들어온 순서대로 값이 나갈 때(FIFO) 사용하면 된다.     
  [2164](https://www.acmicpc.net/problem/2164) 문제를 보면 맨 앞의 카드를 뒤로 보내거나 버린다. queue를 이해하기 좋은 문제이다.<br>
  ## Deque     
  Deque의 구현은 queue + α 일 경우 사용하면 된다.    
  α: 선형적으로 들어온 값들이 reverse가 되거나 맨 뒤의 원소가 맨 앞으로 가야하는 상황 또는 반대일 때 필요하다.    
  [1021](https://www.acmicpc.net/problem/1021) 문제: 최소로 움직이는 값을 원하기에, 원소가 위치한 idx를 구하고 그 위치가     
  front에 가깝다면 앞으로 그리고 back에 가깝다면 뒤로 이동하면 된다.    
  [5430](https://www.acmicpc.net/problem/5430) 문제: 선형적으로 들어온 원소를 뒤집는 행위와 앞의 원소를 제거하는 행위가 필요하기에     
  정말 간단하게, 한 번 뒤집었을 경우 원래 deque의 front는 back이 되기에 pop_back을 해주면 된다. 짝수번 뒤집었다면 pop_front를 해주면 된다.<br><br><br>
