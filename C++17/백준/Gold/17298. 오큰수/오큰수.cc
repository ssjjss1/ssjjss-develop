#include <iostream>
#include<stack>
using namespace std;
long long int n;
long long int a[10000001],b[10000001];
stack<int> v;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  fill(&b[0],&b[0]+1000001,-1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
    while(v.size()&&a[v.top()]<a[i]){
      b[v.top()]=a[i];
      v.pop();
    }
    v.push(i);
  }
  for(int i=1;i<=n;i++) cout<<b[i]<<" ";
}