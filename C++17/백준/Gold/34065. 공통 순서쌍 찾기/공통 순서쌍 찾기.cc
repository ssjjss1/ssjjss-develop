#include <bits/stdc++.h>
using namespace std;

const int INF = 200004;
int tree[4 * INF];
map<int, vector<int>> temp; // pb 기준 정렬된 쌍 저장

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(2 * node, l, mid, idx, val);
    else update(2 * node + 1, mid + 1, r, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int l, int r, int x, int y) {
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return tree[node];
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, x, y) +
           query(2 * node + 1, mid + 1, r, x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> A(n + 1), B(n + 1), posA(n + 1), posB(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        posA[A[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        posB[B[i]] = i;
    }

    vector<tuple<int, int, int>> v;
    for (int i = 1; i <= n; i++) {
        v.emplace_back(posA[i], posB[i], i);
    }

    sort(v.begin(), v.end()); 

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        auto [pa, pb, x] = v[i];

        int cnt = query(1, 1, n, 1, pb - 1);

        if (cnt > 0) {
            for (auto it = temp.begin(); it != temp.end() && it->first < pb; it++) {
                for (auto y : it->second) {
                    ans.emplace_back(y, x);
                    if (ans.size() >= k) break;
                }
                if (ans.size() >= k) break;
            }
        }

        temp[pb].push_back(x);
        update(1, 1, n, pb, 1);
        if (ans.size() >= k) break;
    }

    if ((int)ans.size() >= k) {
        cout << "Yes\n";
        for (int i = 0; i < k; i++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    } else {
        cout << "No\n";
    }
}