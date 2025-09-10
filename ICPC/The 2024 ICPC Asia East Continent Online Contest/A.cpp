#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int ch;cin >> ch;
    int n = 31;
    vector<int> a(32,0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1,a.end());
    int pos = upper_bound(a.begin() + 1, a.end(), ch) - a.begin();
    
    if(pos < 3) cout << 32 << endl;
    else if(pos >= 3 && pos < 7) cout << 16 << endl;
    else if(pos >= 7 && pos < 14) cout << 8 << endl;
    else if(pos >= 14 && pos < 28) cout << 4 << endl;
    else if(pos >= 28 && pos < 32) cout << 2 << endl;
    else cout << 1 << endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}