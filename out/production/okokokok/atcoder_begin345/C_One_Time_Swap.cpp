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
int cnt[26];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin>>s;
    for(char x : s) cnt[x-'a']++;
    ll s2 = 0;
    rep(i,0,26) s2+=cnt[i];
    ll res = 0, s1 = 0;
    rep(i,0,26){
        if(!cnt[i]) continue;
        ll c = (s2 - s1 - cnt[i]);
        res += cnt[i] * c;
        s1 += cnt[i];
    }
    rep(i,0,26) if(cnt[i] > 1){
        res++;break;
    }
    cout<<res;
    return 0;
}
