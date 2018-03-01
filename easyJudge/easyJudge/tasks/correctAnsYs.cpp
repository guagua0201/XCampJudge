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
const int Z = 100005;
int n,m;
vector<PII> v[Z],rv[Z];
int ans[Z],st,ed,mk[Z];
vector<int> from[Z];
struct srt{
    bool operator()(const int &a,const int &b){
        return ans[a] > ans[b];
    }
};
void read(){
    RII(n,m);
    REP(i,m){
        int a,b,f;
        RIII(a,b,f);
        v[a].pb(mp(b,f));
        rv[b].pb(mp(a,f));
    }
    RII(st,ed);   
}
priority_queue<int,vector<int>,srt> pq;
vector<int> ansv;
void solve(){
    REP2(i,1,n) ans[i] = INF;
    ans[st] = 0;
    pq.push(st);
    while(!pq.empty()){
        int now;
        now = pq.top();
        pq.pop();
        if(mk[now]) continue;
        SREP(f,v[now]){
            if(ans[f.X] > ans[now] + f.Y){
                ans[f.X] = ans[now] + f.Y;
                from[f.X].clear();
                from[f.X].pb(now);
                pq.push(f.X);
            }
            else if(ans[f.X] == ans[now] + f.Y){
                from[f.X].pb(now);
            }
        }
    }
    if(ans[ed] == INF) {
        cout<<-1<<endl;
    }
    else{
        cout<<ans[ed]<<endl;
        // int now = ed;
        // while(now!=st){
        //     ansv.pb(now);
        //     SREP(f,rv[now]){
        //         if(ans[f.X] + f.Y == ans[now]){
        //             now = f.X;
        //             break;
        //         }
        //     }
        // }
        // ansv.pb(1);
        // reverse(ALL(ansv));
        // cout<<ansv[0];
        // for(int i=1;i<LE(ansv);i++){
        //             cout<<"->"<<ansv[i];
        // }
        // cout<<endl;
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