# DFS
YET TO BE WRITTEN    
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
