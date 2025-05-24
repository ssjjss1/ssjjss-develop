# [Gold V] Dance Recital - 11533 

[문제 링크](https://www.acmicpc.net/problem/11533) 

### 성능 요약

메모리: 2024 KB, 시간: 316 ms

### 분류

백트래킹, 브루트포스 알고리즘, 재귀

### 제출 일자

2025년 5월 24일 15:04:31

### 문제 설명

<p>The Production Manager of a dance company has been tasked with determining the cost for the seasonal dance recital. Because of their exceptional skills, many dancers will perform in more than one routine, but this presents a problem; each dance routine incorporates a unique costume, so between routines, dancers must report backstage to a Wardrobe Specialist, who can change the dancer’s costume in time to begin their next scheduled routine.</p>

<p>A Wardrobe Specialist does a normal change on a dancer when the dancer performs in two routines that are not consecutive, but when a dancer is required to perform in two consecutive routines, a quick change is necessary. A Wardrobe Specialist charges a flat rate per recital that covers all normal changes, but charges an exorbitant amount for each quick change. The Production Manager is responsible for keeping the show under budget, and has hired you to write a program to report the minimum number of quick changes needed for a given recital, given that the order of the dance routines could be changed.</p>

<p>To describe the cast of dancers that are to perform during a recital, each dancer is assigned an identifying uppercase letter. (Fortunately, there are never more than 26 dancers, so characters from A to Z suffice.) To describe a full recital, a list of individual routines is given, with a string of characters defining which dancers appear in a routine. For example, consider the following recital description:</p>

<pre>ABC
ABEF
DEF
ABCDE
FGH</pre>

<p>The above list describes a recital with 5 dance routines, including a total of 8 individual performers (dancers A through H). The first routine listed includes dancers {A, B, and C}. The second routine includes dancers {A, B, E, and F}. Notice that if these first two routines are performed in the above order, dancers A and B will require a quick change between the routines. In fact, if these five routines are scheduled in the order given above, a total of six quick changes are required. However, the schedule can be rearranged as follows:</p>

<pre>ABEF
DEF
ABC
FGH
ABCDE</pre>

<p>In this case, only two quick changes are required (those for E and F between the first two dances).</p>

### 입력 

 <p>The first line contains a single integer R, with 2 ≤ R ≤ 10, that indicates the number of routines in the recital. Following that will be R additional lines, each describing the dancers for one routine in the form of a nonempty string of up to 26 non-repeating, lexicographically sorted uppercase alphabetic characters identifying the dancers who perform in that routine. Although a dancer’s letter will not appear more than once in a single routine, that dancer may appear in many different routines, and it may be that two or more routines have the identical set of dancers.</p>

### 출력 

 <p>Output a single integer designating the minimum number of quick changes required for the recital.</p>

