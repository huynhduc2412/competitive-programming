#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define coutvc(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
const int mxN=2e5;
using namespace std;
ll val[mxN+1];
void Solve(){
        int n,m;cin>>n>>m;
        ll a[m]; inp(a);
        ll ans=0;
        for(int i=1;i<m;i++){
            ll u=a[i-1],v=a[i];
            if(u>v) swap(u,v);
            ll l=v-u,r=n-l;
            if(l<=r){
                ans+=l;
                r-=l;
                val[u]+=r;
                val[v]-=r;
            }else{
                ans+=r;
                l-=r;
                val[1]+=l;
                val[u]-=l;
                val[v]+=l;
            }
        }
        ll res=LLONG_MAX;
        for(int i=1;i<=n;i++){
            val[i]+=val[i-1];
            res=min(res,ans+val[i]);
        }
        cout<<res;
}   
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int test=1;
    // cin>>test;
    for(int o=0;o<test;o++){
        Solve();
        cout<<"\n";
    }
    return 0;
}
