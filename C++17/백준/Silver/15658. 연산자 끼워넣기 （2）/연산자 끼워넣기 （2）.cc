#include<iostream>
#include<vector>
using namespace std;
const int inf=1e9+4;
int n;
int mn=inf,mx=-inf;
int d[14];
void f(vector<int> v, int sum, int cnt){
  if(cnt==n){
    mx=max(mx,sum);
    mn=min(mn,sum);
    return;
  }
  for(int i=1;i<=4;i++){
    if(v[i]<=0) continue;
    if(i==1){
      v[i]-=1;
      f(v,sum+d[cnt+1],cnt+1);
      v[i]+=1;
    }
    if(i==2){
      v[i]-=1;
      f(v,sum-d[cnt+1],cnt+1);
      v[i]+=1;
    }
    if(i==3){
      v[i]-=1;
      f(v,sum*d[cnt+1],cnt+1);
      v[i]+=1;
    }
    if(i==4){
      v[i]-=1;
      f(v,sum/d[cnt+1],cnt+1);
      v[i]+=1;
    }
  }
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  vector<int> v(5); //+,-,x,/
  for(int i=1;i<=n;i++) cin>>d[i];
  for(int i=1;i<=4;i++) cin>>v[i];
  f(v,d[1],1);
  cout<<mx<<"\n"<<mn;
}