#include <bits/stdc++.h>
#define INF 1e9+7
using namespace std;
vector<vector<int>> v(14, vector<int>(14, 0)), temp_v(14, vector<int>(14, 0));
int ans = INF;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
void turn_off(int x, int y) {
    temp_v[x][y] = !temp_v[x][y];
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < 10 && yy < 10) {
            temp_v[xx][yy] = !temp_v[xx][yy]; 
        }
    }
}
bool check() {
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) if (temp_v[i][j] == 1) return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;
            if (c == 'O') v[i][j] = 1;
            else v[i][j] = 0;
        }
    }
    for (int i = 0; i < (1 << 10); i++) {
        int cnt = 0;
        temp_v = v;
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                cnt+=1;
                turn_off(0, j);
            }
        }
        for (int x = 1; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (temp_v[x - 1][y]) { 
                    cnt+=1;
                    turn_off(x, y);
                }
            }
        }
        if (check()) ans = min(cnt, ans);
    }
    if (ans == INF) cout << -1;
    else cout << ans;
}