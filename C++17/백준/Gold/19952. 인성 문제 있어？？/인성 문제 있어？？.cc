#include<bits/stdc++.h>
using namespace std;
int w,h,o,f,xs,ys,xe,ye;

const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      int t;
      cin>>t;
      while(t--){
            cin>>h>>w>>o>>f>>xs>>ys>>xe>>ye;
            vector<vector<int>> d(h+1,vector<int>(w+1,0));
            vector<vector<int>> visited(h+1,vector<int>(w+1,-1));
            
            for(int i=0;i<o;i++){
                  int x,y,l;
                  cin>>x>>y>>l;
                  d[x][y]=l;
            }
            
            queue<tuple<int,int,int>> q;
            q.push({xs,ys,f});
            visited[xs][ys]=f;
            while(!q.empty()){
                  auto [x,y,force]=q.front();
                  q.pop();
                  if(x==xe && y==ye){
                        cout<<"잘했어!!\n";
                        goto next_case;
                  }
                  for(int i=0;i<4;i++){
                        int xx=x+dx[i], yy=y+dy[i];
                        if(xx>=1 && yy>=1 && xx<=h && yy<=w) {
                              int jump = d[xx][yy] - d[x][y];
                              if(jump<=0 && visited[xx][yy]<force-1) {
                                    visited[xx][yy]=force-1;
                                    q.push({xx,yy,force-1});
                              }
                              else if(jump<=force && visited[xx][yy]<force-1) {
                                    visited[xx][yy]=force-1;
                                    q.push({xx,yy,force-1});
                              }
                        }
                  }
            }
            cout<<"인성 문제있어??\n";
      next_case:;
      }
}