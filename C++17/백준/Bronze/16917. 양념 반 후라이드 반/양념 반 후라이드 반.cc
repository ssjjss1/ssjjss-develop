#include<iostream>
using namespace std;
int a,b,c,x,y;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>x>>y;
    c*=2;
    int mn=1e9+4;
    for(int i=0;i<=max(x,y);i++){
        mn=min(mn, a*(x-i>0?x-i:0)+b*(y-i>0?y-i:0)+c*i); 
    }
    cout<<mn;
}