#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pair = pair<int, int>;

int n;
int parent[3004], t_size[3004];

void Init() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        t_size[i] = 1;
    }
}

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        parent[y] = x;
        t_size[x] += t_size[y];
    }
}

int ccw(Pair p1, Pair p2, Pair p3) {
    ll ans = (1LL * p1.first * p2.second + 1LL * p2.first * p3.second + 1LL * p3.first * p1.second);
    ans -= (1LL * p1.second * p2.first + 1LL * p2.second * p3.first + 1LL * p3.second * p1.first);
    return (ans > 0) - (ans < 0);
}

bool Cross(Pair a, Pair b, Pair c, Pair d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return (ab <= 0 && cd <= 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    vector<pair<Pair, Pair>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first.first >> points[i].first.second 
            >> points[i].second.first >> points[i].second.second;
    }

    Init();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Cross(points[i].first, points[i].second, points[j].first, points[j].second)) {
                Union(i, j);
            }
        }
    }

    unordered_map<int, int> Size;
    int mx = 0, total = 0;

    for (int i = 0; i < n; i++) {
        int P = Find(i);
        if (Size[P] == 0) total += 1;
        Size[P] += 1;
        mx = max(mx, Size[P]);
    }

    cout << total << '\n' << mx;
}