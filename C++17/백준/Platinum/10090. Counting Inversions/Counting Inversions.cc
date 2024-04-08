#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long int ans;
long long int f(int a[], int x, int middle, int y) {
	static int b[2000004];
	long long int i = x, j = middle + 1, idx = x, cnt = 0, sum = 0;
	while (i <= middle && j <= y) {
		if (a[i] < a[j]) b[idx++]=a[i++], sum += cnt;
		else b[idx++]=a[j++], cnt += 1;// x와 y를 1씩 카운팅하면서 서로 비교..1)
	}
	while (i <= middle) b[idx++] = a[i++], sum += cnt;//1)에서 탐색되지 않은 값들을 b에 저장하고 cnt만큼 sum 증가
	while (j <= y) b[idx++] = a[j++];
	for (int k = x; k <= y; k++) a[k] = b[k];//a에 정렬된 수를 복사
	return sum;
}
void g(int a[], int x, int y) {
	if (x == y) return;
	int middle = (x + y) / 2;
	g(a, x, middle);
	g(a, middle + 1, y);//분할 정복
	ans+=f(a, x, middle, y);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int a[2000004];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	g(a, 1, n);
	cout << ans;
}