#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n;cin>> n;
    string s;cin >> s;
    ll ans = 0, v = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '0'){v += 10;ans += v;}
        if(s[i] == '1'){v = max(0LL ,v - 5);ans += v;}
        if(s[i] == '2'){v -= 10 ;
            if(v >= 0) ans += v;
            v += 10;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}