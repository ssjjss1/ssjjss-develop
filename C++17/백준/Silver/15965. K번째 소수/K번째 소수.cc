#include<iostream>
#include<vector>
using namespace std;
long long int n;
vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<bool> a(8000000, true);
	for (int i = 2; i <= 7368788; i++) {
		if (a[i] == true) {
			v.push_back(i);
			for (int j = 2 * i; j <= 7368788; j += i) {
				a[j] = false;
			}
		}
	}
	cout << v[n - 1];
}