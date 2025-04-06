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
int cnt[26] , cnt1[101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin>>s;
    rep(i,0,sz(s)) cnt[s[i] - 'a']++;
    rep(i,0,26){
        cnt1[cnt[i]]++;
    }
    rep(i,1,101){
        if(cnt1[i] == 2 || !cnt1[i]) continue;
        cout<<"No"; return 0;
    }
    cout<<"Yes";
    return 0;
}
