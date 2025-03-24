#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>m;
      
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            
            v.push_back(x);
      }
      
      int l=0,r=100004,ans=100004;
      while(l<=r){
            int middle=(l+r)/2;
            
            bool flag=true;
            
            for(int i=0;i<v.size();i++){
                  if(i==0&&v[i]-middle>0){
                        flag=false;
                        break;
                  }
                  if(v[i]+middle<v[i+1]-middle&&i!=v.size()-1) {
                        flag=false;
                        break;
                  }
                  if(i==v.size()-1&&v[i]+middle<n){
                        flag=false;
                        break;
                  }
            }
            
            if(flag) {
                  r=middle-1;
                  ans=min(middle,ans);
            } else {
                  l=middle+1;
            }
      }
      cout<<ans;
}