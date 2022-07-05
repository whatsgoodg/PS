<h1>For Coding Test</h1>
There will be codse for BackJoon wrritten in C++<br>
The names of files will be the problem number<br>
Codes will be explained by comments if a problem is considered easy<br>
If it's considered hard, codes will be explained with an extra file<br>
Algorithms are going to be written in Data Structur & Algorithms repo<br><br><br><br><br><br><br><br>


<h1>Skills for Problem Solving</h1>
  <h2>1. Useful Tips</h2>
  <h3>Let's use bits/stdc++.h </h3>
  gcc 계열의 컴파일러를 사용하지 않는다면 따로 설정을 해주어야 하지만 매우 간단하다.<br>
  굳이 헤더를 모두 작성할 필요 없이 한 줄로 간결하게 끝낼 수 있다.<br>
  컴파일 시간이 좀 늘어날지 몰라도 코딩 테스트에선 이점을 얻을 수 있다.<br><br><br>
  
  <h3>ios::sync_with_stdio(0)</h3>
  간단히 cout과 scanf를 같이 사용한다면 순서에 맞게 출력이 되어야 하므로 C++ stream과 C stream는 동기화가 이루어진다.<br>
  이것을 끊어줌으로써 시간 복잡도 측면에서 이득이다.<br> 
  이후에 scanf나 printf를 사용하면 안 된다.<br><br><br>
  
  <h3>cin.tie(0)</h3>
  C++에서 입력 후에 출력 순서를 맞추어 주기 위해 cin을 받기 전에 cout 버퍼를 모두 비워준다.<br>
  이러한 flush는 시간이 상당히 걸리기에, 이것을 cin과 cout의 tie를 풀어준다.<br>
  같은 맥락으로 endl는 절대 사용하지 않는다.<br><br><br><br><br><br>
  
  <h2>2. Useful Functions</h2>
  <h3>max_element (ForwardIterator first, ForwardIterator last)</h3>
  <algorithm> header에 있는 함수이다.<br>
  first: begin을 가리키는 iterator(주소)를 인자로 전달한다.<br>
  last: end를 가리키는 iterator(주소)를 인자로 전달한다.<br>
  return: 가장 큰 원소를 가리키는 iterator를 반환한다.<br>
  동일한 원소가 두 개 이상 저장되어 있다면 가장 첫 번째의 원소를 가리키는 iterator를 반환한다.<br>
  size < 1 경우, end를 가리키는 iterator를 반환한다.<br><br><br>
  <h3>fill (ForwardIterator first, ForwardIterator last, val v)</h3>
  <algorithm> header에 있는 함수이다.<br>
  container의 [first, last) 범위에 있는 모든 원소를 v로 초기화하는 함수이다.<br>
  첫 번째, 두 번째 인자는 위의 함수와 동일하다.<br>
  return: (x) <br>
