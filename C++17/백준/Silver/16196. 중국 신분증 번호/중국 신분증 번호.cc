#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string s1, s3, s4;
string s2Y, s2M, s2D;
int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
long long sum = 0;
vector<string> v;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 18; i++) {
		char x;
		cin >> x;
		if (i <= 6) s1 += x;
		else if (i <= 10) s2Y += x;
		else if (i <= 12) s2M += x;
		else if (i <= 14) s2D += x;
		else if (i <= 17) s3 += x;
		else s4 += x;
	}
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	if (find(v.begin(), v.end(), s1) == v.end()|| "1900" > s2Y || "2011" < s2Y || "01" > s2M || "12" < s2M || !stoi(s3)) {
		cout << "I" << "\n";
		return 0;
	}
	int k = 0;
	if (stoi(s2M) == 2 && (stoi(s2Y) % 4 == 0 && stoi(s2Y) % 100 != 0 || stoi(s2Y) % 400 == 0)) {
		k = day[stoi(s2M)] + 1;
	}
	else k = day[stoi(s2M)];
	if (stoi(s2D) < 1 || stoi(s2D) > k) {
		cout << "I";
		return 0;
	}
	string s = s1 + s2Y + s2M + s2D + s3;
	sum += (s4 == "X" ? 10 : stoi(s4));
	for (int i = 0; i < 17; i++) {
		sum += (pow(2, 17 - i) * (s[i] - '0'));
	}
	if((sum%11)!=1) cout << "I" << "\n";
	else cout << (stoi(s3) % 2 ? "M" : "F");
}