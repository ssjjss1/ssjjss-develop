#include<iostream>
using namespace std;
int t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        int n,m;
        int mx1=0,mx2=0;
        cin>>n>>m;
        while(n--){
            int x;
            cin>>x;
            mx1=max(mx1,x);
        }
        while(m--){
            int x;
            cin>>x;
            mx2=max(mx2,x);
        }
        if(mx1<mx2)cout<<"B"<<"\n";
        else cout<<"S"<<"\n";
    }
}