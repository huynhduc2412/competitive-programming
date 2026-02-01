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
    int a[n] , w[n];
    vector<int>box(n + 1 , 0);
    for(int &x : a) {
        cin>>x;
        box[x]++;
    }
    for(int &x : w) cin>>x;
    vector<int>id;
    int cnt = n;
    rep(i,1,n+1) {
        if(box[i] > 0) cnt--;
    }
    rep(i,0,n){
        if(box[a[i]] > 1) {
            id.push_back(i);
        }
    }
    sort(all(id) , [&](int i , int j){
        return w[i] < w[j];
    });
    int ans = 0;
    for(int i : id) {
        if(box[a[i]] > 1) {
            ans += w[i];
            cnt--;
            box[a[i]]--;
        }
        if(cnt == 0) break;
    }
    cout<<ans;
    return 0;
}
