#include<bits/stdc++.h>
using namespace std;
int n, m, sum;
vector<int> v, v1;
struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    n *= 24;
    for (int i = 1, x; i <= m; i++) cin >> x, v.push_back(100-x), sum += x;
    for (int i = 1, x; i <= m; i++) cin >> x, v1.push_back(x);
   
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // 함수 
    for (int i = 0; i < m; i++) pq.push({v1[i], v[i]});
    while(!pq.empty()&&n){
          auto [x,y]=pq.top();pq.pop();
          if(x<=y){
                sum+=x;
                pq.push({x,y-x});
                n-=1;
          }else{
                pq.push({y,y});
          }
    }
    cout<<sum;
}