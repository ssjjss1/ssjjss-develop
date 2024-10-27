#include<iostream>
using namespace std;
long long n,m,sum;
long long d[100004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++) cin>>d[i];
      for(int i=n;i>=1;i--){
            sum+=d[i];
            if(sum>=m) {
                  cout<<i;
                  return 0;
            }
      }
      cout<<-1;
}