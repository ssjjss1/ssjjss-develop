#include <bits/stdc++.h>
#define INF 2004
using namespace std;

int n, m, idx, scc_cnt;
vector<int> v[INF];
vector<int> d(INF), low(INF), scc(INF);
vector<bool> finished(INF);
stack<int> stk;

void dfs(int x) {
	d[x] = low[x] = ++idx;
	stk.push(x);
	for (auto node : v[x]) {
		if (!d[node]) {
			dfs(node);
			low[x] = min(low[x], low[node]);
		} else if (!finished[node]) {
			low[x] = min(low[x], d[node]);
		}
	}
	if (d[x] == low[x]) {
		while (true) {
			int node = stk.top();
			stk.pop();
			finished[node] = 1;
			scc[node] = scc_cnt;
			if (x == node) break;
		}
		scc_cnt += 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m) {
		idx = scc_cnt = 0;
		fill(d.begin(), d.end(), 0);
		fill(low.begin(), low.end(), 0);
		fill(scc.begin(), scc.end(), 0);
		fill(finished.begin(), finished.end(), false);
		for (int i = 0; i < INF; i++) v[i].clear();
		while (!stk.empty()) stk.pop();
		
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			int nx = (x > 0 ? x * 2 : (-x) * 2 + 1);
			int ny = (y > 0 ? y * 2 : (-y) * 2 + 1);
			int _nx = (nx % 2 ? nx - 1 : nx + 1);
			int _ny = (ny % 2 ? ny - 1 : ny + 1);
			
			v[_nx].push_back(ny);
			v[_ny].push_back(nx);
		}
		v[3].push_back(2);
		
		for (int i = 2; i <= 2 * n + 1; i++) {
			if (!d[i]) dfs(i);
		}
		
		for(int i=2;i<=2*n;i+=2){
		      if(scc[i]==scc[i+1]) {
		            cout<<"no\n";
		            goto next_case;
		      }
		}
		
		cout<<(scc[2]<scc[3]?"yes\n":"no\n");
		next_case:;
	}
}