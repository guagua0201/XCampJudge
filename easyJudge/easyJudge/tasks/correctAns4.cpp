#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int n,m,q,cnt;
int rt[100005];
int L[1000005],R[1000005],D[1000005];
char mk[1000005];
inline int rit(){
    int x;
    scanf("%d",&x);
    return x;
}
void read(){
    int i;
    n=rit(),m=rit();
    q=rit();
    for(i=1;i<=n;i++) rt[i]=i;
    for(i=1;i<=m;i++){
        L[i]=rit(),R[i]=rit();
        mk[i]=0;
    }
    for(i=0;i<q;i++){
        D[i]=rit();
        mk[D[i]]=1;
    }
}
inline int findroot(int x){
    if(rt[x]==x) return x;
    rt[x]=findroot(rt[x]);
    return rt[x];
}
inline void go(int a,int b){
    a=findroot(a);
    b=findroot(b);
    if(a!=b){
        rt[a]=b;
        cnt--;
    }
}
void solve(){
    int i,f;
    cnt=n;
    for(i=1;i<=m;i++)
        if(!mk[i]) go(L[i],R[i]);
    for(i=q-1;i>=0;i--){
        f=D[i];
        D[i]=cnt;
        go(L[f],R[f]);
    }
    for(i=0;i<q;i++) printf("%d\n",D[i]);
}
int main(){
    read();
    solve();
    return 0;
}