#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
vector<int> v[1004];
vector<int> v3[1004];
map<string, int> ma;
vector<string> v1;
vector<int> v2;
vector<int> a(1004,0);
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int n1=n;
    while (n--) {
        string s;
        cin >> s;
        v1.push_back(s);
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<n1;i++) ma[v1[i]]=i;
    cin >> m;
    while (m--) {
        string s1, s2;
        cin >> s1 >> s2;
        v[ma[s2]].push_back(ma[s1]);    
        a[ma[s1]]+=1;
    }
    queue<int> q;
    for(int i=0;i<n1;i++){
        if(!a[i]){
            q.push(i);
            v2.push_back(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto i:v[x]){
            if(!--a[i]){
                q.push(i);
                v3[x].push_back(i);
            }
        }
    }
    cout<<v2.size()<<"\n";
    for(auto i:v2) cout<<v1[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n1;i++){
        cout<<v1[i]<<" "<<v3[i].size()<<" ";
        sort(v3[i].begin(),v3[i].end());
        for(auto j:v3[i]) cout<<v1[j]<<" ";
        cout<<"\n";
    }
}