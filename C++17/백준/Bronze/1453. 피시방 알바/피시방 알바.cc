#include<bits/stdc++.h>
using namespace std;
int n,ans;
int visited[104];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++){
            int x; cin>>x;
            if(visited[x]) ans+=1;
            visited[x]=1;
      }
      cout<<ans;
}