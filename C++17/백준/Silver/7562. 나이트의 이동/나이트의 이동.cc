#include <bits/stdc++.h>
using namespace std;
int l, n, m, A, B;
const int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 },dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int visited[301][301];
int f(){
    queue<pair<int, int>> q;
    visited[n][m] = 1;
    q.push({ n, m });
    while (!q.empty()){
        int x = q.front().first,y = q.front().second;
        q.pop();
        if (x == A && y == B) return visited[x][y] - 1;
        for (int i = 0; i < 8; i++){
            int xx = x + dx[i],yy = y + dy[i];
            if (0 > xx || l <= xx||0 > yy || l <= yy||visited[xx][yy]) continue;
            visited[xx][yy] = visited[x][y] + 1;
            q.push({ xx, yy });
        }
    }
  return -1;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> l >> n >> m >> A >> B;
        fill(&visited[0][0], &visited[300][301], 0);
        cout << f() << "\n";
    }
}