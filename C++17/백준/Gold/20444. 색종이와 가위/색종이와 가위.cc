#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>n>>k;
      long long l=0, r=n/2;
      while(l<=r){
            long long middle=(l+r)/2;
            long long res=(n-middle+1)*(middle+1);
            if(res<k){
                  l=middle+1;
            } else if(res==k){
                  //cout<<middle<<"\n";
                  cout<<"YES";
                  return 0;
            } else{
                  r=middle-1;
            }
      }
      cout<<"NO";
}