#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>t;
      while(t--){
            int n; cin>>n;
            vector<int> visited(n+1);
            vector<int> v,ans(n+1);
            for(int i=0;i<n;i++){
                  int x;cin>>x;
                  v.push_back(x);
            }
            bool flag=true;
            for(int i=n-1;i>=0;i--){
                  int cnt=v[i];
                  for(int j=1;j<=n;j++){
                        if(!visited[j]){
                              if(cnt==0) {
                                    ans[i]=j;
                                    visited[j]=1;
                                    break;
                              }
                              else cnt-=1;
                        }
                  }
                  if(!ans[i]){
                        cout<<"IMPOSSIBLE"<<'\n';
                        flag=false;
                        break;
                  }
            }
            if(flag){
                  for(int i=0;i<n;i++) cout<<ans[i]<<' ';
                  cout<<'\n';
            }
      }
}