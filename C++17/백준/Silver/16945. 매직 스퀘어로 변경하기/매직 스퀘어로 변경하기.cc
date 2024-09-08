#include<iostream>
using namespace std;
int d[4][4],a[8][3][3]={{{8,1,6},{3,5,7},{4,9,2}},{{6,1,8},{7,5,3},{2,9,4}},{{4,9,2},{3,5,7},{8,1,6}},{{2,9,4},{7,5,3},{6,1,8}},{{8,3,4},{1,5,9},{6,7,2}},{{4,3,8},{9,5,1},{2,7,6}},{{6,7,2},{1,5,9},{8,3,4}},{{2,7,6},{9,5,1},{4,3,8}}};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)cin>>d[i][j];
    int mn=1e9;
    for(int k=0;k<8;k++){
        int c=0;
        for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)c+=abs(d[i][j]-a[k][i-1][j-1]);
        mn=min(mn,c);
    }
    cout<<mn;
}