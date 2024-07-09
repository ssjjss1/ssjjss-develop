#include<iostream>
#include<vector>
using namespace std;
int n, m, l, k;
const int dx[] = { 1,1,-1,-1 }, dy[] = { -1,1,1,-1 };
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> l >> k;
	for (int i = 1, x, y; i <= k; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	int s = v.size();
	int mx = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			int x = v[i].first, y = v[j].second;
			for (int d = 0; d < 4; d++) {
				int xx = x + l * dx[d], yy = y + l * dy[d];
				int mnx = min(x, xx), mny = min(y, yy), mxx = max(x, xx), mxy = max(y, yy);
				int cnt = 0;
				for (auto p : v) {
					if (mnx <= p.first && mny <= p.second && mxx >= p.first && mxy >= p.second) cnt += 1;
				}
				mx = max(mx, cnt);
			}
		}
	}
	cout << k - mx;
}