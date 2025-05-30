/*https://codeforces.com/problemset/problem/2060/C*/
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
    vector<int> a(n),th(k + 5,0);
    for(int &x : a)cin >> x;
    for(int i = 0; i < n; i++){
        if(a[i] >= k) continue;
        th[a[i]]++;
    }
    int ans = 0;
    for(int i = 1; i < k; i++){
        if(i == k - i){
            ans += (th[i] >> 1);
            continue;
        }
        int minN = min(th[i],th[k - i]);
        th[i] -= minN;
        th[k - i] -= minN;
        ans += minN;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while(t--){
       solve();
    }
    return 0;
}