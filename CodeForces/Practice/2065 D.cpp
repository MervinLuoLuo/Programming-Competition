/*https://codeforces.com/problemset/problem/2065/D*/
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
    int n,m;cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    vector<int> perfix(n);
    for(int i = 0; i < n; i++){
        for(auto it : a[i]) perfix[i] += it;
    }
    vector<int> pos(n);
    for(int i = 0; i < n;i++) pos[i] = i;
    sort(pos.begin(),pos.end(),[&](int a,int b){
        return perfix[a] > perfix[b];
    });
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += perfix[pos[i]] * (n - 1 - i) * m;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){
            ans += a[i][j] * (m - j);
        }
    }
    cout << ans << endl;
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