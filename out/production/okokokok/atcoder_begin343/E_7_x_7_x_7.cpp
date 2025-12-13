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
    int v1,v2,v3; cin>>v1>>v2>>v3;
    // 343-(f1+f3-2*v3) + 343-(f2+f3-2*v3) + 343-(f1+f2-2*v3) - 3*v3;
    auto f=[&](int a,int b,int c,int a1,int b1,int c1){
        int x = min({a1,a,0})+7-max({a,a1,0});
        int y = min({b1,b,0})+7-max({b,b1,0});
        int z = min({c1,c,0})+7-max({c,c1,0});
        if(x<0||y<0||z<0) return 0;
        return x*y*z;
    };
    auto f1=[&](int a,int b,int c,int a1,int b1,int c1){
        int x = min(a,a1)+7-max(a1,a);
        int y = min(b,b1)+7-max(b,b1);
        int z = min(c,c1)+7-max(c,c1);
        if(x<0||y<0||z<0) return 0;
        return x*y*z;
    };
    rep(a,-7,8){
        rep(b,-7,8)
            rep(c,-7,8)
                rep(a1,-7,8)
                    rep(b1,-7,8)
                        rep(c1,-7,8){
                            int V3 = f(a,b,c,a1,b1,c1);
                            int V2 = f1(0,0,0,a,b,c) + f1(0,0,0,a1,b1,c1) + f1(a,b,c,a1,b1,c1)  - 3*v3;
                            int V1 = 343-(f1(0,0,0,a,b,c)+f1(0,0,0,a1,b1,c1)) + 343-(f1(a1,b1,c1,a,b,c)+f1(0,0,0,a1,b1,c1))
                            + 343-(f1(0,0,0,a,b,c)+f1(a,b,c,a1,b1,c1)) + 3*v3;
                            if(V1==v1&&v2==V2&&v3==V3){
                                cout<<"Yes\n";
                                cout<<"0 0 0"<<" "<<a<<" "<<b<<" "<<c<<" "<<a1<<" "<<b1<<" "<<c1;
                                return 0;
                            }
                        }
    }
    cout<<"No\n";
    return 0;
}
