#include<bits/stdc++.h>
typedef long long ll;
using namespace std;   
const int inf=9876543;
int n,a[44],ret=inf;
string s; 
void f(int t){
  if(t==n+1){
    int sum=0; 
    for(int i=1;i<=(1<<(n-1));i*=2){
      int cnt=0; 
      for(int j=1;j<=n;j++) if(a[j]&i)cnt++;
      sum+=min(cnt,n-cnt); 
    }
    ret=min(ret, sum);
    return;
  } 
  f(t+1);
  a[t]=~a[t];
  f(t+1);
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  cin>>n; 
  for(int i=1;i<=n;i++){
    cin>>s; 
    int value=1; 
    for(int j=0;j<s.size();j++){
      if(s[j]=='T')a[i]|=value; 
      value*=2;
    }
  }   
  f(1);
  cout<<ret;
}