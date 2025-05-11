#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>k>>m;
      
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
      }
      
      for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            if(x>0&&k<=x){
                  k=(x+1-k);
            } else if(x<0&&n+x<k){
                  k=2*n+x-k+1;
            }
      }
      
      cout<<k;
}