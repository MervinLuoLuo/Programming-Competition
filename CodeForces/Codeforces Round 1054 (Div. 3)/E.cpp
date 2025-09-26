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
    int n,k,l,r;cin >> n >> k >> l >> r;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    map<int,int> mp1,mp2;
    int j1 = 0,j2 = 0;
    int cnt1 = 0,cnt2 = 0;
    int ans = 0;

    for(int i = 1; i <= n; i++){
        while((cnt1 < k) && (j1 <= n)){
            if((++j1) <= n){
                if(++mp1[a[j1]] == 1) cnt1++;
            }
        }

        while(cnt2 <= k && j2 <= n){
            if(++j2 <= n){
                if(++mp2[a[j2]] == 1) cnt2++;
            }
        }
        
        ans += max(0LL,(min(r,j2 - i) - max(l,j1 - i + 1) + 1));
        if(--mp1[a[i]] == 0) cnt1--;
        if(--mp2[a[i]] == 0) cnt2--;
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