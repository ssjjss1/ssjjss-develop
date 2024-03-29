#include<iostream>

using namespace std;

int n;

int x;

long long int b[1000004];

int main(){

  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  cin>>n;

  for(int i=1;i<=1000001;i++){

    for(int j=i;j<=1000001;j+=i){

      b[j]+=i;

    }

  }

  for(int i=2;i<=1000000;i++){

    b[i]+=b[i-1];

  }

  while(n--){

    cin>>x;

    cout<<b[x]<<"\n";

  }

}