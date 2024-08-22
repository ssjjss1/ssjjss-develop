#include<iostream>
#include<queue>
using namespace std;
int n, m;
int mx, cnt;
int d[54][54];
int visited[54][54];
const int dx[] = { 0, -1, 0, 1 }, dy[] = { -1, 0, 1, 0 };
int f(int x, int y, int p) {
    visited[x][y] = p;
    queue<pair<int, int>> q;
    q.push({ x, y });
    int ans = 1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m || visited[xx][yy]) continue;
            if (d[x][y] & (1 << i)) continue;
            visited[xx][yy] = p;
            q.push({ xx, yy });
            ans += 1;
        }
    }
    mx = max(mx, ans);
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> d[i][j];
        }
    }
    vector<int> v;
   int p=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j]) {
                p+=1;
                cnt += 1;
                v.push_back(f(i, j, p));
            }
        }
    }
    int mx2 = mx; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int xx=i+dx[k],yy=j+dy[k];
                if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
                if(visited[xx][yy]!=visited[i][j]) mx2=max(mx2,v[visited[xx][yy]-1]+v[visited[i][j]-1]);
            }
        }
    }
    cout << cnt << "\n" << mx << "\n" << mx2;
}