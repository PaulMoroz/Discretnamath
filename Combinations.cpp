#include <bits/stdc++.h>
using namespace std;
int C (int n, int k)
{
  if (k == 0 || n == k)
    return 1;
  return C (n - 1, k - 1) + C (n - 1, k);
}
int main ()
{
  int n, k, x, y;
  cout<<"Enter x, y and power of action\n";
  cin>>x>>y>>n;
  if(x==0 && y==0)
    cout<<0;
  else
  if(x==0){
    cout<<pow(y,n)<<"y^"<<n;
  }
  else
    if(x==0)cout<<pow(y,n)<<"y^"<<n;
  else{
    cout<<pow(x,n)<<"x^"<<n;
    for(int i = 1 ;i < n; i++){
        int coef = pow(x,n-i) * pow(y,i) * C(n,i);
        if(coef>0)cout<<'+';
        if(abs(coef)!=1)cout<<coef;
        if(coef==-1)cout<<'-';
        cout<<"x^"<<n-i<<"*y^"<<i;

    }
    if(pow(y,n)>0)cout<<'+';
    if(pow(y,n)==-1)cout<<'-';
    if(abs(pow(y,n))!=1)cout<<pow(y,n);

    cout<<"y^"<<n;
  }
}
