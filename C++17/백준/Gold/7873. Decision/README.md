# [Gold V] Decision - 7873 

[문제 링크](https://www.acmicpc.net/problem/7873) 

### 성능 요약

메모리: 6264 KB, 시간: 692 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색, 구현

### 제출 일자

2025년 7월 18일 21:33:43

### 문제 설명

<p>In a galaxy not so far away, in a time where men were real men, women were real women, and small furry creatures from Alpha Centauri were real small furry creatures from Alpha Centauri, an astronom called Mr. Gorsky discovered a small inhabited planet. After an initial enthusiasm (yes, we are not alone!), all the living Nobel Peace Prize winners gathered in one place, formed a committee, and discussed options of invading the planet. Long story short, in order to decide on this important topic, they need to know the number of the cities on the remote planet.</p>

<p>The quality of photos delivered by Mr. Gorsky were unfortunately quite bad: on a rectangular grid, each grid element was either blank (no city there) or (partially) dark, which meant a city or a part of it. If two dark parts share a common edge, they are a part of the same city. The committee then said plainly: “You have to count the number of the cities. Good luck, Mr. Gorsky”.</p>

<p>An example map containing three cities is presented below.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1f5bea0d-90d5-4176-a9ba-e80afca7bbba/-/preview/" style="width: 143px; height: 114px;"></p>

### 입력 

 <p>The input contains several test cases. The first line of the input contains a positive integer Z ≤ 20, denoting the number of test cases. Then Z test cases follow.</p>

<p>The first line of an input instance contains two integers n and m, the photo dimensions, such that 1 ≤ n, m ≤ 1000. The following n lines contain the description of the photo. Each line contains m characters from the set {<code>A</code>, <code>B</code>, <code>C</code>, <code>D</code>, <code>E</code>, <code>F</code>} encoding the grid elements in the following way:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b963381c-60a2-4842-be31-d2dbe41edc0a/-/preview/" style="width: 383px; height: 50px;"></p>

### 출력 

 <p>For each input instance, your program should output one line containing the number of cities on a given map</p>

