#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long res=0;

void f(long long x){
      if(b<x) return;
      
      if(x>=a) res+=1;
      
      f(10*x+7);
      f(10*x+4);
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cin>>a>>b;
      
      f(4);
      f(7);
      
      cout<<res;
}