#include<iostream>
#include<vector>
using namespace std;
int n;
void f(vector<int> v, vector<int> v1,int cnt, int size){
  if(size==6) {
    for(auto i:v1) cout<<i<<" ";
    cout<<"\n";
    return;
  }
  for(int i=cnt;i<=n;i++) {
    v1.push_back(v[i]);
    f(v,v1,i+1,size+1);
    v1.pop_back();
  }
}
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  while(true){
    cin>>n;
    if(n==0) break;
    vector<int> v(n+4,0);
    vector<int> v1;
    for(int i=1;i<=n;i++) cin>>v[i];
    f(v,v1,1,0);
    cout<<"\n";
  }
}