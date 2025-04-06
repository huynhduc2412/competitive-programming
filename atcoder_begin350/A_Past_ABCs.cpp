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
    string s; cin>>s;
    if(s.substr(0,3) != "ABC"){
        cout<<"No";
    }
    int c = stoi(s.substr(3,3));
    if(c > 349 || c == 316 || c == 0) cout<<"No";
    else cout<<"Yes";
    return 0;
}
