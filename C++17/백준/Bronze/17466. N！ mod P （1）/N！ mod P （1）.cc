#include<iostream>
using namespace std;
long long int n;
long long int m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = n-1; i >= 1; i--) {
		n *= i;
		n %= m;
	}
	cout << n;
}