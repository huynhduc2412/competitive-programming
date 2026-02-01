#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repv(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
const int mxN=2e5;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,t ; cin>>s>>t;
    int n = sz(s);
    rep(i,1,n) {
        vector<string>list;
        for(int j = 0 ; j < n ; j += i){
            list.push_back(s.substr(j,i));
        }
        rep(j,0,i){
            string c;
            for(string x : list) {
                if(sz(x) <= j) {
                    break;
                }
                c += x[j];
            }
            if(c == t) {
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
