#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<string> v;
vector<string> v1;
bool compare(string x, string y){
    if(x.size()!=y.size()) return x.size()>y.size();
    return x>y;
}
bool compare1(string x, string y){
    return x+y>y+x;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int p=n;
    while(p--){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<(m-n+1);i++) v1.push_back(v[0]);
    for(int i=1;i<v.size();i++) v1.push_back(v[i]);
    sort(v1.begin(),v1.end(),compare1);
    for(auto i:v1) cout<<i;
}