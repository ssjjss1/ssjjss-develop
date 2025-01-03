# [Gold IV] 제기차기 - 23830 

[문제 링크](https://www.acmicpc.net/problem/23830) 

### 성능 요약

메모리: 2412 KB, 시간: 16 ms

### 분류

이분 탐색, 매개 변수 탐색

### 제출 일자

2024년 11월 19일 14:37:37

### 문제 설명

<p>얼마 전 학교 체육대회 "사차원"이 열렸다. 대회 종목 중 하나는 제기차기였고, 몇몇 학생을 제외하고는 대부분의 학생이 한두 번 밖에 차지 못했다. 잘 하는 사람과 못 하는 사람의 점수 차이가 너무 커졌기 때문에, 대회 전체 점수에 영향이 클 거라고 생각한 선생님은 다음과 같은 규칙을 정했다.</p>

<ul>
	<li>기준이 되는 양의 정수 $K$를 정한다.</li>
	<li>어떤 학생의 제기차기 점수가 $K+r$ 초과라면 그 학생의 점수에서 $p$를 뺀다.</li>
	<li>어떤 학생의 제기차기 점수이 $K$ 미만이라면 그 학생의 점수에 $q$를 더한다.</li>
</ul>

<p>선생님은 이 규칙으로 점수를 계산한 후에, 전교생의 제기차기 점수 합이 $S$ 미만이라면, 학생들에게 제기차기를 충분히 연습시키지 못한 태영이에게 체육관 청소를 시킬 예정이다. 선생님은 $p, q, r, S$를 정한 후에 태영이에게 $K$를 정해달라고 했다. 태영이가 청소를 하지 않아도 되도록 $K$를 정하는 방법이 있는지, 있다면 $K$로 가능한 최솟값은 얼마인지 구하여라.</p>

### 입력 

 <p>첫째 줄에 전교생 수 $N$이 주어진다.</p>

<p>둘째 줄에 학생 $N$ 명의 제기차기 점수 $A_1, A_2, \cdots, A_N$이 공백으로 구분되어 주어진다.</p>

<p>셋째 줄에 선생님이 정한 상수 $p, q, r, S$가 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>태영이가 청소를 하지 않아도 되는 $K$의 최솟값을 출력한다. 만약에 어떻게 $K$를 정해도 태영이가 청소를 해야 한다면,  $-1$을 출력한다.</p>

