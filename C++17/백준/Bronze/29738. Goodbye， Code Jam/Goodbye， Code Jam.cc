#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
     ios::sync_with_stdio(0);
     cin.tie(0);
     cin>>t;
     
     int test=1;
     while(t--){
           int n;
           cin>>n;
           
           cout<<"Case #"<<test++<<": ";
           if(n<=25) cout<<"World Finals\n";
           else if(n<=1000) cout<<"Round 3\n";
           else if(n<=4500) cout<<"Round 2\n";
           else cout<<"Round 1\n";
     }
}