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
    string t; cin>>t;
    int j = 0;
    for(int i = 0 ; i < sz(s) ; i++){
        if(j < sz(t) && s[i] - 32 == t[j]){
            j++;
        }
    }
    if(j == sz(t)){
        cout<<"Yes"; return 0;
    }
    else if(j + 1 == sz(t)){
        if(t.back() == 'X') cout<<"Yes";
        else cout<<"No";
        return 0;
    }
    cout<<"No";
    return 0;
}
