#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e7 + 1;
const long long MOD = 1e9 + 7;

int n;
int A[MAX], B[MAX];
vector<int> primes;
bool visited[MAX];

long long multiply(long long x, int exp) {
    long long res = 1;
    while (exp) {
        if (exp % 2) res = (res * x) % MOD;
        x = (x * x) % MOD;
        exp /= 2;
    }
    return res;
}

void searchPrime() {
    for (int i = 2; i < MAX; i++) {
        if (!visited[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < MAX; j += i) {
                visited[j] = true;
            }
        }
    }
}

void findPrime(int x, int cnt[]) {
    for (auto i : primes) {
        if (i * i > x) break;
        while (x % i == 0) {
            cnt[i] += 1;
            x /= i;
        }
    }
    if (x > 1) cnt[x] += 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    searchPrime();

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        findPrime(b - a, A);
        findPrime(b, B);
    }

    long long ansA = 1, ansB = 1;
    for (int i = 2; i < MAX; i++) {
        int exp = A[i] - B[i];
        if (exp > 0) ansA = (ansA * multiply(i, exp)) % MOD;
        else if (exp < 0) ansB = (ansB * multiply(i, -exp)) % MOD;
    }

    cout << ansA << " " << ansB;
}