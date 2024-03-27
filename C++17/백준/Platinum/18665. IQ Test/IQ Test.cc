#include <iostream>

#include<set>

#include<cmath>

#include<cassert>

using namespace std;

typedef long long ll;

ll cnt = 0;

set<pair<ll,ll>> s;

void f(ll n) {

    ll x, y;

    x = sqrt(n);

    if (n > x * x) x+=1;

    y = x * x - n;

    auto k = s.find({ x,y });

    if (k == s.end()) {

        if (x > 2) f(x);

        if (y > 2) f(y);

      cnt++;assert(cnt<=43);

       cout<<x<<" "<<y<<"\n";

       s.insert({ x, y });

    }

}

int main() {

    ll n; 

    cin >> n;

    f(n);

}