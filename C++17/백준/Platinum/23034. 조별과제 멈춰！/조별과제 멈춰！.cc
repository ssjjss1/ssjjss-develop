#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n, m, t, sum;
ll p[100004], d[1004][1004];
vector<pair<int, int>> v1[100004];
struct edge {
    int u, v, c;
    bool operator<(const edge& a) { return c < a.c; }
} a[100004];
ll f(ll x) {
    if (x == p[x]) return x;
    return p[x] = f(p[x]);
}
void g(ll b) {
    queue<int> q;
    bool visited[100004];
    fill(visited, visited + 100003, 0);
    visited[b] = 1;
    q.push(b);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : v1[x]) {
            ll xx = i.first, yy = i.second;
            if (!visited[xx]) {
                d[b][xx] = max(max(d[b][x], yy), d[b][xx]);
                visited[xx] = 1;
                q.push(xx);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(d, 0, sizeof(d));
    for (int i = 0; i < 1004; i++) p[i] = i;
    for (int i = 0; i < m; i++) cin >> a[i].u >> a[i].v >> a[i].c;
    sort(a, a + m);
    for (int i = 0; i < m; i++) {
        ll u = a[i].u, v = a[i].v, c = a[i].c;
        ll x = f(u), y = f(v);
        if (x != y) {
            sum += c;
            p[x] = y;
            v1[u].push_back({v, c});
            v1[v].push_back({u, c});
        }
    }
    for (int i = 1; i <= n; i++) g(i);
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        cout << sum - d[x][y] << '\n';
    }
}