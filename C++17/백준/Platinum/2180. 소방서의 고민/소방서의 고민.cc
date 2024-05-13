#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int mod = 40000;
struct P { float f; ll a, b; };
bool compare(const P & x, const P & y) {
	if (x.f == y.f) {
		if (x.a == y.a) {
			return x.b < y.b;
		}
		return x.a < y.a;
	}
	return x.f < y.f;
}
ll n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<P> v;
	ll sum=0,sum1=0;
	for (ll i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		if (x == 0) sum += y;
		else v.push_back({ float(y) / float(x), x,y });
	}
	sort(v.begin(), v.end(),compare);
	ll cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		sum1 += (v[i].a * cnt + v[i].b);
		sum1 %= mod;
		cnt = sum1;
	}
	cout << (sum+sum1)%mod;
}