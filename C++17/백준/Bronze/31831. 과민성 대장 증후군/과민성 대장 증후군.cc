#include<iostream>
using namespace std;
int n, m, cnt;
long long int sum;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		sum += x;
		sum = (sum < 0 ? 0: sum);
		if (sum >= m) cnt += 1;
	}
	cout << cnt;
}