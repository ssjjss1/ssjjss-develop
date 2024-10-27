#include<bits/stdc++.h>
using namespace std;
int n, cnt=0;
string s;
vector<int> v;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s;
        int x = stoi(s.substr(0, 2)), y = stoi(s.substr(3, 2));
        v.push_back(x*60 + y);
    }
    sort(v.begin(), v.end());
    int i=0;
    while(i<n){
        int t = v[i], j=i;
        while(j<n && j<i+3 && abs(v[j]-t)<=10) j++;
        cnt+=1;
        i=j;
    }
    cout << cnt;
}