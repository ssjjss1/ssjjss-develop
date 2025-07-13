#include <bits/stdc++.h>
using namespace std;

struct P {
	int mul, sum, num;
};

bool comp(P &a, P &b) {
	if(a.mul != b.mul) return a.mul < b.mul;
	if(a.sum != b.sum) return a.sum < b.sum;
	return a.num < b.num;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<P> v;
	for(int i = 1; i <= n; i++) {
		int x, a, b, c;
		cin >> x >> a >> b >> c;
		v.push_back({a*b*c, a+b+c, x});
	}

	sort(v.begin(), v.end(), comp);

	cout << v[0].num << " " << v[1].num << " " << v[2].num;
}