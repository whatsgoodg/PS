[이진 검색 트리](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#binary-search-tree) 포스트를 먼저 확인하자.               
                           
# 이진 탐색 트리                     
위의 포스트를 확인했다면, 단순하게 **STL의 사용법**을 익히고 다양한 문제를 풀면 된다.                   
set, multiset, map 등이 있으며 기존에 배운 해시함수를 위한 unordered 자료구조와의 **차이**는 다음과 같다.    

```
                |     set             | unordered_set                     
---------------------------------------------------------                  
Ordering        | increasing  order   | no ordering                   
                | (by default)        |                
                     
Implementation  | Self balancing BST  | Hash Table                   
                | like Red-Black Tree |                                  
             
search time     | log(n)              | O(1) -> Average               
                |                     | O(n) -> Worst Case                    
                   
Insertion time  | log(n) + Rebalance  | Same as search                 
                          
Deletion time   | log(n) + Rebalance  | Same as search    
```
                 
정렬 유무, 시간복잡도에서 알 수 있는 점은 어느 문제에서 두 자료구조를 사용할지 정하는 것이다.            
일반적인 set, map에서 제공하는 __prev, next, lower_bound__ 멤버를 사용해야한다면 set을 사용하는 것이 좋다.                    
만약 원소의 __삽입/검색/삭제__만 빠르게 처리를 해야하는 상황이면 unordered 자료구조를 사용하는 것이 좋다.              
평균적으론 unordered 자료구조가 빠르지만, **충돌 횟수가 많다**면 성능 저하가 일어나기 때문에, 항상 빠르게 동작하는 것을 보장할 수 없다.                
반면 set 자료구조는 무조건 lgN이기 때문에 시간복잡도를 정확하게 계산할 수 있다. ~~웬만하면 set 쓰자..~~           
그런데 set은 lgN 연산 중에 **조금 무거운** 편이다. balance를 조절하거나 무거운 연산이 많기 때문에 이분탐색, 정렬보다 느리다고 할 수 있다.           
시간복잡도를 계산했을 때 간당간당할 수 있다.             
