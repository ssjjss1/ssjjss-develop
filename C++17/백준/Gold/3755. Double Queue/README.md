# [Gold IV] Double Queue - 3755 

[문제 링크](https://www.acmicpc.net/problem/3755) 

### 성능 요약

메모리: 6220 KB, 시간: 56 ms

### 분류

자료 구조, 우선순위 큐, 트리를 사용한 집합과 맵

### 제출 일자

2025년 3월 27일 16:54:55

### 문제 설명

<p>The new founded Balkan Investment Group Bank (BIG-Bank) opened a new office in Bucharest, equipped with a modern computing environment provided by IBM Romania, and using modern information technologies. As usual, each client of the bank is identified by a positive integer K and, upon arriving to the bank for some services, he or she receives a positive integer priority P. One of the inventions of the young managers of the bank shocked the software engineer of the serving system. They proposed to break the tradition by sometimes calling the serving desk with the lowest priority instead of that with the highest priority. Thus, the system will receive the following types of request: </p>

<ul>
	<li><code>0</code>: The system needs to stop serving</li>
	<li><code>1 K P</code>: Add client K to the waiting list with priority P</li>
	<li><code>2</code>: Serve the client with the highest priority and drop him or her from the waiting list</li>
	<li><code>3</code>: Serve the client with the lowest priority and drop him or her from the waiting list</li>
</ul>

<p>Your task is to help the software engineer of the bank by writing a program to implement the requested serving policy. </p>

### 입력 

 <p>Each line of the input contains one of the possible requests; only the last line contains the stop-request (code 0). You may assume that when there is a request to include a new client in the list (code 1), there is no other request in the list of the same client or with the same priority. An identifier K is always less than 10<sup>6</sup>, and a priority P is less than 10<sup>7</sup>. The client may arrive for being served multiple times, and each time may obtain a different priority. </p>

### 출력 

 <p>For each request with code 2 or 3, the program has to print, in a separate line of the standard output, the identifier of the served client. If the request arrives when the waiting list is empty, then the program prints zero (0) to the output. </p>

