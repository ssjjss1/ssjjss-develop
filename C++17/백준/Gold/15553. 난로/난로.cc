#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n, m;
int d[100001];
struct P{
	int a,b,c;
};
bool compare(const P& x, const P& y) {
	return x.a < y.a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	map<int, int> ma;
	vector<P> v;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	for (int i = 1, x; i < n; i++) {
		v.push_back({ d[i + 1] - d[i],d[i],d[i + 1] });
	}
	sort(v.begin(), v.end(), compare);
	int k = n - m;
	long long cnt = 0;
	for (int i = 0; i < k;i++) {
		if (ma[v[i].b] && ma[v[i].c]) cnt += v[i].a - 1;
		else if (ma[v[i].b] || ma[v[i].c]) cnt += v[i].a;
		else cnt += (v[i].a + 1);
		ma[v[i].b] = 1, ma[v[i].c] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!ma[d[i]]) cnt += 1;
	}
	cout << cnt;
}