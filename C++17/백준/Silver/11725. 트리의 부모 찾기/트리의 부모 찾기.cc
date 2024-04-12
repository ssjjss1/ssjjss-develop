#include<iostream>
#include<vector>
using namespace std;
int n;
int x, y;
int visited[100001];
int b[100001];
vector<int> v[100001];
void f(int a) {
	visited[a] = 1;
	if (v[a].empty()) return;
	for (int i = 0; i < v[a].size(); i++) {
		if(!visited[v[a][i]])
			f(v[a][i]);
		b[v[a][i]] = a;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i ++ ) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	f(1);
	for (int i = 2; i <= n; i++) {
		cout << b[i] << "\n";
	}
}