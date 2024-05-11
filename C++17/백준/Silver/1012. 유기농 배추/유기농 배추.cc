#include <iostream>
using namespace std;
long long int n;
long long int a,b,c;
long long int x,y;
long long int cnt=0;
long long int d[100][100]={};
void f(int x, int y){
  if(x<0||y<0||x>=a||y>=b) return;
  else if(d[y][x]!=1) return;
  else{
    d[y][x]=2;
    f(x,y+1);
    f(x-1,y);
    f(x+1,y);
    f(x,y-1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a>>b>>c;
    for(int i=1;i<=c;i++){
      cin>>x>>y;
      d[y][x]=1;
    }
    for(int i=0;i<a;i++){
      for(int j=0;j<b;j++){
        if(d[j][i]==1){
          f(i,j);
          cnt+=1;
        }
      }
    }
    cout<<cnt<<"\n";
    for(int i=0;i<a;i++){
      for(int j=0;j<b;j++){
        d[j][i]=0;
      }
    }
    cnt=0;
  }
}