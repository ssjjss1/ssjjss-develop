#include<iostream>
using namespace std;
int n,aks;
int a[1001][1001];
long long int sum = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
	}
	int l = 0, r = 987654321;
	while (l <= r) {
		long long int middle = (l + r) / 2,ans=0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++){
				ans += (a[i][j] < middle ? a[i][j] : middle);
			}
		}
		if (ans * 2 >= sum) {
			r = middle - 1;
			aks = middle;
		}
		else l = middle + 1;
	}
	cout << aks;
}