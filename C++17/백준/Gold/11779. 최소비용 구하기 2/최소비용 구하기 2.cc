#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 987654321;
int n, m, b, c;
int a[100001], d[100001];
vector<pair<int, int>> v[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1,x,y,z; i <= m; i++) {
		cin >> x >> y >> z;
		v[x].push_back({ y,z });
	}
	cin >> b >> c;
	fill(a, a + 100001, inf);
	priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int,int>>> q;
	q.push({ 0,b });
	a[b] = 0;
	while (!q.empty()) {
		int x = q.top().second, y = q.top().first;
		q.pop();
		if (a[x] != y)continue;
		for (auto i : v[x]) {
			int p = i.first, l = i.second;
			if (a[p] > a[x] + l) {
				a[p] = a[x] + l;
				d[p] = x;
				q.push({ a[p],p });
			}
		}
	}
	cout << a[c]<<"\n";
	int k = c;
	vector<int> v;
	v.push_back(c);
	while (k != b) {
		v.push_back(d[k]);
		k = d[k];
	}
	reverse(v.begin(), v.end());
	cout << v.size()<<"\n";
	for (auto i : v) {
		cout << i << " ";
	}
}