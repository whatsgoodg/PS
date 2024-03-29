# DFS     
## DFS 기본 개념    
### Flood Fill  
원래 BFS는 graph 자료구조의 vertex(정점)를 모두 방문하기 위해 사용되는 알고리즘이다.       
DFS는 Depth 즉, 깊이를 우선적으로 방문하기에 한 정점을 기준으로         
그 정점과 incident vertecies(가장 가까이에 있는 정점들)중 한 곳을 우선적으로 방문하고 방문된 정점을 기준으로 반복한다.         
이 원리를 이용하여 Flood Fill(예를 들어, 외부 윤곽선 안에 있는 모든 영역을 하나의 색으로 덮어쓰는 알고리즘이다)을 DFS로 방문할 수 있다.        
          
 <img src="https://upload.wikimedia.org/wikipedia/commons/5/5e/Wfm_floodfill_animation_stack.gif"  width="400" height="300"/>        
        
위의 그림은 Flood Fill의 예시이다. 이러한 기능을 DFS로 어떻게 구현해야할까? 스택를 이용하여 구현할 수 있다.        
> 1. 시작 정점의 상하좌우 정점들을 Stack에 넣는다.       
> 2. Stack의 top을 방문하고 이를 기준으로 상하좌우 정점들을 Stack에 넣는다.       
         
방문이 끝났을 때 이전의 정점의 상하좌우중 탐색하지 않은 곳을 위의 행위를 반복할 것이다.         
방문이 끝나는 기준은 이렇다.       
       
> 1. 윤곽선에 다다랐을 때 탐색을 멈춘다.          
> 2. 이미 색이 채워져 있다면 탐색을 멈춘다.         
       
이는 BFS와 동일하다.        
        
## DFS vs BFS
### DFS     
DFS Depth(깊이)를 우선적으로 탐색하기 때문에 네 방향(상하좌우)중 한 곳만 먼저 탐색한다. 그렇기 때문에 Stack을 이용하는 것이다.     
Stack은 FILO란 특성을 가지고 있기 때문에, 맨 마지막으로 들어온 방향(정점)이 맨 처음으로 나간다.     
이는 계속해서 업데이트 되는 한 방향의 탐색이 위의 방문이 끝나는 조건에 부합하기 이전까진 계속해서 탐색이 이루어진다는 것이다.      
### BFS    
BFS는 Breadith(너비)를 우선적으로 탐색하기 때문에 네 방향(상하좌우)를 모두 탐색한다. 이러한 이유로 Queue를 이용하는 것이다. 
Queue는 FIFO란 특성을 가지고 있기 때문에, 맨 처음으로 들어온 네 방향이 Stack과 다르게 먼저 나갈 우선순위를 가지게 된다.     
그렇기 때문에 네 방향이 먼저 탐색되는 것이다.     

이제 ***DFS 구현***을 알아보자.    
우린 기본적으로 네 가지의 자료구조가 필수적으로 필요하다.
> * 방문해야할 이차원 배열(1)    
> * 방문 상태를 저장할 이차원 배열(2)    
> * 상하좌우를 방문하기 위한 배열(3)    
> * 상하좌우 중 한 곳(깊이)를 우선적으로 방문하기 위한 Stack(4)     

```cpp
#include <stack>
#include <utility>
using namespace std;

int board[100][100]; //(1)
int visited[100][100]; //(2)
int dx[4]{ 0,1,-1,0 }; //(3)
int dy[4]{ 1,0,0,-1 };

int main() {
    stack<pair<int, int>> S; //(4)
    Q.push({ 0,0 });
    visited[0][0] = 1;
    while (Q.empty()) {
        pair<int, int> cur = Q.top(); Q.pop();
        for (int i = 0; i < 4; i++) {
	    int x = cur.first + dx[i];
	    int y = cur.second + dy[i];
            if (x < 0 || x >= 100 || y < 0 || y >= 100) continue;
	    if (visited[x][y] || !board[x][y]) continue;
	    visited[x][y] = 1;
	    Q.push({ x,y });
        }
    }
}
```       
> 이는 Stack 자료구조를 이용하여 구현한 것이다.     
> 하지만 대개 DFS는 대개 재귀함수로 많이 구현된다.      
> 왜냐하면 BFS로 DFS의 기능에 가장 짧은 경로도 알 수 있기 때문이다.     
> 그렇기 때문에 DFS는 재귀함수 형태로 ***backtracking*** 알고리즘을 구현하기 위하여 사용된다.           
> BFS와 DFS는 방법론이다. 이차원 배열에 DFS와 BFS를 사용할 수 있는 이유는 모든 데이터에 대해서            
> 그래프의 형태로 적용할 수 있기 때문이다. 하나의 배열의 cell을 기준으로 상하좌우의 cells은 incident vertices이다.           
> 그리고 각 cell의 간선은 index이며 이는 이차원 배열을 무방향 그래프로 모델링한 것이다.           
