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
      
      long long prev=v[n-1];
      for(int i=n-2;i>=0;i--){
            if(v[i]<prev) {
                  long long temp;
                  temp=v[i]*(prev/v[i])+(prev%v[i]?v[i]:0);
                  prev=temp;
            } else prev=v[i];
      }
      
      cout<<prev;
}