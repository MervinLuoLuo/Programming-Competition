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
    int n,k;cin >> n >> k;
    vector<int> a(n);
    vector<int> freq(n + 1,0);
    for(int i = 0; i < n ; i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    for(int i = 0; i <= n; i++){
        if(freq[i] % k){cout << 0 << endl; return;}
        else freq[i] /= k; 
    }

    vector<int> cnt(n + 1,0);
    int ans = 0;
    int l = 0, r = 0;
    while(l <= r && r < n){
        cnt[a[r]]++;
        while(cnt[a[r]] > freq[a[r]]){
            cnt[a[l]]--;l++;
        }
        ans += (r - l + 1);
        r++;
    }
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