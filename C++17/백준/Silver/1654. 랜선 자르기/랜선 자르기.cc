#include<iostream>
using namespace std;
int n,m;
int a[10004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      int mx=0;
      for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx, a[i]);
      long long l=1, r=mx,ans=0;
      while(l<=r){
            long long mid=(l+r)/2;
            long long cnt=0;
            for(int i=1;i<=n;i++) cnt+=a[i]/mid;
            if(m>cnt) r=mid-1;
            else if(m<=cnt) l=mid+1,ans=max(ans, mid);
      }
      cout<<ans;
}