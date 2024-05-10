#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
using matrix = vector<vector<ll>>;
const ll mod=1e9+7;
ll n,m,d;
matrix g(const matrix &v,const matrix &cnt){
  matrix ans(51,vector<ll>(51));
  for(int i=0;i<51;i++){
    for(int j=0;j<51;j++){
      for(int k=0;k<51;k++){
        ans[i][k]=(ans[i][k]+v[i][j]*cnt[j][k])%mod;
      }
    }
  }
  return ans;
}
matrix f(matrix v,ll cnt){
  matrix ans(51,vector<ll>(51));
  for(int i=0;i<51;i++) ans[i][i]=1;
  for(;cnt;cnt>>=1,v=g(v,v)){
    if(cnt&1) ans=g(ans,v);
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  matrix p(51,vector<ll>(51));
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    p[u-1][v-1]=p[v-1][u-1]=1;
  }
  cin>>d;
  cout<<f(p,d)[0][0];
}