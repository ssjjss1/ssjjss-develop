#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> domino;
const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int d[14][14];
int ans;
set<pair<int,int>> usedDominoes;

void Init(){
      for(int i=0;i<=6;i++){
            for(int j=i;j<=6;j++){
                  domino.push_back({i,j});
            }
      }
}

void backtracking(int x, int y, int cnt, vector<vector<bool>> &visited){
      if(cnt == 28){
            ans += 1;
            return;
      }

      if(y > 7){
            backtracking(x+1, 1, cnt, visited);
            return;
      }

      if(x > 8) return;

      if(visited[x][y]){
            backtracking(x, y+1, cnt, visited);
            return;
      }

      visited[x][y] = true;
      for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx < 1 || nx > 8 || ny < 1 || ny > 7 || visited[nx][ny]) continue;
            int a = d[x][y], b = d[nx][ny];
            if(a > b) swap(a, b);
            if(usedDominoes.count({a, b})) continue;

            usedDominoes.insert({a, b});
            visited[nx][ny] = true;
            backtracking(x, y+1, cnt+1, visited);
            visited[nx][ny] = false;
            usedDominoes.erase({a, b});
      }
      visited[x][y] = false;
}

int main(){
      ios::sync_with_stdio(0); cin.tie(0);
      for(int i=1;i<=8;i++){
            string s;
            cin>>s;
            for(int j=1;j<=7;j++){
                  d[i][j]=s[j-1]-'0';
            }
      }
      Init();
      vector<vector<bool>> visited(14, vector<bool>(14, 0));
      backtracking(1,1,0, visited);
      cout << ans;
}