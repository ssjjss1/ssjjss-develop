#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[100004];
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=1;i<=n;i++) cin>>a[i];
      sort(a+1, a+n+1);
      cin>>m;
      while(m--){
            int x;
            cin>>x;
            int l=1,r=n;
            bool flag=true;
            while(l<=r){
                  int mid=(l+r)/2;
                  if(a[mid]==x) {
                        cout<<1<<"\n";
                        flag=false;
                        break;
                  }
                  if(a[mid]<x) l=mid+1;
                  if(a[mid]>x) r=mid-1;
            }
            if(flag) cout<<0<<"\n";
      }
}