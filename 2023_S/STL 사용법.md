# C++ STL 사용법 정리

## Map
* 딕셔너리 같은거
* 레드블랙트리로 구현
* pair로 구현
* key 기준 오름차순 자동정렬
<details>
<summary>더 보기</summary>

### 선언
map<key, value> map1; <br>
ex) map<string, int> dict; <br>
ex) map<string,string,greater<string>> log;

#### 데이터 확인
find, end <br>
ex) if( m.find("Alice") != m.end() )

### 삽입 삭제
insert, erase

### 원소 접근 
iterator
</details>

## 비교 함수 오버라이딩

### sort
sort는 그냥 함수 만들면 된다 bool을 반환하는 함수를 call by reference로 사용하면 된다.<br><br>
return하는 방향으로 정리된다.

### 우선순위 큐
sort 처럼 함수를 만드는데 구조체 안에 넣고 ()operator를 오버라이딩 해야한다 <br>
##### 예시
```
sturct compare{
    bool operator() (string& a, string& b) {
        return a<b;
    }
}

```
이 때 compare는 우선순위 큐 비교에 사용되는 함수 return 이 true이면 swap 한다. a가 원래 존재하던 녀석 b가 지금 침입한 녀석이다.<br><br>
지금 b가 더 클 때 바꾸니까 top 은 가장 큰 녀석이 차지한다.
