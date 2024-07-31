#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18 + 4;
int n, m, q;
vector<pair<int, int>> v;
pair<ll, ll> v1[504][504]; // 1) 이동시간, 2) i,j사이의 개의 방해를 받는 최대 시간
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    vector<int> d(n + 4);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        v.push_back({d[i], i});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v1[i][j] = {inf, max(d[i], d[j])};
        }
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        v1[x][y] = {z, max(d[x], d[y])};
        v1[y][x] = {z, max(d[x], d[y])};
    }
    sort(v.begin(), v.end());
    for (auto k : v) {
        int xx = k.second;
        ll yy = k.first; // xx: 경유지, yy: 경유지에서의 방해받는 시간
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll mx = max({v1[i][j].second, v1[i][xx].second, v1[xx][j].second, yy});
                if (v1[i][j].first + v1[i][j].second> v1[i][xx].first + v1[xx][j].first + mx) {
                    v1[i][j].first = v1[i][xx].first + v1[xx][j].first;
                    v1[i][j].second = mx;
                }
            }
        }
    }
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        if (v1[x][y].first != inf) cout << v1[x][y].first + v1[x][y].second << "\n";
        else cout << -1 << "\n";
    }
}