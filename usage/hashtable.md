# HashTable
HashTable을 이용한 PS에 집중하여 포스팅합니다.                   
[HashTable](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#hash-table) 참고.                           
**`Linear Probing`**               
충돌 발생 시 오른쪽으로 한 칸씩 이동하는 방법.              
>* Cache hit ratio가 높다.(공간적 지역성)
>* Clustering이 생겨 성능에 영향을 준다: 충돌이 많이 발생될수록 Linear probing의 횟수가 더 많아진다.
                
**`Quadratic Probing`**             
충돌 발생 시 오른쪽으로 n^2(n=1,2,..) 칸씩 이동하는 방법
>* Cache hit ratio가 괜찮다. 
>* Clustering을 어느정도 회피할 수 있다. 충돌 발생 시, 무조건적으로 Clustering이 발생하지 않음.
                
**`Double Hashing`**
충돌 발생 시 이동할 칸의 수를 새로운 해시 함수로 계산하는 방식
>* Clustering을 효과적으로 피할 수 있다.
>* Cache hit ratio가 낮다.
       
## STL
`예제코드`              
* [unordered_set](https://github.com/whatsgoodg/PS/blob/main/hashtable/unorder_set.cpp)               
* [unordered_multiset](https://github.com/whatsgoodg/PS/blob/main/hashtable/unorder_multiset.cpp)                 
* [unordered_map](https://github.com/whatsgoodg/PS/blob/main/hashtable/unorder_map.cpp)                        
