 #include<iostream>
 #include<vector>
 using namespace std;
 int n,m;
 vector<int> v;
 void f(int x, int cnt){
   if(cnt>m){
     for(auto i:v){
       cout<<i<<" ";
     }
     cout<<"\n";
     return;
   }
   for(int i=1;i<=n;i++){
     bool flag=false;
     for(auto j:v){
       if(i<=j){
         flag=true;
         break;
       }
     }
     if(flag) continue;
     v.push_back(i);
     f(i,cnt+1);
     v.pop_back();
   }
 }
 int main(){
   ios::sync_with_stdio(0);
   cin>>n>>m;
   f(1,1);
 }