#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int d[100004];
struct P {
    int a, b, c, d;
};
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {return a.second < b.second;}
bool com1(P x, P y) { return x.b < y.b; }
bool com2(P x, P y) { return x.c < y.c; }
bool com3(P x, P y) { return x.d < y.d; }
vector<P> v;
vector<pair<pair<int, int>, int>> v1;
int f(int x) {
    if (d[x] == x) return x;
    return d[x] = f(d[x]);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) d[i] = i;
    for (int i = 1, x, y, z; i <= n; i++) {
        cin >> x >> y >> z;
        v.push_back({i, x, y, z});
    }
    sort(v.begin(), v.end(), com1);
    for (int i = 0; i < v.size() - 1; i++) v1.push_back({{v[i].a, v[i + 1].a}, abs(v[i].b - v[i + 1].b)});
    sort(v.begin(), v.end(), com2);
    for (int i = 0; i < v.size() - 1; i++)  v1.push_back({{v[i].a, v[i + 1].a}, abs(v[i].c - v[i + 1].c)});
    sort(v.begin(), v.end(), com3);
    for (int i = 0; i < v.size() - 1; i++) v1.push_back({{v[i].a, v[i + 1].a}, abs(v[i].d - v[i + 1].d)});
    sort(v1.begin(), v1.end(), compare);
    long long ans = 0;
    int cnt = 0;
    for (auto i : v1) {
        int x = i.first.first, y = i.first.second, w = i.second;
        int X = f(x), Y = f(y);
        if (X != Y) {
            d[X] = Y;
            ans += w;
            cnt += 1;
        }
        if (cnt == n - 1) break;
    }
    cout << ans;
}