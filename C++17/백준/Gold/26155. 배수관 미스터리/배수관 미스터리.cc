#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<tuple<double, int, int>> v;
vector<pair<double, int>> queries;
vector<int> parent, Rank, ans;

void init() {
    parent.resize(n + 1);
    Rank.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (Rank[x] < Rank[y]) swap(x, y);
        parent[y] = x;
        if (Rank[x] == Rank[y]) Rank[x]+=1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    init();

    for (int i = 0; i < m; i++) {
        int a, b; double p;
        cin >> a >> b >> p;
        v.emplace_back(p, a, b);
    }

    cin >> q;
    queries.resize(q);
    ans.resize(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(v.rbegin(), v.rend());
    sort(queries.rbegin(), queries.rend());

    int cnt = n, idx = 0;

    for (auto [x, i] : queries) {
        while (idx < m && get<0>(v[idx]) >= x) {
            int a = get<1>(v[idx]);
            int b = get<2>(v[idx]);
            if (find(a) != find(b)) {
                unite(a, b);
                cnt-=1;
            }
            idx+=1;
        }
        ans[i] = cnt;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}