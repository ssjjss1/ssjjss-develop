#include<iostream>
using namespace std;
int n,m;
int a[1000001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long int r = 0, l = 1e18,aks;
	while (r <= l) {
		long long int middle = (r + l) / 2,ans=0;
		for (int i = 1; i <= n; i++) {
			ans += middle / (a[i]);
		}
		if (ans >= m) {
			l = middle - 1;
			aks = middle;
		}
		else r = middle + 1;
	}
	cout << aks;
}