// #include<iostream>
// using namespace std;
// int n;
// string s;
// char c[54][54];
// void f1(){
//   for(int i=2;i<n+2;i++) c[i][1]='|';
//   for(int i=n+3;i<2*n+3;i++) c[i][1]='|';
// }
// void f2(){
//   for(int i=2;i<=n+1;i++) c[1][i]='-';
// }
// void f3(){
//   for(int i=2;i<=n+1;i++) c[n+2][i]='-';
// }
// void f4(){
//   for(int i=2;i<=n+1;i++) c[2*n+3][i]='-';
// }
// void f5(){
//   for(int i=2;i<n+2;i++) c[i][n+2]='|';
//   for(int i=n+3;i<2*n+3;i++) c[i][n+2]='|';
// }
// int main(){
//   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//   cin>>n>>s;
//   for(auto i:s){
//     fill(&c[0][0],&c[0][0]+54*54,' ');
//     if(i=='0'){
//       f1(),f2(),f4(),f5();
//     }
    
//     for(int i=1;i<=2*n+3;i++){
//       for(int j=1;j<=n+2;j++){
//         cout<<c[i][j];
//       }
//       cout<<"\n";
//     }
//   }
// }
#include<iostream>
using namespace std;
int n;
string s;
char c[54][54];
void f1() { 
    for(int i = 2; i < n + 2; i++) c[i][1] = '|';
}
void f2() { 
    for(int i = n + 3; i < 2 * n + 3; i++) c[i][1] = '|';
}
void f3() { 
    for(int i = 2; i <= n + 1; i++) c[1][i] = '-';
}
void f4() { 
    for(int i = 2; i <= n + 1; i++) c[n + 2][i] = '-';
}
void f5() {
    for(int i = 2; i <= n + 1; i++) c[2 * n + 3][i] = '-';
}
void f6() { 
    for(int i = 2; i < n + 2; i++) c[i][n + 2] = '|';
}
void f7() { 
    for(int i = n + 3; i < 2 * n + 3; i++) c[i][n + 2] = '|';
}
void g(char digit) {
    fill(&c[0][0], &c[0][0] + 54 * 54, ' ');

    if (digit == '0') {
        f1(); f2(); f3(); f5(); f6(); f7();
    } else if (digit == '1') {
        f6(); f7();
    } else if (digit == '2') {
        f3(); f6(); f4(); f2(); f5();
    } else if (digit == '3') {
        f3(); f4(); f5(); f6(); f7();
    } else if (digit == '4') {
        f1(); f4(); f6(); f7();
    } else if (digit == '5') {
        f1(); f3(); f4(); f5(); f7();
    } else if (digit == '6') {
        f1(); f2(); f3(); f4(); f5(); f7();
    } else if (digit == '7') {
        f3(); f6(); f7();
    } else if (digit == '8') {
        f1(); f2(); f3(); f4(); f5(); f6(); f7();
    } else if (digit == '9') {
        f1(); f3(); f4(); f5(); f6(); f7();
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int l = 1; l <= 2 * n + 3; l++) {
        for (int i = 0; i < s.length(); i++) {
            g(s[i]);
            for (int j = 1; j <= n + 2; j++) cout << c[l][j];
            if (i < s.length() - 1) cout << " ";
        }
        cout << "\n";
    }
}