#include<bits/stdc++.h>
using namespace std;
int n,m;

int d[200004];

bool comp(pair<int,int> &a, pair<int,int> &b){
      if(a.first==b.first) return a.second<b.second;
      return a.first>b.first;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>m;
      vector<pair<int,int>> v;
      
      for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            
            d[x]=i;
      }
      
      for(int i=1;i<=n;i++){
            v.push_back({d[i], i});
      }
      
      sort(v.begin(),v.end(), comp);
      
      for(auto i:v){
            cout<<i.second<<"\n";
      }
}