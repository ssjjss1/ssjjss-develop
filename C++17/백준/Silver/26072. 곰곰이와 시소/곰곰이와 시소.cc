#include<bits/stdc++.h>
using namespace std;
int n;
double l;
double a[100004], b[100004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>l;
      for(int i=1;i<=n;i++) cin>>a[i];
      for(int i=1;i<=n;i++) cin>>b[i];
      double left=0, right=l;
      double ans=0;
      for(int i=1;i<=100;i++){
            double mid=(left+right)/2;
            double sum=0;
            for(int j=1;j<=n;j++) sum+=double(b[j]*(mid-a[j]));
            if(sum>=0) right=mid-1;
            else left=mid+1;
            ans=mid;
      }
      cout<<fixed<<setprecision(20)<<ans;
}