#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>t;
      while(t--){
            cin>>n;
            int mx=-1e9+7;
            vector<int> v(n+4,0);
            for(int i=1;i<=n;i++) cin>>v[i];
            for(int i=1;i<=n;i++){
                  int sum=0;
                  for(int j=i;j<=n;j++){
                        sum+=v[j];
                        mx=max(mx, sum);
                  }
            }
            cout<<mx<<"\n";
      }
}