#include<bits/stdc++.h>
using namespace std;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int x1, x2, x3, y1, y2, y3,q;
      cin>>x1>>y1>>x2>>y2>>x3>>y3>>q;
      
      while(q--){
            int x,y, t1,t2,t3;
            cin>>x>>y>>t1>>t2>>t3;
            
            int r1=abs(x1-x)+abs(y1-y);
            int r2=abs(x2-x)+abs(y2-y);
            int r3=abs(x3-x)+abs(y3-y);
            
            cout<<min({(r1/t1+(r1%t1>0))*t1, (r2/t2+(r2%t2>0))*t2, (r3/t3+(r3%t3>0))*t3})<<"\n";
      }
}