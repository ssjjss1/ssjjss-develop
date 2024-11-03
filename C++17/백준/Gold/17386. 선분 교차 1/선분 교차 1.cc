#include<iostream>
using namespace std;
using Point=pair<long long,long long>;
int ccw(Point x, Point y, Point z){
      long long res=(y.first-x.first)*(z.second-x.second);
      res-=(y.second-x.second)*(z.first-x.first);
      return (res>0)-(res<0);
}
bool cross(Point a, Point b, Point c, Point d){
      int ab=ccw(a,b,c)*ccw(a,b,d);
      int cd=ccw(c,d,a)*ccw(c,d,b);
      if(ab==0&&cd==0){
            if(a>b) swap(a,b);
            if(c>d) swap(c,d);
            return !(b<c||d<a);
      }
      return ab<=0&&cd<=0;
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      Point P[5];
      for(int i=1,x,y;i<=4;i++){
            cin>>x>>y;
            P[i]={x,y};
      }
      cout<<cross(P[1],P[2],P[3],P[4]);
}