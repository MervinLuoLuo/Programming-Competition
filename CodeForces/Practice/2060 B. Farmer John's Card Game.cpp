/*https://codeforces.com/problemset/problem/2060/B*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)cin >> a[i][j];
    }
    vector<pii> ans(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        sort(a[i].begin(),a[i].end());
        for(int j = 0; j < m - 1; j++){
            if(a[i][j + 1] != a[i][j] + n) {no;return;}        
        }
        ans[i].first = a[i][0];ans[i].second = i + 1;  
    }
    sort(ans.begin(),ans.end());
    for(auto it : ans) cout << it.second << " ";
    cout << endl;
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