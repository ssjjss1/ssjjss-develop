#include<bits/stdc++.h>
using namespace std;
int t;

int gcd(int a, int b){
      if(b==0) return a;
      return gcd(b, a%b);
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>t;
      while(t--){
            int a,b;
            cin>>a>>b;
            
            cout<<gcd(a,b)<<"\n";
      }
}