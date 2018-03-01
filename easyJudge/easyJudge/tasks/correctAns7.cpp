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
int n,s;
int val[8] = {1,5,10,50,100,200,500,1000};
int coin[8] = { 1,1,1,1,0,0,0,0};
int a[100],b[100];
int dp[100][20005],totalCoin,totalOwn;
inline int ask(int x){
    int ans = 0;
    RREP(i,8){
        while(x>=val[i]){
            x-=val[i];
            ans+=coin[i];
        }
    }
    return ans;
}
void read(){
    RI(s);
    n = 1;
    REP(i,8){
        int f;
        RI(f);
        REP(j,f){
            b[n] = coin[i];
            totalCoin+=coin[i];
            totalOwn+=val[i];
            a[n++] = val[i];
        }
    }
}
void solve(){
    if(totalOwn < s) {
        cout<<-1<<endl;
        return ;
    }
    REP(i,100) REP(j,20005) dp[i][j] = 1000000000;
    dp[0][0] = 0;
    REP2(i,1,n){
        dp[i][0] = 0;
        REP2(j,1,20000){
            if(j>=a[i]){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    int ans = INF;
    REP2(i,s,20000){
        if(dp[n][i]<10000){
            ans = min(ans,ask(i-s)+(totalCoin-dp[n][i]));
        }
    }
    cout<<ans<<endl;
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