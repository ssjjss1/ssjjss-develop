#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int inf=1e9+4;
int t;
int n,d,c;// 컴 개수, 의존 개수, 감염된 컴 번호
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>t;
  while(t--){
    int visited[10004];// 이동 시간의 최솟값
    fill(visited,visited+10004,inf);
    vector<pair<int,int>> v[100004];
    cin>>n>>d>>c;
    for(int i=1,x,y,z;i<=d;i++){
      cin>>x>>y>>z;
      v[y].push_back({x,z});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,c});
    visited[c]=0;
    int mx=0,ans=0;
    while(!q.empty()){
      int x=q.top().second, y=q.top().first;
      q.pop();
      if(visited[x]<y) continue;
      mx=max(mx,y);
      ans+=1;
      for(auto i:v[x]){
        int xx=i.first,yy=i.second;
        if(visited[xx]>visited[x]+yy){
          visited[xx]=visited[x]+yy;
          q.push({visited[xx],xx});
        }
      }
    }
    cout<<ans<<" "<<mx<<"\n";
  }
}