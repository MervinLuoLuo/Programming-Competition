/*https://codeforces.com/problemset/problem/1989/B*/
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
    string a,b;cin >> a;
    cin >> b;
    int n = a.size(),m = b.size();
    int ans = n + m;
    for(int i = 0; i < m; i++){
        int j = i;
        for(auto c : a){
            if(j < m && c == b[j]) j++;
        }
        ans = min(ans,n + m - (j - i));
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
