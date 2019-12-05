#include <iostream>
#include <cstdio>
using namespace std;
int n,i,j,a[101][101],b[101],c[101]={0},x,y,from[102]={0},m,w,s,f;
void dejkstra(int v)
{
c[v]=1;
for(i=0;i<n;i++)
if(a[v][i]!=-1 && c[i]==0 && v!=i)
{
if(b[v]+a[v][i]<b[i]){
b[i]=min(b[i],b[v]+a[v][i]);from[i] = v;}
}
}
int min_ar()
{
int min=1000000,nm=-1;
for(i=0;i<n;i++)
if(min>b[i] && c[i]==0){min=b[i];nm=i;}
return nm;
}

int out(int v){
    return from[v];
}

int main()
{

cout<<"Enter number of tops and edges, start and finish tops\n";

cin>>n>>m>>x>>y;
cout<<"Enter list of edges\n";
cout<<n;
for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++)
        a[i][j] = -1;
    b[i] = INT_MAX;
}
for(int i=1;i<=m;i++){
    cin>>s>>f>>w;
    a[s][f] = w;
    a[f][s] = w;
}
if(a[x][y]==0){cout<<0;return 0;}

b[x]=0;
int t=1;
while(t==1)
{
t=0;
int v=min_ar();
if(c[v]==0 && v>=0 ) {dejkstra(v); t=1;}
}

cout<<"The shortest way: "<<b[y]<<endl;
cout<<"Tops on the shortest way: ";
 int curr = y;
 int path[n*n] = {0},sz = 0;
 while(curr!=x){
    path[sz] = curr;
    sz++;
    curr = out(curr);
 }
 for(int i=sz-1;i>=0;i--)
    cout<<path[i]<<' ';
}
