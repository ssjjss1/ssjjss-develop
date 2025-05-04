#include<bits/stdc++.h>
using namespace std;
int s,n,m,manyItems;
int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>s>>n>>m;
      
      for(int i=1;i<=n+m;i++){
            int x;
            cin>>x;
            
            if(x==0){
                  manyItems-=1;
            } else{
                  if(++manyItems>s){
                        s*=2;
                  }
            }
      }
      
      cout<<s;
}