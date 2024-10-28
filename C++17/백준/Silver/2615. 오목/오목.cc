#include<bits/stdc++.h>
using namespace std;
int d[34][34];
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
bool check(int x, int y){
      for(int i=0;i<8;i++){
            int cnt=0;
            for(int j=1;j<=20;j++){
                  if((x+dx[i]*j)<1||(x+dx[i]*j)>19||(y+dy[i]*j)<1||(y+dy[i]*j)>19||d[x][y]!=d[x+dx[i]*j][y+dy[i]*j]) break;
                  cnt+=1;
            }
            if(cnt==4&&d[x-dx[i]][y-dy[i]]!=d[x][y]) return 1; 
      }
      return 0;
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      for(int i=1;i<=19;i++){
            for(int j=1;j<=19;j++){
                  cin>>d[i][j];
            }
      }
      for(int j=1;j<=19;j++){
            for(int i=1;i<=19;i++){
                  if(d[i][j]!=0){
                        if(check(i,j)){
                              cout<<d[i][j]<<"\n"<<i<<" "<<j;
                              return 0;
                        }
                  }
            }
      }
      cout<<0;
}