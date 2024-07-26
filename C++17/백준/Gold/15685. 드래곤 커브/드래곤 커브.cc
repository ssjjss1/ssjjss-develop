#include<iostream>
#include<vector>
using namespace std;
int n;
int a[104][104];
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, -1, 0, 1 };
void f(int x, int y, int d, int g) {
    vector<int> v;
    v.push_back(d);
    for (int i = 0; i < g; i++) {
        int size = v.size();
        for (int j = size - 1; j >= 0; j--) v.push_back((v[j] + 1) % 4);
    }
    a[y][x] = 1;
    for (int d : v) {
        x += dx[d];
        y += dy[d];
        a[y][x] = 1;
    }
}
int g() {
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) cnt += 1;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        f(x, y, d, g);
    }
    cout << g();
}