#include<iostream>
using namespace std;
const int inf=-987654321;
int dp[50001][4];
int a[50001];
int n,m;
int f(int x, int cnt){
  if(x>n){
    return cnt==3?0:inf; 
  }
  int &ref=dp[x][cnt];
  if(ref!=inf) return ref;
  if(cnt<3&&x+m-1<=n) ref=max(ref,f(x+m,cnt+1)+a[x+m-1]-a[x-1]);
  ref=max(ref,f(x+1,cnt));
  return ref;
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    a[i]+=a[i-1];
  }
  cin>>m;
  fill(&dp[0][0],&dp[0][0]+50001*4,inf);
  cout<<f(1,0);
}