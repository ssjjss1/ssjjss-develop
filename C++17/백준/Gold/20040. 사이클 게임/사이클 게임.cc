#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> parent;

void Init(){
      for(int i=0;i<n;i++){
            parent[i]=i;
      }
}

int Find(int x){
      if(x==parent[x]) return x;
      return parent[x]=Find(parent[x]);
}

void Union(int x, int y){
      x=Find(x);
      y=Find(y);
      
      if(x!=y){
            parent[x]=y;
      }
}

int main(){
      ios::sync_with_stdio(0);cin.tie(0);
      cin>>n>>m;
      parent.resize(n+4);
      Init();
      
      int ans=0;
      for(int i=1;i<=m;i++){
            ans++;
            int x,y;
            cin>>x>>y;
            if(Find(x)!=Find(y)){
                  Union(x,y);
            } else{
                  cout<<ans;
                  return 0;
            }
      }
      cout<<0;
}