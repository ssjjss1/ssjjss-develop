#include<iostream>
#include<vector>
#include<queue>
using namespace std;
char a[1501][1501];
int visited[1501][1501];
int n, m;
queue<pair<int,int>> q1,q2;
const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
vector<pair<int, int>> v;
void f() {
  int size=q1.size();
  while(size--){
    int x=q1.front().first,y=q1.front().second;
    q1.pop();
    for(int i=0;i<4;i++){
      int xx=x+dx[i],yy=y+dy[i];
      if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]!='X') continue;
      q1.push({xx,yy});
      a[xx][yy]='.';
    }
  }
}
bool g() {
  queue<pair<int, int>> q;
  while (!q2.empty()) {
    int x = q2.front().first, y = q2.front().second;
    q2.pop();
    if (x == v[1].first && y == v[1].second) return 1;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx<1 || yy<1 || xx>n || yy>m || visited[xx][yy]) continue;
      visited[xx][yy] = 1;
      if(a[xx][yy]=='X') q.push({xx,yy});
      else q2.push({xx,yy});
    }
  }
  q2=q;
  return 0;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char x;
      cin>>x;
      a[i][j]=x;
      if (x == 'L') {
        q1.push({i,j});
        v.push_back({i,j});
      }
      else if(x=='.') q1.push({i,j});
    }
  }
  int cnt = 0;
  q2.push({v[0].first,v[0].second});
  while(true) {
    if (g()) {
      cout << cnt;
      return 0;
    }
    f();
    cnt += 1;
  }
}