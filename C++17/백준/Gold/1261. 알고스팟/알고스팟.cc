#include<iostream>
#include<queue>
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
const int inf=987654321;
int n,m;
int a[104][104],d[104][104];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>m>>n;
  fill(&d[0][0],&d[0][0]+104*104,inf);
  for(int i=1;i<=n;i++){
    string s;
    cin>>s;
    for(int j=0;j<m;j++){
      a[i][j+1]=s[j]-'0';
    }
  }
  queue<pair<int,int>> q;
  q.push({1,1});
  d[1][1]=0;
  while(!q.empty()){
    int x=q.front().first, y=q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int xx=x+dx[i],yy=y+dy[i];
      if(xx<1||xx>n||yy<1||yy>m) continue;
      if(a[xx][yy]){
        if(d[xx][yy]>d[x][y]+1){
          d[xx][yy]=d[x][y]+1;
          q.push({xx,yy});
        }
      }
      else if(!a[xx][yy]){
        if(d[xx][yy]>d[x][y]){
          d[xx][yy]=d[x][y];
          q.push({xx,yy});
        }
      }
    }
  }
  cout<<d[n][m];
}