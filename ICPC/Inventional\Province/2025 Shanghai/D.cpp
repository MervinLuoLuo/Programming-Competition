#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int a,b,x,y;cin >> a >> b >> x >> y;
    if(a == x && b == y) cout << "Yes" << endl;
    else if(a == x && b < y){
        if((b & y) == b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(b == y && a > x){
        if((a & x) == x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}