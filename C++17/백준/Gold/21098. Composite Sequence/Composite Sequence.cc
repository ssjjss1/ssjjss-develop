#include<bits/stdc++.h>
using namespace std;
long long n;

bool check(long long x){
      for(long long i=2;i*i<=x;i++){
            if(x%i==0) return false;
      }
      return true;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      
      cin>>n;
      
      vector<long long> odd, even, v;
      for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            
            v.push_back(x);
            if(x%2) odd.push_back(x);
            else even.push_back(x);
      }
      
      if(even.size()>2){
            cout<<"Yes";
      } else{
            if(n<=3){
                  for(int i=0;i<(1<<n);i++){
                        long long sum=0;
                        for(int j=0;j<n;j++){
                              if((1<<j)&i){
                                    sum+=v[j];
                              }
                        }
                        
                        if(!check(sum)) {
                              cout<<"Yes";
                              return 0;
                        } 
                  }
                  
                  cout<<"No";
            } else {
                  cout<<"Yes";
            }
      }
}