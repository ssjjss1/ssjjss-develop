#include<iostream>
using namespace std;
int n,m,k;
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m>>k;
      int mod=n%m;
      for(int i=1;i<=k;i++){
            mod*=10;
            if(i!=k)mod%=m;
      }
      cout<<mod/m;
}