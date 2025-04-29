#include<bits/stdc++.h>
using namespace std;
int n;
bool flag=false;

set<string> name;
map<string,vector<string>> ma;
map<string,bool> visited;

void dfs(string a, string b){
      visited[b]=1;
      for(auto c : ma[b]){
            if(a==c) {
                  flag=true;
                  return;
            }
            if(!visited[c]) dfs(a,c);
      }
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      int test=1;
      while(true){
            cin>>n;

            if(n==0) break;
            
            int cnt=0;
            visited.clear();
            name.clear();
            ma.clear();
            
            for(int i=1;i<=n;i++){
                  string a,b;
                  cin>>a>>b;
                  
                  ma[a].push_back(b);
                  name.insert(a);
                  name.insert(b);
            }
            
            for(auto a:name){
                  if(!visited[a]){
                        flag=false;
                        dfs(a,a);
                        if(flag){
                              cnt+=1;
                        }
                  }
            }
            
            cout<<test++<<" "<<cnt<<"\n";
      }
}