#include<iostream>
#include<string>
using namespace std;
int n;
int a[100];
string s = "Messi Gimossi";
void f(int x,int cnt) {
	if (x <= 13) {
		if (x==6) cout<<"Messi Messi Gimossi";
		else cout<<(s[x - 1]);
		return;
	}
	if (x > a[cnt]) f(x, cnt - 1);
	else if (x <= a[cnt]) {
		if (x - a[cnt - 1] - 1 < 0) f(x, cnt - 1);
		else if (x - a[cnt - 1] - 1 == 0) {
			cout << "Messi Messi Gimossi";
			return;
		}
		else f(x - a[cnt - 1] - 1, cnt - 2);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	a[0] = 5, a[1] = 13;
	for (int i = 2; i <= 39; i++) {
		a[i] = a[i - 1] + a[i - 2] + 1;
	}
	f(n,39);
}