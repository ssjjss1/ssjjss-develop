#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int n;
ld m, ans = 1e18;
vector<bool> visited;
vector<tuple<ld, ld, ld, ld>> v; 
vector<ld> mt;

pair<ld, ld> posP(int i, ld t) {
    auto [x, y, vi, ai] = v[i];
    ld vx = vi * cos(ai);
    ld vy = vi * sin(ai);
    return {x + vx * t, y + vy * t};
}

ld findXY(ld gx, ld gy, ld ct, int i) {
    ld l = 0, r = 1e9;
    while (r - l > 1e-6) { 
        ld middle = (l + r) / 2.0;
        auto [px, py] = posP(i, ct + middle);
        ld dist = hypot(px - gx, py - gy);
        if (dist <= m * middle) r = middle;
        else l = middle;
    }
    return r;
}

void backTracking(int cnt, ld t, ld prevX, ld prevY) {
    if (cnt == n) {
        ld res = 0;
        for (int i = 0; i < n; i++) {
            auto [x, y] = posP(i, mt[i]);
            auto [_, __, vi, ___] = v[i];
            res = max(res, mt[i] + hypot(x, y) / vi);
        }
        ans = min(ans, res);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        ld dt = findXY(prevX, prevY, t, i);
        auto [mx, my] = posP(i, t + dt);
        mt[i] = t + dt;
        backTracking(cnt + 1, t + dt, mx, my);
        visited[i] = false;
        mt[i] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    v.resize(n);
    visited.assign(n, false);
    mt.assign(n, -1);

    for (int i = 0; i < n; i++) {
        ld x, y, vi, ai;
        cin >> x >> y >> vi >> ai;
        v[i] = make_tuple(x, y, vi, ai);
    }

    backTracking(0, 0, 0.0, 0.0);
    cout << (int)llround(ans);
}