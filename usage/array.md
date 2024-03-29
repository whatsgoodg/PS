# Array
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
