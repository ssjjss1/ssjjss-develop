#include <bits/stdc++.h>
typedef long double ld;
#define Edge tuple<int, int, ld, ld>
using namespace std;

int n, m;
ld f;
vector<Edge> adj;
vector<int> parent;

void Init() {
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

bool check(ld g) {
    sort(adj.begin(), adj.end(), [g](Edge a, Edge b) {
        return get<2>(a) + get<3>(a) * g < get<2>(b) + get<3>(b) * g;
    });

    Init();

    ld totalVal = 0, totalTime = 0;
    int cnt = 0;

    for (auto [u, v, c, t] : adj) {
        if (find(u) != find(v)) {
            Union(u, v);
            totalVal += c;
            totalTime += t;
            cnt+=1;
        }
        if (cnt == n - 1) break;
    }

    return (totalVal + g * totalTime) <= f;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> f;

    for (int i = 0; i < m; i++) {
        int u, v;
        ld c, t;
        cin >> u >> v >> c >> t;
        adj.push_back({u, v, c, t});
    }

    ld l = 0, r = 1e7;
    while ((r - l) >= 0.000001) {
        ld middle = (l + r) / 2.0;
        if (check(middle)) l = middle;
        else r = middle;
    }

    cout << fixed << setprecision(4) << max((ld)0.0, l);
}