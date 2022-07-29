# 백트래킹
백트래킹이란 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘이다.       
이렇게만 듣는다면 완전탐색인 부르트포스랑 차이점이 없어 보인다. 그러나 용어에서 보았을 때 백트래킹은 이전상태(back)를 추적한다.(tracking)      
이전상태로 돌아가는 행위를 ***가지치기***라고 부른다.     
그렇다면 백트래킹은 완점탐색을 하던 도중에 결과와 맞지 않는 경우의 수가 등장했을 경우 탐색을 중단한다.     
### 백트래킹의 성질
> 1. 모든 경우의 수를 탐색한다.
> 2. 모든 경우의 수를 탐색하던 도중 결과와 맞지 않는 조건에 해당되면 탐색을 즉시 종료하고 이전 상태로 돌아간다.
             
부르트포스 알고리즘은 BFS, DFS, 선형 자료구조 등 다양하게 구현될 수 있고 사용될 수 있다. 그냥 완전탐색을 한다면 그건 부르트 포싱인 것이다.     
그런데 만약 완전탐색에 가지치기를 더한다면 어떻게 구현을 해야할까?      

### 가지치기  
백트래킹은 완전탐색 도중 가지치기를 한다. 이는 결과와 적합하지 않다면, 즉시 탐색을 중단하고 이전 상태로 돌아가 또 다른 경우의 수를 탐색한다.     
이는 Stack 자료구조와 딱 들어맞는다. Stack을 이용한 탐색 중 DFS를 본다면 하나의 경우의 수(한 방향의 깊이)를 탐색하다가 그 방향의 탐색이 끝났을 경우     
그 이전의 다른 방향을 탐색하는 성질을 가진다. 이는 완전탐색을 DFS로 구현한 경우이며 우리가 흔히 아는 부르트포스 알고리즘이다. 
그렇다면 이런 결과가 나오게 된다.
> 1. Stack 자료구조를 사용하는 DFS는 백트래킹과 매우 유사하다.
> 2. DFS는 (백트래킹-가지치기) 형태이다.
> ***결론적으로 DFS에 탐색 조건을 추가한다면 백트래킹 알고리즘이 되는 것이다.***         <br><br><br>

## 시간복잡도   
DFS말고 백트래킹을 사용하는 이유가 무엇일까?       
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Depthfirst.png/250px-Depthfirst.png"  width="400" height="300"/>      
이는 DFS의 이미지이며, 트리의 한 방향을 우선 탐색하는 것을 볼 수 있다. 탐색이 끝났을 경우 그 깊이에서의 모든 조건을 탐색하기 위해     
같은 깊이의 다음 노드를 탐색하는 것을 볼 수 있다. 위의 이미지처럼 tree의 가장 깊은 깊이에 도달했을 때 탐색을 끝낸다면 시간복잡도가 굉장히 클 수 있다.
완전탐색에서 시간복잡도를 줄이기 위해 백트래킹을 사용한다.       
백트래킹을 사용한다면 위의 이미지에서 깊이 2의 가장 왼쪽에 있는 노드가 조건에 부합하지 않는다면 탐색을 바로 종료하고 그 이전으로 돌아간다.    

### 재귀함수
DFS를 반복문으로 구현한다면 Stack 자료구조를 사용하게 된다. Stack을 사용하여, 네 가지의 방향중 한 방향만 우선 탐색을 진행한다.      
만약 이렇게 Stack 자료구조를 사용한다면 모든 경우의수를 탐색하기 이전에 Stack에 모두 저장해야 하며, 이는 재귀함수보다 시간복잡도가 늘어난다.     
시간복잡도를 줄이기 위해 재귀함수를 사용한다면 경우의 수 한 가지씩만 메모리(스택)에 저장해두고 가지치기를 하거나 탐색이 끝났을 때     
다른 경우의 수를 저장하기 때문에 시간복잡도 상에서 유리하기 때문에 재귀함수를 사용한다.    
하지만 stackoverflow 즉, 스택 메모리가 넘치는 상황이 발생할 수 있기 때문에 상황에 맞게 잘 사용해야한다.     
