#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

int calc(int x,int y,int z,int n){
    int xx = n / x;
    int xy = n / lcm(x,y);
    int xz = n / lcm(x,z);
    int xyz = n / lcm(lcm(x,y),z);
    int res = (xx - xy - xz + xyz) * 6 + (xy + xz - 2 * xyz) * 3 + xyz * 2;
    return res;
}

void solve(){
    int a,b,c,m;cin >> a >> b >> c >> m;
    cout << calc(a,b,c,m) << " " << calc(b,a,c,m) << " "<< calc(c,a,b,m) << endl; 
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}