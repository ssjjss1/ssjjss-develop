#include <iostream>
using namespace std;
int n, m;
int x, y, z;
int d[104][104];
const int inf = 987654321;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fill(&d[0][0], &d[0][0] + 104 * 104, inf);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        x--, y--;
        d[x][y] = d[x][y] ? min(d[x][y], z) : z;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << 0 << " ";
            else
                cout << (d[i][j] == inf ? 0 : d[i][j]) << " ";
        }
        cout << "\n";
    }
}