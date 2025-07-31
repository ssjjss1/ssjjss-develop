#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    cin>>x>>y;

    int a=100-x, b=100-y;
    int c=100-a-b, d=a*b;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d/100<<" "<<d%100<<"\n";
    if(d/100) cout<<c+d/100<<" "<<d%100;
    else cout<<c<<" "<<d;
}