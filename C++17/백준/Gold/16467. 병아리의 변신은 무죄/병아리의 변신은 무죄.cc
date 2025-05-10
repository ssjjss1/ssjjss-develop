#include <bits/stdc++.h>
using namespace std;

const long long MOD = 100000007;

vector<vector<long long>> multiply(vector<vector<long long>> A, vector<vector<long long>> B) {
	int size = A.size();
	vector<vector<long long>> res(size, vector<long long>(size, 0));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
			}
		}
	}
	return res;
}

vector<vector<long long>> power(vector<vector<long long>> A, long long exp) {
	int size = A.size();
	vector<vector<long long>> res(size, vector<long long>(size, 0));
	for (int i = 0; i < size; i++) res[i][i] = 1;

	while (exp) {
		if (exp % 2) res = multiply(res, A);
		A = multiply(A, A);
		exp /= 2;
	}
	return res;
}

long long power_mod(long long B, long long exp) {
	long long res = 1;
	while (exp) {
		if (exp % 2) res = (res * B) % MOD;
		B = (B * B) % MOD;
		exp /= 2;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int k;
		long long n;
		cin >> k >> n;

		if (k == 0) {
			cout << power_mod(2, n) << "\n";
			continue;
		}

		if (n <= k) {
			cout << 1 << "\n";
			continue;
		}

		vector<vector<long long>> matrix(k + 1, vector<long long>(k + 1, 0));
		
		matrix[0][0] = 1;
		matrix[0][k] = 1;

		for (int i = 1; i <= k; i++) matrix[i][i - 1] = 1;

		vector<vector<long long>> ans = power(matrix, n - k);

		long long res = 0;
		for (int i = 0; i <= k; i++) {
			res = (res + ans[0][i]) % MOD;
		}
		cout << res << "\n";
	}
}