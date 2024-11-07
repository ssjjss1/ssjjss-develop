#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
vector<pair<int,int>> v;
bool compare(pair<int,int> a, pair<int,int> b){
      if(a.second==b.second) return a.first<=b.first; 
      return a.second<=b.second;
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x,y;i<=n;i++) cin>>x>>y, v.push_back({x,y});
      sort(v.begin(),v.end(),compare);
      int y=v[0].second;
      for(int i=1;i<n;i++){
            if(v[i].first<y) continue;
            y=v[i].second;
            cnt+=1;
      }
      cout<<cnt;
}