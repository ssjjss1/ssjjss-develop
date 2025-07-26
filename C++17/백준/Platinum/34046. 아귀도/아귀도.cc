#include <bits/stdc++.h>
#define INF 200004
using namespace std;

constexpr long long MOD = 1e9 + 7;

vector<int> adj[INF], ze, start[INF], finish[INF], a(INF), in(INF), out(INF), prevCx(INF);
vector<bool> visited(INF);
multiset<int, greater<int>> idxPri;
unordered_map<int, int> cntIdx;
int idx;

void dfs(int cx, int prev) {
    in[cx] = ++idx;
    prevCx[idx] = cx;
    for (auto nx : adj[cx]) {
        if (nx != prev) dfs(nx, cx);
    }
    out[cx] = idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) ze.push_back(i);
        else visited[a[i]] = 1;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            int x = a[i];
            start[in[x]].push_back(i);
            finish[out[x]].push_back(i);
        }
    }

    vector<int> ch(INF, 0);
    for (int i = 1; i <= n; i++) {
        for (auto x : start[i]) {
            idxPri.insert(x);
            cntIdx[x]+=1;
        }
        for (auto x : finish[i - 1]) {
            cntIdx[x]-=1;
            if (cntIdx[x] == 0) {
                cntIdx.erase(x);
                idxPri.erase(idxPri.find(x));
            }
        }
        if (!idxPri.empty()) ch[prevCx[i]] = *idxPri.begin();
    }

    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int idx = upper_bound(ze.begin(), ze.end(), ch[i]) - ze.begin();
            if (idx == ze.size()) {
                cout << 0;
                return 0;
            }
            pos.push_back(idx);
        }
    }

    sort(pos.rbegin(), pos.rend());
    long long ans = 1;
    int sz = pos.size();
    for (long long i = 0; i < sz; i++) {
        long long cnt = sz - pos[i] - i;
        if (cnt <= 0) {
            cout << 0;
            return 0;
        }
        ans = ans * cnt;
        ans %= MOD;
    }

    cout << ans;
}