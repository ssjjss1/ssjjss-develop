#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int n,m;
const int inf = -98765432;
long long int a[1000004];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>m;
	vector<pair<long long int, long long int>> v;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'R') a[i] += (a[i-1]+m);
		else a[i] += (a[i-1]-1);
		v.push_back({ a[i],i });
	}
	sort(v.begin(), v.end());
	long long  int mx = inf;
	long long  int k = inf,p=0;
	for (auto i : v) {
		if (k != i.first) k = i.first, p = i.second;
		else mx = max(mx, i.second - p);
	}
	mx==inf?cout <<0:cout<<mx;
}