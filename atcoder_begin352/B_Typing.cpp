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
    string s,t; cin>>s>>t;
    for(int i = 0 , j = 0 ; j < sz(t) ; j++){
        if(s[i] == t[j]){
            i++;
            cout<<j+1<<" ";
        }
    }
    return 0;
}
