#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll n,ans;
ll a[100004];
stack<ll> s;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  s.push(0);
  for(int i=1;i<=n+1;i++){
    while(!s.empty()&&a[s.top()]>a[i]){
      int k=s.top();
      s.pop();
      ans=max(ans,a[k]*(i-s.top()-1));
    }
    s.push(i);
  }
  cout<<ans;
}