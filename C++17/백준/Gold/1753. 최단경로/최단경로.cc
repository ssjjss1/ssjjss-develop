#include<iostream>

#include<vector>

#include<queue>

using namespace std;

int n,m,k;

int x,y,z;

int d[20001];

const int inf=987654321;

vector<pair<int,int>> v[200001];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

int main(){

  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  cin>>n>>m>>k;

  fill(d,d+20001,inf);

  for(int i=1;i<=m;i++){

    cin>>x>>y>>z;

    v[x].push_back({y,z});

  }

  q.push({0,k});

  d[k]=0;

  while(!q.empty()){

    int x=q.top().second,y=q.top().first;

    q.pop();

    if(d[x]!=y) continue;

    for(auto i:v[x]){

      int p=i.first,l=i.second;

      if(d[p]>d[x]+l){

        d[p]=d[x]+l;

        q.push({d[p],p});

      }

    }

  }

  for(int i=1;i<=n;i++){

    if(d[i]==inf) cout<<"INF"<<"\n";

    else cout<<d[i]<<"\n";

  }

}