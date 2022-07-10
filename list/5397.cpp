#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        list<char> ans = {};
        string inputs;
        auto p = ans.begin();
            
        cin >> inputs;
        for (char c : inputs) { 
            if (c == '<') {
                if (p != ans.begin()) p--;//begin이 아니라면 자유롭게 커서 이동
            }
            else if (c == '>') {
                if (p != ans.end()) p++;//end가 아니라면 자유롭게 커서 이동(end까지 가게 된다면 커서는 맨 뒤에 위치함)
            }
            else if (c == '-') {
                if (p != ans.begin()) {//(중요)커서가 위치한 곳이 글자의 뒤라고 가정해보자. 그럼 커서 앞의 글자를 삭제해야하는데 end가 맨 뒤에 위치한다고 했을 때 
                  //맨 뒤에 위치한 커서의 앞 글자를 삭제하려면 노드를 한 칸 앞으로 이동시켜주고 삭제를 해야한다.
                    p--;//노드 이동 후 삭제
                    p = ans.erase(p);//이 때 왼쪽으로 shift된 노드를 가리키므로 커서의 위치는 이전과 다를게 없어진다.
                }
            }
            else ans.insert(p, c);//커서 앞에 글자를 입력
        }
        for (char c : ans) cout << c;
        cout << '\n';
    }
}
