#include<bits/stdc++.h>
using namespace std;
int n,m;
int parent[1004];

void Init(){
      for(int i=0;i<1003;i++) parent[i]=i;
}

int find(int x){
      if(x==parent[x]) return x;
      return parent[x]=find(parent[x]);
}

void unionSet(int x, int y){
      x = find(x);
      y = find(y);
      
      if(x!=y){
            parent[y]=x;
      }
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>m;

      Init();
      
      vector<string> t;
      for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            t.push_back(s);
      }
      
      vector<tuple<int, int, int>> v;
      for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                  string a=t[i], b=t[j];
                  int cnt=0;
                  
                  for(int k=0;k<m;k++){
                        if(a[k]!=b[k]){
                              cnt+=1;
                        }
                  }
                  
                  v.push_back({cnt,i,j});
            }
      }
      
      sort(v.begin(),v.end());

      int total = 0;
      vector<pair<int,int>> ans;
      for(auto x : v){
            int cost = get<0>(x);
            int i = get<1>(x);
            int j = get<2>(x);
            if(find(i) != find(j)){
                  unionSet(i,j);
                  total += cost;
                  ans.push_back({i,j});
            }
      }

      cout << total << "\n";
      for(auto [u, v] : ans){
            cout << u << " " << v << "\n";
      }
}