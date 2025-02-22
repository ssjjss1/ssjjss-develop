#include<bits/stdc++.h>
using namespace std;
int n, ans;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n;
      vector<int> v;
      int cnt=1, prev;
      cin>>prev;
      for(int i=1;i<n;i++){
            int x;
            cin>>x;
            if(prev!=x) {
                  v.push_back(cnt);
                  ans=max(ans, cnt);
                  cnt=1;
                  prev=x;
            } else {
                  cnt++;
            }
      }
      v.push_back(cnt);
      ans=max(ans, cnt);
      
      for(int i=0;i<(int)v.size()-1;i++){
            ans=max(ans, v[i]+v[i+1]);
      }
      
      cout<<ans;
}