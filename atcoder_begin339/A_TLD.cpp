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
void Solve(){
        string s; cin>>s;
        string res;
        for(int i=sz(s)-1;i>=0;i--){
            if(s[i]=='.') break;
            res+=s[i];
        }
        reverse(all(res));
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
