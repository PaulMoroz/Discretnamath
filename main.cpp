#include <bits/stdc++.h>
using namespace std;
 int ways[14], a[14][14],vis[14] = {0},tops[14] = {0},topNumb = 0,val,s,f;
int min_array(int n){
    int min = INT_MAX, nmin = 0;
    for(int i=1;i<=n;i++){
        if(ways[i]<min && vis[i]==0){
            min = ways[i];nmin = i;
        }
    }
    return  nmin;
}
int main() {
    int n,m;

    cout<<"Enter amount of tops and edges of graph\n";
    cin>>n>>m;
    cout<<"Enter number of start top,end top and edge weight between them\n";
    for(int i=1;i<=20;i++)
        ways[i] = INT_MAX;
    for(int i = 1;i<=m;i++){
        cin>>s>>f>>val;
        a[s][f] = val;
        a[f][s] = val;
    }
    ways[1] = 0;
    int current = 1;
    while(current!=0){
        vis[current] = 1;
        for(int i=1;i<=n;i++){
            if(a[current][i]!=0 && vis[i] ==0  )ways[i] = min(ways[i], a[current][i]);
        }
        topNumb ++;
        tops[topNumb] = current;
        current = min_array(n);
    }
    cout<<"The order of tops after algorithm passing\n";
    int sum = 0;
    for(int i=1;i<n;i++){
        sum += ways[i];
        cout<<tops[i]<<" -> ";
    }
    cout<<tops[n];
    cout<<"\nLength of minimal frame: "<<sum + ways[n];
}
