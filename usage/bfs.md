# BFS    
## BFS 기본 개념
### Flood Fill     
원래 BFS는 graph 자료구조의 vertex(정점)를 모두 방문하기 위해 사용되는 알고리즘이다.       
BFS는 Breadith 즉, 너비를 우선적으로 방문하기에 한 정점을 기준으로         
그 정점과 incident vertecies(가장 가까이에 있는 정점들)을 방문하고 그 방문된 정점들에게 똑같은 행위를 반복하여 모든 정점을 방문한다.       
이 원리를 이용하여 Flood Fill(예를 들어, 외부 윤곽선 안에 있는 모든 영역을 하나의 색으로 덮어쓰는 알고리즘이다)을 BFS로 구현할 수 있다.      
    
 <img src="https://upload.wikimedia.org/wikipedia/commons/b/b6/Wfm_floodfill_animation_queue.gif"  width="400" height="300"/>     
     
위의 그림은 Flood Fill의 예시이다. 이러한 기능을 BFS로 어떻게 구현해야할까? 큐를 이용하여 구현할 수 있다.
> 1. 상하좌우를 탐색했을 때, 윤곽선을 넘어간다면 탐색을 하지 않는다.
> 2. 상하좌우를 탐색했을 때, 탐색한 곳이 이미 색이 있다면 탐색을 하지 않는다.
    
만약 윤곽선 안이고 연두색이 아니라면 탐색을 돌아 윤곽선 안에 있는 모든 영역을 방문하여 연두색으로 채워주면 된다.  
    
이 알고리즘의 구현을 바탕으로 PS에 등장하는 ***다차원 배열의 각 칸을 너비 우선으로 방문***해야하는 문제들을 해결할 수 있다.  
이 때에도 위의 Flood Fill이나, Graph 자료구조의 BFS와 굉장히 유사하다.   

> 1. 상하좌우를 탐색했을 때, 이차원 배열의 범위를 넘어갔다면 탐색을 하지 않는다.    
> 2. 상하좌우를 탐색했을 때, 이미 탐색한 곳이라면 탐색을 하지 않는다.    
> 3. 탐색이 필요없는 곳이라면, 탐색을 하지 않는다.     
    
이제 ***BFS 구현***을 알아보자.    
우린 기본적으로 네 가지의 자료구조가 필수적으로 필요하다.
> * 방문해야할 이차원 배열(1)    
> * 방문 상태를 저장할 이차원 배열(2)    
> * 상하좌우를 방문하기 위한 배열(3)    
> * 상하좌우(너비)를 우선적으로 방문하기 위한 큐(4)     
    
     
```cpp
#include <queue>
#include <utility>
using namespace std;

int board[100][100]; //(1)
int visited[100][100]; //(2)
int dx[4]{ 0,1,-1,0 }; //(3)
int dy[4]{ 1,0,0,-1 };

int main() {
    queue<pair<int, int>> Q; //(4)
    Q.push({ 0,0 });
    visited[0][0] = 1;
    while (Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
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
## BFS 기초 응용 문제
BFS를 이용하는 문제는 간단하다.    
Graph 자료구조의 BFS는 정점과 정점 사이의 최단 거리를 구할 수 있다. 모든 정점과의 최단 거리를 구할 수 있기 때문에 이 점을 이용하는 문제를 알아보자.     

### BFS는 정점과 정점 사이의 최단거리를 알 수 있다.   
[2178](https://www.acmicpc.net/problem/2178)문제이다. 이 문제를 보면 이차원 배열의 (1, 1)에서 출발하여 (row, col)로 가는 최단 거리를 구해야한다.    
여기서 최단거리를 어떻게 구할까? 한 지점의 상하좌우를 방문한다면, 그 상하좌우를 큐에 넣는다. 그리고 그 네 개의 지점들에 대해서 똑같은 행위를 반복한다.     
첫 번째 네 지점 -> 두 번째 네 지점 방문되는 순서가 큐의 성질과 딱 들어맞는다. 그렇다면 큐에 있는 지점들은 시작점으로 부터 거리순으로 놓이게 된다.                
그렇다면 (row, col)에 도착했을 땐 이미 최단 거리이다. 우린 위에서 본 board 활용하여 시작점부터 한 칸씩 방문되는 정점의 거리를 업데이트해주면 된다. 
```cpp
visited[x][y] = visited[cur.front][cur.second] + 1; 
```   
이런 식으로 visited를 거리로 업데이트를 해준다면, 방문된 사실도 저장할 수 있고 거리도 저장할 수 있게 된다.       
[7576](https://www.acmicpc.net/problem/7576) 이 와 굉장히 비슷한 문제이다.       
    
### 방문해야할 곳을 나눌 수 있다.     
[1926](https://www.acmicpc.net/problem/1926)문제를 보자. 이 문제는 BFS는 상하좌우 탐색을 잘 이해했다면 해결하기 쉽다.     
만약 BFS로 배열을 상하좌우로 탐색하던 도중 방문 가능한 곳이 대각선상 하나만 있다면 어떻게 될까? 당연히 방문을 하지 못할 것이다.          
이 점을 이용하여 우린 배열의 한 지점을 기준으로 방문 가능한 곳을 덩어리 형태로 나눌 수 있다.       
1926문제를 보면, 1로 연결돼 있는 즉, BFS로 탐색할 수 있는 1의 집합(덩어리)를 찾아내면 된다.      
시간 제한이 2초에 배열의 크기가 최대 250000이므로 O(N^2)의 시간 복잡도로 해결할 수 있다.       
이중 반복문을 이용하여 모든 지점을 통해 BFS를 실행한다면 1로 연결돼 있는 영역들의 개수를 구할 수 있게 된다.     
[1012](https://www.acmicpc.net/problem/1012), [10026](https://www.acmicpc.net/problem/10026) 이와 유사한 문제들이다.

