#include<bits/stdc++.h>
using namespace std;
int t;
long long fibo[54];
int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);
      fibo[0]=0, fibo[1]=1;
      for(int i=2;i<=44;i++) fibo[i]=fibo[i-1]+fibo[i-2];
      
      cin>>t;
      while(t--){
            vector<long long> v;
            long long n;
            cin>>n;
            for(int i=44;i>=1;i--){
                  if(n>=fibo[i]) {
                        n-=fibo[i];
                        v.push_back(fibo[i]);
                  }
                  if(!n) break;
            }
            for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<' ';
            cout<<"\n";
      }
}