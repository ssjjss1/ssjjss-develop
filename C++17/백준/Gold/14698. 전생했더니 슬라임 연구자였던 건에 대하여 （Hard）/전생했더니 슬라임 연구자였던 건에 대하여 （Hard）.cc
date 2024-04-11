#include <iostream>

#include <queue>

#include <algorithm>

using namespace std;

const long long int m = 1000000007;

int t,n;

long long int k;

int main() {

  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> t;

    while(t--){

        cin >> n;

        priority_queue<long long int,vector<long long int >,greater<long long int >> q;

        for (int i = 1; i <= n; i++) {

            cin >> k;

            q.push(k);

        }

        long long int sum=1;

        while (q.size()!=1) {

             long long int a,b;

             a=q.top(); 

             q.pop();

             b=q.top(); 

             q.pop();

            sum *= (((a % m) * (b % m)) % m);

            sum%=m;

            q.push(a * b);    

        }

    cout << sum << "\n";

    }

}