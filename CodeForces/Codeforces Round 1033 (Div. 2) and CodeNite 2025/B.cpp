#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,s;cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int dx,dy,x,y;cin >> dx >> dy >> x >> y;
        if(dx == dy) ans += (x == y);
        else ans += (x + y == s);
    }
    cout << ans << endl;
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}