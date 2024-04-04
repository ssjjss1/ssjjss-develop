#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  vector<long long int> v(n);
  for(long long int i=0;i<n;i++){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  for(long long int i=0;i<n;i++){
    cout<<v[i]<<"\n";
  }
}