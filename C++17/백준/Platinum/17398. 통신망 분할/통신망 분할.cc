#include<bits/stdc++.h>
using namespace std;
int n,m,q;

long long parent[100004], t_size[100004];
vector<pair<int,int>> dist;
vector<bool> removed;
vector<int> question;

void Init(){
      for(int i=1;i<=n;i++){
            parent[i]=i;
            t_size[i]=1;
      }
}

int find(int x){
      if(parent[x]==x) return x;
      return parent[x]=find(parent[x]);
}

void union_set(int x, int y){
      x=find(x), y=find(y);
      if(x!=y){
            if(t_size[x] < t_size[y]) swap(x, y);
            parent[y] = x;
            t_size[x] += t_size[y];
      }
}

int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);
      cin>>n>>m>>q;
      dist.resize(m+1);
      removed.resize(m+1, false);
      
      for(int i=1;i<=m;i++) {
            int x,y;
            cin>>x>>y;
            dist[i] = {x,y};
      }
      
      for(int i=0;i<q;i++){
            int x; 
            cin>>x;
            question.push_back(x);
            removed[x]=true;
      }
      
      Init();
      for(int i=1;i<=m;i++){
            if(!removed[i]) union_set(dist[i].first, dist[i].second);
      }
      
      long long ans=0;
      reverse(question.begin(), question.end());
      for(int i=0;i<q;i++){
            int idx = question[i];
            int u = dist[idx].first, v = dist[idx].second;
            if(find(u) != find(v)){
                  ans += t_size[find(u)] * t_size[find(v)];
                  union_set(u, v);
            }
      }
      cout<<ans;
}