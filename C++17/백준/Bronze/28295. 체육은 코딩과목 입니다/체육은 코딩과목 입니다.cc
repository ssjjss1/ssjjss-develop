#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int sum=0;
    for(int i=0;i<10;i++){
        int x;
        cin>>x;
        
        sum+=x;
    }

    cout<<(sum%4==0?"N":(sum%4==1?"E":(sum%4==2?"S":"W")));
}