#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define coutvc(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
const int mxN=2e5;
using namespace std;
void Solve(){
    int n;cin>>n;
    ll Q[n];inp(Q);
    ll A[n];inp(A);
    ll B[n];inp(B);
    ll res=0;
    for(ll t=0;t<=1e6;t++){
        ll j=LLONG_MAX;
        for(int i=0;i<n;i++){
            ll c=Q[i]-t*A[i];
            if(c<0){
                cout<<res;return;
            }
            if(!B[i]){
                continue;
            }
            j=min(j,c/B[i]);
        }
        if(j==LLONG_MAX) j=0;
        res=max(res,t+j);
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

    int test;
    test=1;
    // cin>>test;
    for(int o=0;o<test;o++){
        Solve();
        cout<<"\n";
    }
    return 0;
}
