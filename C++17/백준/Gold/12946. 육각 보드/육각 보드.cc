#include<iostream>
using namespace std;
int n,p;
const int inf=-1e9;
const int dx[]={-1,-1,0,0,1,1},dy[]={0,1,-1,1,-1,0};
int visited[54][54];
char c[54][54];
void f(int a, int b, int cnt){
  visited[a][b]=cnt;
  p=max(p,1);
  for(int i=0;i<6;i++){
    int x=a+dx[i],y=b+dy[i];
    if (x < 1 || x > n || y < 1 || y > n) continue;
    if(c[x][y]=='X'&&visited[x][y]==inf){
      f(x,y,1-cnt);
      p=max(p,2);
    }
    else if(c[x][y]=='X'&&visited[x][y]==cnt){
      cout<<3;
      exit(0);
    }
  }
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>c[i][j];
    }
  }
  fill(&visited[0][0],&visited[0][0]+54*54,inf);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(visited[i][j]==inf&&c[i][j]=='X') f(i,j,0);
    }
  }
  cout<<p;
}