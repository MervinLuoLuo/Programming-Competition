#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n+5);
    map<int,int> pos;
    int ans = maxn;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        int cur = a[i];
        if(pos[cur] == 0) pos[cur] = i;
        else {
            ans = min(ans, i - pos[cur] + 1);
            pos[cur] = i;
        }
    }
    if(ans == maxn) cout << -1 << endl;
    else cout << ans << endl;
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