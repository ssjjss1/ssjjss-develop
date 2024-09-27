#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
      if(a.first==b.first)return a.second<b.second;
      return a.first<b.first;
}
int n;
vector<pair<int,int>> v;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x,y;i<=n;i++) cin>>x>>y,v.push_back({x,y});
      sort(v.begin(),v.end(),compare);
      for(auto i:v) cout<<i.first<<" "<<i.second<<"\n";
}