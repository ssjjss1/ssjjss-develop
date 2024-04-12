#include<iostream>
using namespace std;
int n;
int a[1001][1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin>>a[i][j];
		}
	}
	for (int i = n; i > 1; i--) {
		for (int j = 1; j < i; j++) {
			a[i - 1][j] += max(a[i][j], a[i][j + 1]);
		}
	}
	cout << a[1][1];
}