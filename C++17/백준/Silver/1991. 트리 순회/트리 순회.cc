#include <iostream>
#include <vector>
using namespace std;
int n;
char c1, c2, c3;
vector<int> v[100];
void f(char x) {
	if (x == '.')return;
	cout << x;
	f(v[x - 'A'][0]);
	f(v[x - 'A'][1]);
}
void g(char x) {
	if (x == '.')return;
	g(v[x - 'A'][0]);
	cout << x;
	g(v[x - 'A'][1]);
}
void h(char x) {
	if (x == '.') return;
	h(v[x - 'A'][0]);
	h(v[x - 'A'][1]);
	cout << x;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c1 >> c2 >> c3;
		v[c1 - 'A'].push_back(c2);
		v[c1 - 'A'].push_back(c3);
	}
	f('A');
	cout << '\n';
	g('A');
	cout << '\n';
	h('A');
}