#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int x,y,X,Y;cin >> x >> y >> X >> Y;
    int dx = (abs(x - X) + 1) / 2,dy = (abs(y - Y) + 1) / 2;

    if(dx == 0 && dy == 0) {cout << 0 << endl;return;}
    if(dx == 0) dx = 2;
    if(dy == 0) dy = 2;
    cout << max(dx,dy) << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}