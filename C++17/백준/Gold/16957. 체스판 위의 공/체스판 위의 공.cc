#include<bits/stdc++.h>
using namespace std;
int r, c;
int d[504][504], ans[504][504], parent[300004];
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1}, dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
pair<int,int> points[300004];

void Init() {
    for (int i = 0; i < 300004; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> d[i][j];
            points[d[i][j]]={i,j};
        }
    }

    Init();  

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int xx = -1, yy = -1, mn = 1e9;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x > 0 && y > 0 && x <= r && y <= c) {
                    if (d[x][y] < d[i][j] && d[x][y] < mn) { 
                        mn = d[x][y];
                        xx = x;
                        yy = y;
                    }
                }
            }
            if (xx != -1 && yy != -1) unionSet(d[xx][yy], d[i][j]);
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int root = find(d[i][j]);
            ans[points[root].first][points[root].second] += 1; 
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}