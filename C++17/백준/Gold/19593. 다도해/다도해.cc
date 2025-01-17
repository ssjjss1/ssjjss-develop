#include<bits/stdc++.h>
using namespace std;

int t;
vector<int> parent;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        int n, seed, a, b, cnt = 0;
        cin >> n >> seed >> a >> b;

        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 1; i <= n * n; i++) {
            if (i == 1) seed = seed % (1LL * n * n);
            else seed = (1LL * seed * a + b) % (1LL * n * n);
            int x = seed / n, y = seed % n;
            if (x != y && find(x) != find(y)) {
                union_set(x, y);
                cnt++;
            }
            if (cnt == n - 1) {
                cout << i << "\n";
                break;
            }
        }
        if (cnt < n - 1) cout << 0 << "\n";
    }
}