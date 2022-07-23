 # List     
  리스트를 사용한 알고리즘 문제는 그리 많지 않다고 한다. 아마도 다른 자료구조들로 충분히 구현이 가능하기 때문이라고 생각한다.    
  텍스트 편집기를 연상케 하는 문제를 이용하여 STL list(이중연결)를 어느정도 익힐 수 있다. 그럼 문제 [5397](https://www.acmicpc.net/problem/5397)을 보자.    
  굉장히 간단한 문제라고 생각했지만 계속 예외가 나와서 당황한 문제이다. 이미지를 보면 이해가 굉장히 빨라진다.(탭에 그려볼걸..)    
  <img src="https://github.com/whatsgoodg/Codes_for_tests/blob/main/images/LIST.JPG?raw=true"  width="500" height="200"/>     
  위의 사진을 보면 begin은 맨 처음 원소를 가리키는 iterator이다. end는 맨 마지막 원소 **다음**이다.    
  이것은 **past-the-end**라고 불리며 맨 마지막 원소 다음이니 이미지와 같이 노드를 가리키는게 아니다. 마지막 노드 다음을 가리키는 것이다    
  그리고 list가 비어있는 상태엔 begin과 end가 동일하다.    
  ## insert     
  만약 아무 원소도 가지지 않은 list에 반복자를 사용하여 원소를 추가했을시    
  begin에 노드가 추가되고 반복자는 여전히 end를 가리킨다.   
  
  ```cpp    
     list<char> inputs;//empty        
     auto it = inputs.begin();//begin=end    
     inputs.insert(it, 1);    
     cout << *it << endl;//run-error: end는 아무 원소도 가리키지 않으므로 역참조 불가능    
  ```    
 
  이 end를 이용하여 우린 텍스트 에디터 커서의 맨 마지막 자리를 표현해주면 된다.(글자가 입력되고 커서는 여전히 글자 뒤에 존재한다.)    
  ## erase    
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
