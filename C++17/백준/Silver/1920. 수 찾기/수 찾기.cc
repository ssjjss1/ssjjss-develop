#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void g(int a,int b,int x,vector<long long int>& k){
  int middle;
  middle=(a+b)/2;
  if(a>b){
    cout<<0<<"\n";
    return;
  }
  if(k[middle]==x){
    cout<<1<<"\n";
    return;
  }
  else if(k[middle]<x) return g(middle+1,b,x,k);
  else if(k[middle]>x) return g(a,middle-1,x,k);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n,m;
  cin>>n;
  vector<long long int> k(n);
  for(int i=0;i<n;i++){
    cin>>k[i];
  }
  sort(k.begin(),k.end());
  //f(k,0,n-1);
  cin>>m;
  long long int x;
  for(int i=0;i<m;i++){
    cin>>x;
    g(0,n-1,x,k);
  }
}