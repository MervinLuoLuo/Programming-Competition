#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1,a.end());

    int ans = 1;
    for(int i = 1; i <= n; i++){
        int pos = i;
        for(int j = i; j <= n; j++){
            if(a[i] == a[j]){
                ans = max(ans,j - i + 1);
            }
            else{
                int k = 2 * a[j] - a[i];
                while(pos < n && a[pos + 1] <= k) pos++;
                if(a[pos] != k) continue;
                int a = min(j - i + 1,pos - j) * 2;
                int b = min(j - i,pos - j) * 2 + 1;
                ans = max({ans,a,b});
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}