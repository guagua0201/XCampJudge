#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define D double
#define ll long long
#define MS0(x) memset((x),0,sizeof((x)));
#define MS1(x) memset((x),-1,sizeof((x)));
#define MSF(x) memset((x),127,sizeof(x));
#define pb push_back
#define LE(x) (int)((x).length())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<D,D>
#define im guagua
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
void init(){
}
const int Z = 100005;
int n,r;
ll ans;
int a[Z],b[Z];
void mgsrt(int l,int r){
    int mid = (l+r)/2,i,j,k;
    if(l==r) return ;
    mgsrt(l,mid);
    mgsrt(mid+1,r);
    for(i=k=l,j=mid+1;i<=mid && j<=r;k++){
        if(a[i] <= a[j]){
            b[k] = a[i++];
        }
        else{
            b[k] = a[j++];
            ans+=mid-i+1;
        }
    }
    for(;i<=mid;i++,k++){
        b[k] = a[i];
    }
    for(;j<=r;j++,k++){
        b[k] = a[j];
    }
    for(i=l;i<=r;i++) a[i] = b[i];

    // cout<<"srt "<<l<<" ~ "<<r<<endl;
    // for(i=0;i<n;i++) cout<<a[i]<<' ';
    // cout<<endl;
}
void read(){
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        a[i] = rit();
    }
}
void solve(){
    ans = 0;
    mgsrt(0,n-1);
    cout<<ans<<endl;
}
int main(){
    int nn=1;
    // nn=rit();
    init();
    while(nn--){
        read();
        solve();
    }
    return 0;
}