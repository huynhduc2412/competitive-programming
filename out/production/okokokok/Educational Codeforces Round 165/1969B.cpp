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
        string s; cin>>s;
        int n = sz(s);
        int i=0;
        ll ans=0;
        int cnt=0;
        while(i<n){
            int ch=i;
            while(ch<n&&s[ch]=='1') ch++,cnt++;
            if(ch==n) break;
            if(cnt) ans+=cnt+1;
            i=ch+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
