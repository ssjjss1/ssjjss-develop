# [Gold II] Coins - 8298 

[문제 링크](https://www.acmicpc.net/problem/8298) 

### 성능 요약

메모리: 56716 KB, 시간: 156 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 누적 합, 트리를 사용한 집합과 맵

### 제출 일자

2024년 3월 21일 21:15:31

### 문제 설명

<p>Joe claims that he has telekinetic abilities. This statement has shocked Stan, who is a confirmed rationalist, and he immediately wanted Joe to prove it.</p>

<p>Joe decided to toss a coin to show what he is capable of. He says that he can do it in such a way, that there will be exactly <em>k</em> times more heads than tails. Stan has written down the results for all tosses and now he wants to find the longest sequence of consecutive tosses, in which heads are exactly <em>k</em> times more common than tails.</p>

### 입력 

 <p>The first line of the standard input contains two integers <em>n</em> and <em>k</em> (3 ≤ <em>n</em> ≤ 1 000 000, 2 ≤ <em>k</em> ≤ <em>n</em> - 1). The first is the number of tosses made by Joe, whereas the meaning of the second number has already been described in the task statement. The second line contains a sequence of <em>n</em> characters describing the outcomes of consecutive tosses. It consists of letters <code>O</code> and <code>R</code> denoting heads and tails respectively.</p>

### 출력 

 <p>Your program should output one integer to the first and only line of the standard output equal to the length of the longest sequence of consecutive tosses, in which there are exactly <em>k</em> times more heads than tails. If such sequence does not exist, your program should output 0.</p>

