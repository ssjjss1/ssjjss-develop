#include<iostream>
using namespace std;
int n, k;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int y = 0, cnt = 0;
	while (n--) {
		int x;
		cin >> x;
		if (y == 0) y = x;
		else if (x - y == k) y=0, cnt += 1;
		else if (x - y > k) y = x, cnt += 1;
	}
	cout << (y!=0?cnt+=1:cnt);
}