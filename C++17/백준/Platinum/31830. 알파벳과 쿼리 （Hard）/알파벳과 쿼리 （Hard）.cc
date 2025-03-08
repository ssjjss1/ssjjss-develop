#include <bits/stdc++.h>
#define INF 200004
using namespace std;

int n, q, qr, ql, ans;
string s;
int d[INF], L[INF * 4], R[INF * 4], cnt[INF * 4], lazy[INF * 4];

void propagation(int node, int l, int r) {
    if (lazy[node]) {
        L[node] = (L[node] + lazy[node]) % 26;
        R[node] = (R[node] + lazy[node]) % 26;
        if (l != r) {
            lazy[node * 2] = (lazy[node * 2] + lazy[node]) % 26;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % 26;
        }
        lazy[node] = 0;
    }
}

void Init(int node, int l, int r) {
    if (l == r) {
        L[node] = R[node] = d[l];
        cnt[node] = 1;
        return;
    }
    int middle = (l + r) / 2;
    Init(node * 2, l, middle);
    Init(node * 2 + 1, middle + 1, r);
    L[node] = L[node * 2];
    R[node] = R[node * 2 + 1];
    cnt[node] = cnt[node * 2] + cnt[node * 2 + 1] - (R[node * 2] == L[node * 2 + 1]);
}

void update(int node, int l, int r, int x, int y) {
    propagation(node, l, r);
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        lazy[node] = (lazy[node] + 1) % 26;
        propagation(node, l, r);
        return;
    }
    int middle = (l + r) / 2;
    update(node * 2, l, middle, x, y);
    update(node * 2 + 1, middle + 1, r, x, y);
    L[node] = L[node * 2];
    R[node] = R[node * 2 + 1];
    cnt[node] = cnt[node * 2] + cnt[node * 2 + 1] - (R[node * 2] == L[node * 2 + 1]);
}

void query(int node, int l, int r, int x, int y) {
    propagation(node, l, r);
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        if (ql == -1) {
            ql = L[node];
            qr = R[node];
            ans = cnt[node];
        } else {
            ans += cnt[node] - (qr == L[node]);
            qr = R[node];
        }
        return;
    }
    int middle = (l + r) / 2;
    query(node * 2, l, middle, x, y);
    query(node * 2 + 1, middle + 1, r, x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> s;
    for (int i = 0; i < n; i++) {
        d[i + 1] = s[i] - 'A';
    }
    Init(1, 1, n);
    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1) {
            qr = ql = ans = -1;
            query(1, 1, n, l, r);
            cout << ans << "\n";
        } else {
            update(1, 1, n, l, r);
        }
    }
}