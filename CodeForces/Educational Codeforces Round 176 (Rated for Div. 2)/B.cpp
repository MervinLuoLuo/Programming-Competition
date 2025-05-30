/*https://codeforces.com/contest/2075/problem/B*/
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
    int n,k;cin >> n >> k;
    vector<int> a(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(k == 1){
        int ans = a[1] + a[n];
        if(n > 2) ans = max(ans, (*max_element(a.begin() + 2, a.begin() + n) + max(a[1],a[n])));
        cout << ans << endl;
    }
    else{
        sort(a.begin() + 1,a.begin() + n + 1);
        int ans = 0;
        for(int i = n; i >= n - k; i--){
            ans += a[i];
        }
        cout << ans << endl;
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