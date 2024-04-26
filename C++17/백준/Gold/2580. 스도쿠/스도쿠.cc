#include<iostream>
#include<vector>
using namespace std;
int a[10][10];
vector<pair<int, int>> v;
bool f(int x, int y, int k) {
    for (int i = 0; i < 9; i++) {
        if (a[x][i] == k || a[i][y] == k) return 0;
    }
    int p1 = x / 3;
    int p2 = y / 3;
    for (int i = p1 * 3; i < p1 * 3 + 3; i++) {
        for (int j = p2 * 3; j < p2 * 3 + 3; j++) {
            if (a[i][j] == k) return 0;
        }
    }
    return 1;
}
void g(int level) {
    if (level==v.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j]<<" ";
            }
            cout << "\n";
        }
        exit(0);
    }
    int x = v[level].first;
    int y = v[level].second;
    for (int i = 1; i <= 9; i++) {
        if (f(x, y, i)) {
            a[x][y] = i;
            g(level + 1);
            a[x][y] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0)  v.push_back({ i,j });
        }
    }
    g(0);
}