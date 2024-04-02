#include <iostream>
#include <vector>
#include <algorithm>
long long int n;
using namespace std;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  vector<long long int> v;
  for (int i=0;i<n;i++){
    long long int t;
    cin>>t;
    v.push_back(t);
  }
  vector<long long int> m(n);
  for(int i=0;i<n;i++){
    double p=-1000000000;
    for(int j=i+1;j<n;j++){
      long long int x=v[j]-v[i];
      long long int y=j-i;
      double g=double(x)/double(y);
      if(g<=p){
        continue;
      }
      else{
        p=g;
        m[i]++;
        m[j]++;
      }
    }
  }
  cout<<*max_element(m.begin(),m.end());
}