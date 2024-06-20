#include<iostream>
#include<queue>
using namespace std;
int n,m;
int visited[310][310];
int a[310][310];
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
struct P{
  int _x,_y,_z;
};
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  queue<P> q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
      if(a[i][j]) q.push({i,j,0});
    }
  }
  for(int h=1;h<=100000;h++){
    int size=q.size();
    //size만큼 배열 탐색
    for(int j=1;j<=size;j++){
      int x=q.front()._x,y=q.front()._y,cnt=q.front()._z;
      q.pop();
      for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(a[xx][yy]||xx<1||yy<1||xx>n||yy>m)continue;
        cnt--;
      }
      q.push({x,y,cnt});
    }
    //모든 빙하의 높이 업데이트
    for(int i=1;i<=size;i++){
      int x=q.front()._x,y=q.front()._y,cnt=q.front()._z;
      q.pop();
      if(a[x][y]+cnt>0) q.push({x,y,0}),a[x][y]+=cnt;
      else a[x][y]=0;
    }
    fill(&visited[0][0],&visited[0][0]+304*304,0);
    // 빙하의 개수 확인
    bool flag=true;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(!visited[i][j]&&a[i][j]){
          if(flag){
            flag=false;
            queue<pair<int,int>> _q;
            _q.push({i,j});
            visited[i][j]=1;
            while(!_q.empty()){
              int x=_q.front().first,y=_q.front().second;
              _q.pop();
              for(int k=0;k<4;k++){
                int xx=x+dx[k],yy=y+dy[k];
                if(!a[xx][yy]||xx<1||yy<1||xx>n||yy>m||visited[xx][yy]) continue;
                visited[xx][yy]=1;
                _q.push({xx,yy});
              }
            }
          }
          else{
            cout<<h;
            return 0;
          }
        }
      }
    }
    if(flag){
      cout<<0;
      return 0;
    }
  }
}