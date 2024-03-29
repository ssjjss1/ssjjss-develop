#include<iostream>
using namespace std;
long long int a,b;
long long int g(long long int x, long long int y){
  if(y==0) return x;
  return g(y,x%y);
}
long long int f(long long int x,long long int y){
  return a*b/g(a,b);
}
int main(){
  cin>>a>>b;
  cout<<g(a,b)<<"\n"<<f(a,b);
}