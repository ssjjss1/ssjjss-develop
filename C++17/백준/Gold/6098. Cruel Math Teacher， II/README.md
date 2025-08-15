# [Gold III] Cruel Math Teacher, II - 6098 

[문제 링크](https://www.acmicpc.net/problem/6098) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

이분 탐색, 수학, 수치해석, 매개 변수 탐색

### 제출 일자

2025년 8월 15일 21:54:08

### 문제 설명

<p>As if powers of numbers were not cruel enough, Bessie's cruel math teacher has created yet another cruel assignment: Find the 'root' or 'zero' of a polynomial. All of these polynomials have a highest degree D (1 <= D <= 11) that is odd and have but a single solution in the range -1,000,000 <= X <= 1,000,000; for that solution, the polynomial's value when evaluated for X is very close or equal to to 0 in computer math.</p>

<p>Given a polynomial with real number coefficients (-500 <= coef_i <= 500), find a value of X that is within 0.0005 of the value of X that will yield 0 when the polynomial is evaluated. Multiply that value of X by 1,000 and print it as an (unrounded) integer.</p>

<p>By way of example, consider the cubic polynomial problem 1.5*x*x*x - 10 = 0.  Astute algebra students will quickly recognize a solution for this as x*x*x = 100/15 = 20/3 = 6.66666. To five decimal places, the exactly solution is 1.88207. For this task, the proper output would be 1882.</p>

<p>The polynomial is expressed as the sum from i=0..D of coef_i*x^i (where x^i means x to the i-th power).</p>

<p>No answer will require more than six significant digits and each answer will be small enough that it is able to be incremented by 0.0001 in the 'double' precision floating point datatype without losing lots of precision.</p>

<p>HINT: Find a strategy to narrow the search space each time you choose a new X value as a guess.</p>

<p> </p>

### 입력 

 <ul>
	<li>Line 1: A single integer: D</li>
	<li>Lines 2..D+2: Line i+2 contains a single real number: coef_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the truncated product of 1,000 and the X value that is closest to the X value that causes the polynomial to evaluate to 0</li>
</ul>

<p> </p>

