#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100004];
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n>>k;
      vector<int> v(n);
      for(int i=0;i<n;i++){
            cin>>v[i];
      }
      
      int l=0, r=0;
      int mx=0;
      while(r<n){
           if(a[v[r]] < k){
                 a[v[r]]+=1;
                 r+=1;
                 mx=max(mx, r-l);
           } 
           else {
                 a[v[l]]-=1;
                 l+=1;
           }
      }
      
      cout<<mx;
}