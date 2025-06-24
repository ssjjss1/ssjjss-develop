#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      vector<long long> v(n);
      for(int i=0;i<n;i++){
            cin>>v[i];
      }
      
      sort(v.begin(), v.end());
      int l=0, r=n-1;
      long long alice=0, bob=0;
      while(n>0){
            if(n%2) bob+=v[l], l+=1;
            else alice+=v[r], r-=1;
            
            if(alice<=bob) {
                  cout<<"Bob";
                  return 0;
            }
            n-=1;
      }
      cout<<"Alice";
}