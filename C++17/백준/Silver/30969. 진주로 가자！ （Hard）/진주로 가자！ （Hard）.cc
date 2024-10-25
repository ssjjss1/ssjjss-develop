#include<iostream>
#include<map>
using namespace std;
long long n, ans, cnt, L=1001;
map<long long, int> ma;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long x;
		string s;
		cin >> s >> x;
		if (s == "jinju") ans = x;
		else ma[min(L,x)]+=1;
	}
	for (auto i : ma) if (i.first > ans) cnt += i.second;
	cout << ans << '\n' << cnt;
}