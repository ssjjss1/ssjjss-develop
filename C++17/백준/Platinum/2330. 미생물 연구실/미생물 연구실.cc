#include <bits/stdc++.h>
#define INF 50004
using namespace std;

int N, tree[INF * 4];
vector<tuple<int, int, int>> v;
vector<int> visited(INF * 2, 0);

void update(int node, int l, int r, int idx) {
    if (idx < l || idx > r) return;
    if (l == r) {
        tree[node] += 1;
        return;
    }
    int middle = (l + r) >> 1;
    update(node * 2, l, middle, idx);
    update(node * 2 + 1, middle + 1, r, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int l, int r, int x, int y) {
    if (y < l || x > r) return 0;
    if (x <= l && r <= y) return tree[node];
    int middle = (l + r) >> 1;
    return query(node * 2, l, middle, x, y) + query(node * 2 + 1, middle + 1, r, x, y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        v.emplace_back(e, s, c);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i <= INF * 2; i++) visited[i] = i;

    for (auto i : v) {
        int e = get<0>(i), s = get<1>(i), c = get<2>(i);
        int used = query(1, 0, INF * 2, s, e);
        int usage = c - used;

        while (usage > 0) {
            int idx = e;
            while (idx >= s && visited[idx] == -1) idx-=1;
            if (idx < s) break;

            update(1, 0, INF * 2, idx);
            visited[idx] = -1;
            usage-=1;
        }
    }

    cout << tree[1];
}