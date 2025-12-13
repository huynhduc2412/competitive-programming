#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const int mxN=2e5;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q; cin>>q;
    while(q--){
        int n,k; cin>>n>>k;
        array<int,2>a[n];
        rep(i,0,n) cin>>a[i][1];
        rep(i,0,n) cin>>a[i][0];
        sort(a,a+n,greater<>());
        ll s=0,sA=0,ans=0;
        rep(i,0,n) s+=max(a[i][0]-a[i][1],0);
        priority_queue<int>pq;
        rep(i,0,n){
            if(i>=k) ans=max(ans,s-sA);
            s-=max(a[i][0]-a[i][1],0);
            sA+=a[i][1];
            pq.push(a[i][1]);
            if(sz(pq)>k) sA-=pq.top(),pq.pop();
        }
        ans=max(ans,s-sA);
        cout<<ans<<'\n';
    }
    return 0;
}
