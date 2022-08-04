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
  
  # max, min함수와 find(자료구조), next_permutation함수, tie 함수를 알아보자.
