#include<iostream>
#include<vector>
using namespace std;
int n,mx,mx_idx;
vector<pair<int,int>> v[100004];
int visited[100004];
void f(int x, int sum){
      if(visited[x]) return;
      if(mx<sum) mx=max(mx, sum), mx_idx=x;
      visited[x]=1;
      for(auto i: v[x]){
            int idx=i.first, cnt=i.second;
            f(idx, sum+cnt);
      }
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1,x;i<=n;i++) {
            cin>>x;
            while(true){
                  int y,z;
                  cin>>y;
                  if(y==-1) break;
                  else cin>>z, v[x].push_back({y,z});
            }
      }
      f(1,0);
      fill(visited,visited+n+1,0);
      mx=0;
      f(mx_idx,0);
      cout<<mx;
}