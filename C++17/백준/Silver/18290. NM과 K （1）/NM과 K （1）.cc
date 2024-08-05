#include <iostream>
#include<vector>
using namespace std;
int n, m, k;
int d[14][14];
int mx=-1e9;
vector<pair<int, int>> v;
bool g(int x1, int y1, int x2, int y2) {return (x1 == x2 && abs(y1 - y2) == 1) || (y1 == y2 && abs(x1 - x2) == 1);}
void f(int x, int y, int sum, int cnt) {
    if (cnt == k) {
        mx = max(mx, sum);
        return;
    }
    for (int i = x; i < n; i++) {
        for (int j = (i == x ? y : 0); j < m; j++) {
            bool flag = true;
            for (auto p : v) {
                if (g(p.first, p.second, i, j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                v.push_back({ i, j });
                f(i, j + 1, sum + d[i][j], cnt + 1);
                v.pop_back();
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }
    f(0, 0, 0, 0);
    cout << mx;
}