#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define ll long long
#define REP(i,a) for(int i=0;i<a;++i)
#define REP1(i,a,b) for(int i=a;i<b;++i)
#define REP2(i,a,b) for(int i=a;i<=b;++i)
#define RREP(i,a) for(int i=a-1;i>=0;--i)
#define RREP1(i,a,b) for(int i=a;i>b;--i)
#define RREP2(i,a,b) for(int i=a;i>=b;--i)
#define SREP(i,x) for(auto i:x)
#define MS0(x) memset((x),0,sizeof((x)))
#define MS1(x) memset((x),-1,sizeof((x)))
#define MSF(x) memset((x),127,sizeof(x))
#define pb push_back
#define LE(x) (int)((x).size())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<D,D>
#define im guagua
#define RI(x) x=rit()
#define RII(a,b) a=rit(),b=rit()
#define RIII(a,b,c) a=rit(),b=rit(),c=rit()
#define debug 0
const int INF = 0x7F7F7F7F;
const double EPS = 1e-10 ;
const ll mod7 = 1e9+7;
const ll mod9 = 1e9+9;
using namespace std;
inline ll rit(){
    ll f=0,key=1;
    char c;
    do{
        c=getchar();
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
    }while(c>='0' && c<='9');
    return f*key;
}
inline void fprt(D f){
    printf("%.08lf",f);
}
void init(){
}
int n,m,q,cnt;
int rt[100005];
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
int mk[100005],a[100005],b[100005];
void read(){
    RIII(n,m,q);
    REP2(i,1,m){
        RII(a[i],b[i]);
    }
}
void solve(){
    REP(j,q){
        mk[rit()] = 1;
        REP2(i,1,n) rt[i] = i;
        cnt = n;
        REP2(i,1,m){
            if(!mk[i]){
                go(a[i],b[i]);
            }
        }
        cout<<cnt<<endl;
    }


}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        // while(cin>>n) 
            init(),read(),solve();
    }
    return 0;
}