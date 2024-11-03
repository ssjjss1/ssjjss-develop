#include<iostream>
#include<vector>
using namespace std;
struct P{
      int a,b;
};
vector<P> v(4);
int ccw(){
      long long res=v[1].a*v[2].b+v[2].a*v[3].b+v[3].a*v[1].b;
      res-=v[1].b*v[2].a+v[2].b*v[3].a+v[3].b*v[1].a;
      return (res>0)-(res<0);
}
int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      for(int i=1,x,y;i<=3;i++){
            cin>>x>>y;
            v[i]={x,y};
      }
      cout<<ccw();
}