#include<iostream>
using namespace std;
int n;
long long int a[100];
long long int f(int cnt){
  if(cnt==0) {
    return a[0];
  }
  if(cnt==1){
    return a[1];
  }
  long long int &ref=a[cnt];
  if(ref) return ref;
  return ref=f(cnt-1)+f(cnt-2);
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  a[0]=0;
  a[1]=1;
  cout<<f(n);
}