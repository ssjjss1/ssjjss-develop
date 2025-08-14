#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    int s=m;
    int idx=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<=s) s-=x;
        else {
            s=m-x;
            idx+=1;
        }
        cout<<idx<<"\n";
    }
}