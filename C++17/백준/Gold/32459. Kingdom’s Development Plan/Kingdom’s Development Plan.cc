#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int in[200004];
vector<int> v[200004], v1;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      for(int i=1,x,y;i<=m;i++){
            cin>>x>>y;
            in[y]+=1;
            v[x].push_back(y);
      }
      for(int i=1;i<=n;i++) sort(v[i].begin(), v[i].end());
      priority_queue<int,vector<int>,greater<int>> q;
      for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
      while(!q.empty()){
            int x=q.top();q.pop();
            v1.push_back(x);
            for(auto i:v[x]){
                  if(!--in[i]) q.push(i);
            }
      }
      if(v1.size()==n) for(auto i:v1) cout<<i<<" ";
      else cout<<"IMPOSSIBLE";
}