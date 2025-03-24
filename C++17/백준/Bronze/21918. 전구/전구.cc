#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>m;
      
      vector<int> v(n+1);
      for(int i=1;i<=n;i++){
            cin>>v[i];
      }
      
      while(m--){
            int t;
            cin>>t;
            
            if(t==1){
                  int i,x;
                  cin>>i>>x;
                  
                  v[i]=x;
            } else{
                  int l,r;
                  cin>>l>>r;
                  
                  if(t==2){
                        for(int i=l;i<=r;i++){
                              v[i]=!v[i];
                        }
                  } else if(t==3){
                        for(int i=l;i<=r;i++){
                              v[i]=0;
                        }
                  }else{
                        for(int i=l;i<=r;i++){
                              v[i]=1;
                        }
                  }
            }
      }
      
      for(int i=1;i<=n;i++){
            cout<<v[i]<<" ";
      }
}