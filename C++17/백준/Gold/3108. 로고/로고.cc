#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int d[1004];
vector<pair<pair<int, int>, pair<int, int>>> v;
bool check_zero(int x1, int y1, int x2, int y2) {
    if (x1 == 0 && y1 * y2 <= 0) return true;
    if (x2 == 0 && y1 * y2 <= 0) return true;
    if (y1 == 0 && x1 * x2 <= 0) return true;
    if (y2 == 0 && x1 * x2 <= 0) return true;
    return false;
}
bool check(int i, int j) {
    int x1 = v[i].first.first, y1 = v[i].first.second;
    int x2 = v[i].second.first, y2 = v[i].second.second;
    int x3 = v[j].first.first, y3 = v[j].first.second;
    int x4 = v[j].second.first, y4 = v[j].second.second;
    if (x2 < x3 || x1 > x4 || y2 < y3 || y1 > y4) return false;
    if ((x1 > x3 && x2 < x4 && y1 > y3 && y2 < y4) || 
        (x1 < x3 && x2 > x4 && y1 < y3 && y2 > y4)) return false;
    return true;
}
int find_parent(int x) {
    if (d[x] == x) return x;
    return d[x] = find_parent(d[x]);
}
void union_sets(int x, int y) {
    x = find_parent(x), y = find_parent(y);
    if (x != y) d[x] = y;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    bool flag = true;
    for (int i = 0; i < n; i++) d[i] = i;
    for (int i = 0, x1, y1, x2, y2; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (check_zero(x1, y1, x2, y2)) flag = false;
        v.push_back({{x1, y1}, {x2, y2}});
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (check(i, j)) {
                if (find_parent(i) != find_parent(j)) {
                    union_sets(i, j);
                }
            }
        }
    }
    int cnt = 0;
    vector<int> found;
    found.push_back(find_parent(0));
    for (int i = 1; i < n; i++) {
        if (find(found.begin(), found.end(), find_parent(i)) == found.end()) {
            cnt += 1;
            found.push_back(find_parent(i));
        }
    }
    cout << cnt + flag;
}