# [Platinum V] 수열과 병규 - 34017 

[문제 링크](https://www.acmicpc.net/problem/34017) 

### 성능 요약

메모리: 2020 KB, 시간: 124 ms

### 분류

수학, 재귀

### 제출 일자

2025년 6월 29일 16:33:17

### 문제 설명

<p>특이한 수열을 만드는 게 취미인 병규는 다음과 같은 수열 $a$를 만들었다.</p>

<p>$a_1 = 1, a_2 = 2$이며 모든 양의 정수 $n$에 대해 아래 식을 만족한다.</p>

<ul>
	<li>$a_{3n} = 2a_n + 2a_{n+1} + 1$</li>
	<li>$a_{3n+1} = 2a_{n+2} - 1$</li>
	<li>$a_{3n+2} = -2a_{n+1} - 2a_{n+2} + 2$</li>
</ul>

<p>$S_n = a_1 + a_2 + \cdots + a_n$이라 할 때, 병규는 $S_n$을 빠르게 구하는 방법을 찾고 싶다. 병규를 위해 이 문제를 풀어주자.</p>

### 입력 

 <p>첫째 줄에 쿼리의 개수 $Q$가 주어진다. $(1 \leq Q \leq 200\,000)$</p>

<p>둘째 줄부터 $Q$개의 줄에 걸쳐 $n$이 주어진다. $(1 \leq n \leq 10^{18})$</p>

<p>입력으로 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>각 줄에 $S_n$을 한 줄에 하나씩 순서대로 출력한다.</p>

