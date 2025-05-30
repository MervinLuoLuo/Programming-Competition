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
    int n;cin >> n;
    string s;cin >> s;
    int cnt = 0;
    ll ans = 0;
    for(auto it : s){
        if(it == '1') cnt++;
    }
    int now = 0;
    for(auto it : s){
        if(it == '0') ans += min(now,cnt - now);
        else now++;
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