#include<iostream>
using namespace std;
int n;
int sum;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  int ans=-987654321;
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    sum+=x;
    ans=max(ans,sum);
    if(sum<=0) sum=0;
  }
  cout<<ans;
}