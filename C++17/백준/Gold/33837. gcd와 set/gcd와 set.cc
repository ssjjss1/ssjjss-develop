#include<bits/stdc++.h>
#define INF 5004
using namespace std;

int n, visited[INF], mx = 0;
vector<int> v;

int gcd(int x, int y) {
	if(y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(!visited[x]) {
			v.push_back(x);
		}
		visited[x] += 1;
	}

	if(n == 1) {
		cout << v[0];
		return 0;
	}
	
	sort(v.begin(), v.end());

	for(int i=0; i<v.size(); i++) {
		int g = 0;
		
		if(visited[v[i]] == n) {
			cout << 2 * v[i];
			return 0;
		}
		
		for(int j=0; j<v.size(); j++) {
			if(v[j] % v[i] && i != j) {
				if(g == 0) g = v[j];
				else g = gcd(v[j], g);

				if(g == 1) break;
			}
		}
		
		mx = max(mx, g + v[i]);
	}

	cout << mx;
}