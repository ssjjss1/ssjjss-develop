#include<iostream>
#include<vector>
#define mx 100000001
using namespace std;
int n;
long long int k=1;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  vector<bool> v(mx,1);
  for(int i=2;i*i<mx;i++){
   if(v[i]){
     for(int j=2*i;j<mx;j+=i){
       v[j]=0;
     }
   }
  }
  for (int i = 2; i < mx; i++) {
    if (v[i]) {
      long long int p=1;
      for (long long int j = i; j <= n; j *= i) {
        p*=i;
      }
      k=(k*p%4294967296);
    }
  }
  cout << k;
}