#include<iostream>
using namespace std;
typedef long long int ll;
int t;
ll k;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> k;
		if (k % 2 == 1) {
			cout << k * (k - 1) * (k - 2)<<"\n";
		}
		else {
			if (k % 3 == 0) cout << (k-1) * (k - 2) * (k - 3) << "\n";
			else {
				cout << k * (k - 1) * (k - 3)<<"\n";
			}
		}
	}
}