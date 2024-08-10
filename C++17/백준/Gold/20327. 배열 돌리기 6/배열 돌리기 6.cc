#include<iostream>
using namespace std;
int n,r;
int d[304][304];
void f1(int s,int x, int y){
  for(int i=0;i<s/2;i++){
    for(int j=0;j<s;j++){
      swap(d[i+x][j+y],d[x+s-i-1][j+y]);
    }
  }
}
void f2(int s,int x, int y){
  for(int i=0;i<s;i++){
    for(int j=0;j<s/2;j++){
      swap(d[i+x][j+y],d[i+x][y+s-j-1]);
    }
  }
}
void f3(int s, int x, int y){
  int t[134][134];
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      t[j][s-i-1]=d[i+x][j+y];
    }
  }
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      d[x+i][y+j]=t[i][j];
    }
  }
}
void f4(int s, int x, int y){
  int t[134][134];
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      t[s-j-1][i]=d[i+x][j+y];
    }
  }
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      d[x+i][y+j]=t[i][j];
    }
  }
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>r;
  for(int i=1;i<=1<<n;i++){
    for(int j=1;j<=1<<n;j++){
      cin>>d[i][j];
    }
  }
  while(r--){
    int x,y;
    cin>>x>>y;
    if(x<=4){
      for(int i=1;i<=(1<<n);i+=(1<<y)){
        for(int j=1;j<=(1<<n);j+=(1<<y)){
          if(x==1) f1(1<<y,i,j);
          if(x==2) f2(1<<y,i,j);
          if(x==3) f3(1<<y,i,j);
          if(x==4) f4(1<<y,i,j);
        }
      }
    }
    if(x==5){
      f1(1<<n,1,1);
      for(int i=1;i<=(1<<n);i+=(1<<y)){
        for(int j=1;j<=(1<<n);j+=(1<<y)){
          f1(1<<y,i,j);
        }
      }
    }
    if(x==6){
      f2(1<<n,1,1);
      for(int i=1;i<=(1<<n);i+=(1<<y)){
        for(int j=1;j<=(1<<n);j+=(1<<y)){
          f2(1<<y,i,j);
        }
      }
    }
    if(x==7){
      f3(1<<n,1,1);
      for(int i=1;i<=(1<<n);i+=(1<<y)){
        for(int j=1;j<=(1<<n);j+=(1<<y)){
          f4(1<<y,i,j);
        }
      }
    }
    if(x==8){
      f4(1<<n,1,1);
      for(int i=1;i<=(1<<n);i+=(1<<y)){
        for(int j=1;j<=(1<<n);j+=(1<<y)){
          f3(1<<y,i,j);
        }
      }
    }
  }
  for(int i=1;i<=(1<<n);i++){
    for(int j=1;j<=(1<<n);j++){
      cout<<d[i][j]<<" ";
    }
    cout<<"\n";
  }
} 