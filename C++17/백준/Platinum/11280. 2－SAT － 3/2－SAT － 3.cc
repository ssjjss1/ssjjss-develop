#include<bits/stdc++.h>
#define INF 20004
using namespace std;

int n, m, idx, scc_cnt;
vector<int> v[INF];
vector<int> d(INF), low(INF), scc(INF);
vector<bool> finished(INF);
stack<int> stk;

void tj(int x) {
    d[x] = low[x] = ++idx;
    stk.push(x);
    for (auto i : v[x]) {
        if (!d[i]) {
            tj(i);
            low[x] = min(low[x], low[i]);
        } else if (!finished[i]) {
            low[x] = min(low[x], d[i]);
        }
    }
    if (low[x] == d[x]) {
        while (true) {
            int node = stk.top();
            stk.pop();
            finished[node] = true;
            scc[node] = scc_cnt;
            if (node == x) break;
        }
        scc_cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int nx = (x > 0 ? 2 * x : -2 * x + 1);
        int ny = (y > 0 ? 2 * y : -2 * y + 1);
        int _nx = (nx % 2 ? nx - 1 : nx + 1);
        int _ny = (ny % 2 ? ny - 1 : ny + 1);
        v[_nx].push_back(ny);
        v[_ny].push_back(nx);
    }
    for (int i = 2; i <= 2 * n + 1; i++) {
        if (!d[i]) tj(i);
    }
    for (int i = 1; i <= n; i++) {
        if (scc[2 * i] == scc[2 * i + 1]) {
            cout << "0\n";
            return 0;
        }
    }
    cout << "1";
}