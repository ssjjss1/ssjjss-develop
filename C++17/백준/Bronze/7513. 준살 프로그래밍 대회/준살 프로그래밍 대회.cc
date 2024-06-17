#include<iostream>
#include<map>
using namespace std;
int t,n,m;
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>t;
  for(int i=1;i<=t;i++){
    cout<<"Scenario #"<<i<<":"<<"\n";
    cin>>n;
    map<int,string> ma;
    for(int j=0;j<n;j++) {
      string s;
      cin>>s;
      ma[j]=s;
    }
    cin>>m;
    while(m--){
      int x=0;
      cin>>x;
      for(int j=1,y;j<=x;j++){
        cin>>y;
        cout<<ma[y];
      }
      cout<<"\n";
    }
    cout<<"\n";
  }
}