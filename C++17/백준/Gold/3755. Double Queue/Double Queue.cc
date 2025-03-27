#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> visited;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> less_pq;
      priority_queue<pair<int,int>> high_pq;
      while(true){
            int x;
            cin>>x;
            if(x==0) return 0;
            else if(x==1){
                  int p,k;
                  cin>>k>>p;
                  less_pq.push({p,k});
                  high_pq.push({p,k});
                  visited[k]=0;
            } else if(x==2){
                  int ans=-1;
                  while(!high_pq.empty()){
                        int h=high_pq.top().second;
                        high_pq.pop();
                        if(!visited[h]){
                              ans=h;
                              visited[h]=1;
                              break;
                        }
                  }
                  if(ans==-1) cout<<0<<"\n";
                  else cout<<ans<<"\n";
            } else {
                  int ans=-1;
                  while(!less_pq.empty()){
                        int l=less_pq.top().second;
                        less_pq.pop();
                        if(!visited[l]){
                              ans=l;
                              visited[l]=1;
                              break;
                        }
                  }
                  if(ans==-1) cout<<0<<"\n";
                  else cout<<ans<<"\n";
            }
      }
}