#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> adj[300004];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1), idxA(n + 1);
	for(int i=2; i <= n; i++) {
		int v;
		cin >> v;
		adj[v].push_back(i);
	}

	for(int i=1; i <= n; i++) {
		cin >> a[i];
		idxA[a[i]]=i;
	}
	
	pq.push(a[1]);
	while(!pq.empty()){
	      int x=pq.top();
	      pq.pop();
	      
	      cout<<x<<"\n";
	      int idx=idxA[x];
	      for(auto v:adj[idx]){
	            pq.push(a[v]);
	      }
	}
}