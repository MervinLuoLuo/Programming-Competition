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
    int n,m,l,r;cin >> n >> m >> l >> r;
    for (int x = 0; x <= m; ++x) {
        int lp = -x;
        int rp = m - x;
        if (lp >= l and rp <= r) {
            cout << lp << " " << rp << endl;
            break;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}