#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Point {
      public:
	ll x, y;
	int num;
};

vector<Point> points;

ll ccw(Point a, Point b, Point c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (res > 0) - (res < 0);
}

ll dist(Point a, Point b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	cin >> c;

	while (c--) {
		int n;
		cin >> n;
		points.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
			points[i].num = i;
		}
		
		swap(points[0], *min_element(points.begin(), points.end(), [](Point a, Point b) {
			return a.y < b.y || (a.y == b.y && a.x < b.x);
		}));
		sort(points.begin() + 1, points.end(), [&](Point a, Point b) {
			ll res = ccw(points[0], a, b);
			if (res) return res > 0;
			return dist(points[0], a) < dist(points[0], b);
		});

		int cnt = n - 1;
		while (cnt > 0 && ccw(points[0], points[cnt], points[cnt - 1]) == 0) {
			cnt-=1;
		}
		reverse(points.begin() + cnt, points.end());
		
		for (int i = 0; i < n; i++) cout << points[i].num << " ";
		cout << "\n";

		points.clear();
	}
}