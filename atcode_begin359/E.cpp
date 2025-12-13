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
    int n; cin>>n;
    ll h[n] ; inp(h);
    vector<array<ll,2>>st;
    vector<ll>ans(n + 1 , 0);
    st.push_back({h[0] , 1});
    ans[0] = h[0];
    rep(i,0,n){
        int cnt = 0;
        while(!st.empty() && st.back()[0] < h[i]){
            auto [H , CNT] = st.back(); st.pop_back();
            ans[i + 1] += (CNT * h[i]) - (CNT * H);
            cnt += CNT;
        }
        ans[i + 1] += ans[i] + 1;
        if(cnt > 0) st.push_back({h[i] , cnt});
        st.push_back({1 , 1});   
    }
    rep(i,1,n+1) cout<<ans[i]<<" ";
    return 0;
}



