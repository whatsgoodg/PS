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
                
  ## Implementation
  구조체나 클래스를 사용하여 구현하는 정석적인 리스트가 아닌, 코딩 테스트를 위해 배열을 이용하여 구현하는 리스트를 알아보자.           
  ```cpp
  const int MX = 1000005;
  int dat[MX], pre[MX], nxt[MX];
  int unused = 1;
  
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  ```             
  **`dat`** 는 노드의 값, **`prv`** 는 i 번째 원소에 대해 이전 원소의 인덱스, **`nxt`** 는 다음 원소의 인덱스이다.               
  prv, nxt의 값이 -1이면 해당 원소의 이전/다음 원소가 존재하지 않는다는 의미이다.                                
  `unused` 현재 사용되지 않는 인덱스(새로운 원소가 들어갈 곳)이고, 원소가 추가되면 1씩 증가한다.                 
  0번지는 연결 리스트의 시작 원소로 고정되어 있다. 이는 시작점을 나타내는 `dummy node`이다.                
  그렇다면 **dummy node**는 자연스럽게 `head`이다. 하지만 **unused**는 `tail`이 아니다. 이를 위한 구현은 맨 밑에서 _소스코드_ 에서 알아보자.     
                    
  ![image](https://user-images.githubusercontent.com/86244920/210210055-f7caa9aa-a19f-4c79-893e-8de43acc2581.png)               
                      
  위의 사진을 보고 원리를 이해하자.        
  위의 사진에서 보듯이 dummy node는 head라 하자. 그렇기 때문에 insert는 특정 노드 **뒤**에 삽입된다. 이점을 유의하자. 
  
  리스트의 모든 원소를 출력하는 `traverse`함수를 알아보자. 이해하기 굉장히 간단할 것이다.                
  ### traverse          
  ```cpp
  void traverse() {
	  int cur = nxt[0];
	  while (cur != -1) {
		 cout << dat[cur] << ' ';
		 cur = nxt[cur];
	  }
	  cout << "\n\n";
 }
  ```
  ### insert
  insert 함수의 조건은 아래와 같다.    
  >1. 새로운 원소를 생성
  >2. 새 원소의 pre 값에 삽입할 위치의 주소를 대입
  >3. 새 원소의 nxt 값에 삽입할 위치의 nxt 값을 대입
  >4. 삽입할 위치의 nxt 값과 삽입할 위치의 다음 원소의 pre 값을 새 원소로 변경     
  >5. unused 1 증가
               
  ```cpp
  void insert(int addr, int num) {
	dat[unused] = num;//1
	pre[unused] = addr;///2
	nxt[unused] = nxt[addr];//3
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;//4 마지막 부분에 원소 삽입시. 예외처리
	nxt[addr] = unused;//4
	if(nxt[unused] == -1){
		int tmp = unused;
		unused++;//5
		unused[pre] = tmp;
	}
	else unused++;
  }
  ```
  ### erase
  erase 함수의 조건은 아래와 같다.            
  >1. 이전 위치의 nxt를 삭제할 위치의 nxt로 변경                 
  >2. 다음 위치의 pre를 삭제할 위치의 pre로 변경               
  
  ```cpp
  void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; //마지막 원소를 지울 때 예외처리
  }
  ```
[소스코드](https://github.com/whatsgoodg/PS/blob/main/list/implementation.cpp)                 
