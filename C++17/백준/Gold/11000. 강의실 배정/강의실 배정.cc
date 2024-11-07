#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> q;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x,y;i<=n;i++) cin>>x>>y, v.push_back({x,y});
      sort(v.begin(),v.end());
      for(int i=0;i<n;i++){
            q.push(v[i].second);
            if(q.top()<=v[i].first) q.pop();
      }
      cout<<q.size();
}