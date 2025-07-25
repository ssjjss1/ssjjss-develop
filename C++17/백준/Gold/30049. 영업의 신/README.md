# [Gold IV] 영업의 신 - 30049 

[문제 링크](https://www.acmicpc.net/problem/30049) 

### 성능 요약

메모리: 13984 KB, 시간: 472 ms

### 분류

구현, 자료 구조

### 제출 일자

2025년 6월 30일 01:36:39

### 문제 설명

<p>ZerOne 주식회사의 사장인 정민이는 느슨해진 직원들에 긴장감을 주기 위해 영업왕을 뽑기로 한다. 각 직원은 총 $M$개의 매장 중에서 $K$개의 매장을 담당하고 있으며, 영업왕은 자신이 맡은 모든 매장에서 누적 매출 1위를 달성한 직원으로 한다. 단, 각 매장의 직원별 누적 매출액은 항상 서로 다르며 감소하지 않는다.</p>

<p>ZerOne 회사의 직원들이 올린 매출의 정보가 시간 순서대로 주어진다고 했을 때, 그때마다의 누적 매출액을 계산하여 영업왕의 수를 구하여라.</p>

### 입력 

 <p>첫 번째 줄에 직원의 수 $N$과 총매장 수 $M$, 각 직원이 맡은 매장의 수 $K$가 공백으로 구분되어 주어진다. $(1 \leq N \leq 300;$ $1 \leq M \leq 10\,000;$ $1 \leq K \leq M)$</p>

<p>두 번째 줄부터 각 직원이 맡은 매장의 번호 $j$와 초기 매출액 $t$가 공백으로 구분되어 한 줄에 $K$번 주어진다. $1$번 직원부터 $N$번 직원까지 순서대로 주어진다. $(1 \leq j \leq M;$ $1 \leq t \leq 10\,000)$</p>

<p>$N+2$ 번째 줄에 직원이 매출을 올린 횟수 $Q$가 주어진다. $(1 \leq Q \leq 1\,000\,000)$</p>

<p>$N+3$ 번째 줄부터 $Q$개의 줄에 걸쳐 매출을 올린 직원의 번호 $i$와 매장 번호 $j$, 누적 매출액 대비 증가한 매출액 $v$가 공백으로 구분되어 시간 순서대로 주어진다. $(1 \leq i \leq N;$ $1 \leq j \leq M;$ $1 \leq v \leq 1\,000)$</p>

<p>입력에 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>현재 영업왕의 수를 $Q$줄에 걸쳐 출력한다.</p>

