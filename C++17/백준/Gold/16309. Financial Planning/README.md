# [Gold IV] Financial Planning - 16309 

[문제 링크](https://www.acmicpc.net/problem/16309) 

### 성능 요약

메모리: 3584 KB, 시간: 24 ms

### 분류

이분 탐색, 그리디 알고리즘

### 제출 일자

2025년 2월 26일 22:34:14

### 문제 설명

<p>Being a responsible young adult, you have decided to start planning for retirement. Doing some back-of-the-envelope calculations, you figured out you need at least M euros to retire comfortably.</p>

<p>You are currently broke, but fortunately a generous gazillionaire friend has offered to lend you an arbitrary amount of money (as much as you need), without interest, to invest in the stock market. After making some profits you will then return the original sum to your friend, leaving you with the remainder.</p>

<p>Available to you are n investment opportunities, the i-th of which costs c<sub>i</sub> euros. You also used your computer science skills to predict that the i-th investment will earn you p<sub>i</sub> euros per day. What is the minimum number of days you need before you can pay back your friend and retire?</p>

<p>For example, consider the first sample. If you buy only the second investment (which costs 15 euros) you will earn p<sub>2</sub> = 10 euros per day. After two days you will have earned 20 euros, exactly enough to pay off your friend (from whom you borrowed 15 euros) and retire with the remaining profits (5 euros). There is no way to make a net amount of 5 euros in a single day, so two days is the fastest possible.</p>

### 입력 

 <ul>
	<li>The first line contains the number of investment options 1 ≤ n ≤ 10<sup>5</sup> and the minimum amount of money you need to retire 1 ≤ M ≤ 10<sup>9</sup>.</li>
	<li>Then, n lines follow. Each line i has two integers: the daily profits of this investment 1 ≤ p<sub>i</sub> ≤ 10<sup>9</sup> and its initial cost 1 ≤ c<sub>i</sub> ≤ 10<sup>9</sup>.</li>
</ul>

### 출력 

 <p>Print the minimum number of days needed to recoup your investments and retire with at least M euros, if you follow an optimal investment strategy.</p>

