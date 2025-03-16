#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long sum[100004];
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>m>>q;
      for(int i=1;i<=m;i++){
            int x,val;
            cin>>x>>val;
            sum[x]=val;
      }
      
      for(int i=2;i<=n;i++){
            sum[i]+=sum[i-1];
      }
      
      int l=1, r=n;
      while(q--){
            int x;
            cin>>x;
            
            if(l<=x&&x<=r){
                  long long mnl=sum[x]-(l>1?sum[l-1]:0);
                  long long mnr=sum[r]-sum[x-1];
                  
                  if(mnr==mnl){
                        if(x-1>n-x) r=x;
                        else l=x;
                        cout<<mnl<<"\n";
                  }else if(mnr>mnl) {
                        l=x;
                        cout<<mnl<<"\n";
                  } else{
                        r=x;
                        cout<<mnr<<"\n";
                  }
            } else cout<<0<<"\n";
            
      }
}