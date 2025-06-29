#include <bits/stdc++.h>
using namespace std;

int n, m, k, q;
int d[304][10004], cnt[304];
pair<int, int> best[10004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;

            d[i][x] += y;
            if (d[i][x] > best[x].second) {
                if (best[x].first != 0) {
                    cnt[best[x].first]-=1;
                }
                cnt[i]+=1;
                best[x] = {i, d[i][x]};
            }
        }
    }

    set<int> ans;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == k) ans.insert(i);
    }

    cin >> q;
    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;

        d[u][v] += w;
        if (d[u][v] > best[v].second) {
            if (best[v].first != 0) {
                cnt[best[v].first]-=1;
                if (cnt[best[v].first] < k) {
                    ans.erase(best[v].first);
                }
            }

            cnt[u]+=1;
            best[v] = {u, d[u][v]};
            if (cnt[u] == k) ans.insert(u);
        }

        cout << ans.size() << "\n";
    }
}