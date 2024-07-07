#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Edge {
    int v;
    long long w;
    Edge(int v, long long w) : v(v), w(w) {}
};
int N;
vector<Edge> *list;
bool bfs(long long mask) {
    queue<int> q;
    q.push(1);
    bool visit[N + 1];
    memset(visit, false, sizeof(visit));
    visit[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (Edge E : list[cur]) {
            if (!visit[E.v] && (E.w | mask) == mask) {
                visit[E.v] = true;
                q.push(E.v);
            }
        }
    }
    return visit[N];
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int M;
    cin >> N >> M;
    list = new vector<Edge>[N + 1];
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        list[u].emplace_back(v, w);
        list[v].emplace_back(u, w);
    }
    long long mask = (1LL << 60) - 1;
    for (int k = 59; k >= 0; --k) {
        if (bfs(mask ^ (1LL << k)))
            mask ^= (1LL << k);
    }
    cout << mask;
}