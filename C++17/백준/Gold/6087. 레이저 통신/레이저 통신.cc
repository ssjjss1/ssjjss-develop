#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m;
char c[104][104];
int visited[104][104][4];
vector<pair<int,int>> p;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>m>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>c[i][j];
      if(c[i][j]=='C') p.push_back({i,j});
    }
  }
  queue<pair<pair<int,int>,pair<int,int>>> q;
  for(int i=0;i<4;i++){
    int x=p[0].first+dx[i],y=p[0].second+dy[i];
    if(x<1||y<1||x>n||y>m||c[x][y]=='*') continue;
    q.push({{x,y},{i,0}});
    visited[x][y][i]=0;
  }
  int ans=-1;
  while(!q.empty()){
    int x=q.front().first.first, y=q.front().first.second,dir=q.front().second.first, r=q.front().second.second;
    q.pop();
    if(x==p[1].first&&y==p[1].second){
      if(ans==-1||ans>r) ans=r;
      continue;
    }
    for(int i=0;i<4;i++){
      int xx=x+dx[i],yy=y+dy[i];
      if(xx<1||yy<1||xx>n||yy>m||c[xx][yy]=='*') continue;
      int nr=r+(dir!=i?1:0);
      if(visited[xx][yy][i]==0||visited[xx][yy][i]>nr){
        visited[xx][yy][i]=nr;
        q.push({{xx,yy},{i,nr}});
      }
    }
  }
  cout<<ans;
}