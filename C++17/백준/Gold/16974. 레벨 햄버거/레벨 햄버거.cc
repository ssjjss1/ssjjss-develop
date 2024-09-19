#include<iostream>
using namespace std;
long long n,m;
long long patty[54], buger[54];
long long f(long long x,int level){
      if(level==0){
            if(x==1) return 1;
            else return 0;
      }
      else if(x==1) return 0;
      else if(x<=buger[level-1]+1) return f(x-1,level-1);
      else if(x==buger[level-1]+1) return patty[level-1]+1;
      else if(x<=2*buger[level-1]+2) return patty[level-1]+1+f(x-buger[level-1]-2,level-1);
      else if(x==buger[level]) return patty[level];
}
int main(){
      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n>>m;
      patty[0]=1,buger[0]=1;
      for(int i=1;i<=n;i++) patty[i]=patty[i-1]*2+1, buger[i]=buger[i-1]*2+3;
      cout<<f(m,n);
}