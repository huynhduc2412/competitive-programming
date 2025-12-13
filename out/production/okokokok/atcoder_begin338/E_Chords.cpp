#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define coutvc(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
const int mxN=2e5;
using namespace std;
void Solve(){
    int n; cin>>n;
    array<int,2>a[n];
    rep(i,0,n){
        cin>>a[i][0]>>a[i][1];
        if(a[i][0]>a[i][1]) swap(a[i][0],a[i][1]);
    } 
    sort(a,a+n);
    set<int>s;
    rep(i,0,n){
        auto it=s.lower_bound(a[i][1]);
        if(it==s.begin()){
            s.insert(a[i][1]);continue;
        }
        if(it!=s.begin()) --it;
        if((*it)>a[i][0]){
            cout<<"Yes";return;
        }
        s.insert(a[i][1]);
    }   
    cout<<"No";
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
