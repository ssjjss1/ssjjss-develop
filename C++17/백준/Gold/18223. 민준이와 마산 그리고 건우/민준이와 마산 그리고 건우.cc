#include<bits/stdc++.h>
#define INF 1e9+7
using namespace std;

vector<pair<int,int>> pair_d[5004];
int v, e, p;

int search(int U, int V) {
    vector<int> dist(v + 4, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[U] = 0;
    pq.push({0, U});
    while (!pq.empty()) {
        int cnt = pq.top().first, cx = pq.top().second;
        pq.pop();
        if (cnt > dist[cx]) continue;
        for (auto i : pair_d[cx]) {
            int nx = i.first, next_cnt = i.second;
            if (dist[nx] > dist[cx] + next_cnt) {
                dist[nx] = dist[cx] + next_cnt;
                pq.push({dist[nx], nx});
            }
        }
    }
    return dist[V];
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> v >> e >> p;
    for (int i = 1; i <= e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pair_d[a].push_back({b, c});
        pair_d[b].push_back({a, c});
    }
    int ans1 = search(1, p);
    int ans2 = search(p, v);
    int ans3 = search(1, v);
    if (ans1 + ans2 == ans3) cout << "SAVE HIM";
    else cout << "GOOD BYE";
}