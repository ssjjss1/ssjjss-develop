#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,long long>> v;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int n;
      cin>>n;
      
      for(int i=1;i<=n;i++){
            long long x,y;
            cin>>x>>y;
            v.push_back({x,y});
      }
      
      sort(v.begin(),v.end());
      
      long long cnt=1, prev=v[0].first+v[0].second;
      for(int i=1;i<n;i++){
            if(prev<v[i].first) cnt+=1;
            prev=v[i].first+v[i].second;
      }
      
      cout<<cnt;
}