#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
struct P {
  ll a, b, c;
  bool operator>(const P &other) const { return a > other.a; }
};
int n,m,k;
const ll inf = 1e18+4;
vector<pair<int,int>> v[50004];
ll visited[10004][24];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m>>k;
  for(int i=1,x,y,z;i<=m;i++){
    cin>>x>>y>>z;
    v[x].push_back({y,z});
    v[y].push_back({x,z});
  }
  fill(&visited[0][0],&visited[0][0]+10004*24,inf);
  priority_queue<P,vector<P>,greater<P>> q;
  q.push({0,1,0});
  visited[1][0]=1;
  while(q.size()){
    ll x = q.top().b,y=q.top().a,cnt=q.top().c;
    q.pop();
    if(x==n) continue;
    if(visited[x][cnt]<y) continue;
    for(auto i:v[x]){
      ll xx=i.first,yy=i.second;
      if(visited[xx][cnt]>yy+y){
        visited[xx][cnt]=y+yy;
        q.push({yy+y,xx,cnt});
      }
      if(cnt<k){
        if(visited[xx][cnt+1]>y){
          visited[xx][cnt+1]=y;
          q.push({y,xx,cnt+1});
        }
      }
    }
  }
  ll mn=inf;
  for(int i=0;i<=k;i++) mn=min(mn,visited[n][i]);
  cout<<mn;
}