#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll inf=1e18+4;
int n, m;
ll visited[100004];
vector<pair<int, int>> v[100004];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }
    fill(visited, visited + 100004, inf);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 1});
    visited[1] = 0;
    while (!q.empty()) {
        ll x = q.top().second, y = q.top().first;
        q.pop();
        if (x == n) continue;
        if (visited[x] < y) continue;
        for (auto i : v[x]) {
            int k = y % m;
            ll d;
            if (k <= i.second) d = (y / m) * m + i.second + 1;
            else d = (y / m) * m + i.second + m + 1;
            if (d < visited[i.first]) {
                visited[i.first] = d;
                q.push({d, i.first});
            }
        }
    }
    cout << visited[n];
}