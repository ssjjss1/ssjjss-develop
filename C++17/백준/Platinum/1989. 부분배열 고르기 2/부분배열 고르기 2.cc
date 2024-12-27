#include<bits/stdc++.h>
#define INF 100004
using namespace std;

int n;
long long d[INF], tree_mn[INF * 4], tree_sum[INF * 4], idx_mn[INF * 4];

void update(int node, int l, int r) {
    if (l == r) {
        tree_mn[node] = d[l];
        tree_sum[node] = d[l];
        idx_mn[node] = l;
        return;
    }
    int middle = (l + r) / 2;
    update(node * 2, l, middle);
    update(node * 2 + 1, middle + 1, r);
    if (tree_mn[node * 2] < tree_mn[node * 2 + 1]) {
        tree_mn[node] = tree_mn[node * 2];
        idx_mn[node] = idx_mn[node * 2];
    } else {
        tree_mn[node] = tree_mn[node * 2 + 1];
        idx_mn[node] = idx_mn[node * 2 + 1];
    }
    tree_sum[node] = tree_sum[node * 2] + tree_sum[node * 2 + 1];
}

tuple<long long, int, long long> query(int node, int l, int r, int x, int y) {
    if (y < l || r < x) return {LLONG_MAX, -1, 0}; 
    if (x <= l && r <= y) return {tree_mn[node], idx_mn[node], tree_sum[node]};
    int middle = (l + r) / 2;
    auto [mn1, idx1, sum1] = query(node * 2, l, middle, x, y);
    auto [mn2, idx2, sum2] = query(node * 2 + 1, middle + 1, r, x, y);

    if (mn1 < mn2) return {mn1, idx1, sum1 + sum2};
    else return {mn2, idx2, sum1 + sum2};
}

pair<long long, pair<int, int>> solve(int l, int r) {
    if (l > r) return {-1, {0, 0}};
    auto [mn_val, min_idx, total_sum] = query(1, 1, n, l, r);
    long long total_score = mn_val * total_sum;

    auto left = solve(l, min_idx - 1);
    auto right = solve(min_idx + 1, r);

    if (left.first > total_score) {
        total_score = left.first;
        l = left.second.first;
        r = left.second.second;
    }
    if (right.first > total_score) {
        total_score = right.first;
        l = right.second.first;
        r = right.second.second;
    }

    return {total_score, {l, r}};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    update(1, 1, n);
    auto ans = solve(1, n);
    cout << ans.first << "\n" << ans.second.first << " " << ans.second.second;
}