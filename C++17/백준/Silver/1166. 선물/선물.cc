#include <iostream>
using namespace std;
long long int n,l,w,h;
double a;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>l>>w>>h;
  double m=0;
  double k=max(l,max(w,h));
  for (int i=1;i<10000;i++) {
    long double s=(m+k)/2;
    if(((long long int)(l/s))*((long long int)(w/s))*((long long int)(h/s))>=n) { 
      m=s;
    }
    else {
      k=s;
    }
  }
  printf("%.10lf",m);
}