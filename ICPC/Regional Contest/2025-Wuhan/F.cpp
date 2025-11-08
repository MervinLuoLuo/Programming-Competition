#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(pii a,pii b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
void solve(){
    int n,q;cin >> n >> q;
    vector<pii> a(q + 1, {0,0});
    for(int i = 1; i <= q; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(),cmp);
    int cnt = 0,last = -maxn;
    for(int i = 1; i <= q; i++){
        if(a[i].first > last){
            cnt++;
            last = a[i].second;
        }
    }
    cnt += 1;
    int ans = ceill(log2(cnt));
    cout << ans << endl;
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