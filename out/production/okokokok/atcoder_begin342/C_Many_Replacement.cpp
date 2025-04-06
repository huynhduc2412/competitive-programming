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
    int n; cin>>n;
    string s; cin>>s;
    unordered_map<char,char>mp;
    int q; cin>>q;
    array<char,2>a[q];
    rep(i,0,q) cin>>a[i][0]>>a[i][1];
    reverse(a,a+q);
    rep(i,0,q){
        if(mp.find(a[i][1])==mp.end()){
            mp[a[i][0]] = a[i][1];
        }else{
            mp[a[i][0]] = mp[a[i][1]];
        }
    }
    rep(i,0,n){
        if(mp.find(s[i])!=mp.end()) cout<<mp[s[i]];
        else cout<<s[i];
    }
    return 0;
}
