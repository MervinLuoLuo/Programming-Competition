#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
vector<int> fb;

void solve(){
    int n,m;cin >> n >> m;
    for(int i = fb.size(); i < n; i++){
        fb.push_back(fb[i - 1] + fb[i - 2]);
    }
    for(int i = 0; i < m; i++){
        int w,l,h;cin >> w >> l >> h;
        int need = fb[n - 1] + fb[n - 2];
        if(w >= need || l >= need || h >= need){
            if(w >= fb[n - 1] && l >= fb[n - 1] && h >= fb[n - 1]) cout << 1;
            else cout << 0;
        }
        else cout << 0;
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    fb.push_back(1);fb.push_back(2);
    while(t--){
        solve();
    }
    return 0;
}