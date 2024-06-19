#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int a[100004];
vector<int> v[100004];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  while(m--){
    int t;
    cin>>t;
    vector<int> _v(t+4,0);
    for(int i=1,x;i<=t;i++){
      cin>>x;
      _v[i]=x;
    }
    for(int i=1;i<t;i++){
      v[_v[i]].push_back(_v[i+1]);
      a[_v[i+1]]+=1;
    }
  }
  int cnt=0;
  vector<int> _v(n+4,0);
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(!a[i]) q.push(i);
  }
  while(!q.empty()){
    int x=q.front();
    q.pop();
    cnt+=1;
    _v[cnt]=x;
    for(auto i:v[x]){
      if(!--a[i]) q.push(i);
    }
  }
  if(cnt!=n) cout<<0;
  else{
    for(int i=1;i<=n;i++)cout<<_v[i]<<"\n";
  }
}