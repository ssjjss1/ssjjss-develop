#include <bits/stdc++.h>
using namespace std;

int n;
int visited[2048], fin[2048];

void run(vector<vector<int>> &d) {
    int t = n;
    while (t > 1) {
        memcpy(visited, fin, sizeof(fin));

        for (int i = 2; i <= n; i++) {
            if (!visited[i] && !d[1][i]) {
                int idx = 0;
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && d[1][j] && d[j][i]) {
                        idx = j;
                        break;
                    }
                }
                if (idx) {
                    visited[i] = visited[idx] = fin[i] = 1;
                    cout << i << " " << idx << '\n';
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && d[1][i]) {
                visited[1] = visited[i] = fin[i] = 1;
                cout << 1 << " " << i << '\n';
                break;
            }
        }

        int k = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && !d[1][i]) {
                if (!k) k = i;
                else {
                    cout << k << " " << i << '\n';
                    visited[k] = visited[i] = 1;
                    if (d[k][i]) fin[i] = 1;
                    else fin[k] = 1;
                    k = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (!k) k = i;
                else {
                    cout << k << " " << i << '\n';
                    visited[k] = visited[i] = 1;
                    if (d[k][i]) fin[i] = 1;
                    else fin[k] = 1;
                    k = 0;
                }
            }
        }

        t /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        memset(fin, 0, sizeof(fin));
        memset(visited, 0, sizeof(visited));

        vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char c;
                cin >> c;
                d[i][j] = (c == '1');
            }
        }

        run(d);
    }
}