#include <bits/stdc++.h>
#define INF 75004
using namespace std;
int t;
int seg[INF * 4];

void update(int node, int l, int r, int x){
    if (x < l || r < x) return;
    if (l == r){
        seg[node] += 1;
        return;
    }

    int middle = (l + r) / 2;
    update(node * 2, l, middle, x);
    update(node * 2 + 1, middle + 1, r, x);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long long query(int node, int l, int r, int x, int y){
    if (r < x || y < l) return 0;
    if (x <= l && r <= y) return seg[node];

    int middle = (l + r) / 2;
    return query(node * 2, l, middle, x, y) + query(node * 2 + 1, middle + 1, r, x, y);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--){
        int n; cin >> n;

        vector<pair<int, int>> point;
        vector<int> point_y;
        
        memset(seg, 0, sizeof(seg));
        
        for (int i = 1; i <= n; i++){
            int x, y; cin >> x >> y;
            point.push_back({x, y});
            point_y.push_back(y);
        }

        sort(point.begin(), point.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });

        sort(point_y.begin(), point_y.end(), [](int &a, int &b){
            return a > b;
        });

        long long ans = 0;
        for (int i = 0; i < n; i++){
            int y = point[i].second;
            int idx = upper_bound(point_y.begin(), point_y.end(), y, greater<>()) - point_y.begin();
            ans += query(1, 1, n, 0, idx);
            update(1, 1, n, idx);
        }

        cout << ans << "\n";
    }
}