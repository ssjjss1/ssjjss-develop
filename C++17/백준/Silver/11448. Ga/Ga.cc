#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int dx[]={1,0,-1,0,1,1,-1,-1}, dy[]={0,1,0,-1,1,-1,1,-1};
int t,n;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<vector<int>> v(2*n, vector<int>(2*n, 0)), visited(2*n, vector<int>(2*n, 0));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < n; j++) {
                if(s[j] == 'w') v[i][j] = 1, q.push({i, j}), visited[i][j] = 1;
                if(s[j] == 'b') v[i][j] = 2;
            }
        }
        int ans = 0;
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 8; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if(xx < 0 || yy < 0 || xx >= n || yy >= n || v[xx][yy] == 1 || v[xx][yy] == 2 || visited[xx][yy]) continue;
                ans += 1;
                q.push({xx, yy});
                visited[xx][yy] = 1;
            }
        }
        cout << ans << "\n";
    }
}
