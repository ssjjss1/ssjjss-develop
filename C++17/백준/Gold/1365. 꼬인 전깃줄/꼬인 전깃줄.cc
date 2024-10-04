#include<iostream>
using namespace std;
int n,x,idx;
int d[100004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++){
            cin>>x;
            auto it=lower_bound(d,d+idx,x);
            if(*it==0) idx+=1;
            *it=x;
      }
      cout<<n-idx;
}