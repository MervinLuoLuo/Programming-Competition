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
    int n,m;cin >> n >> m;
    vector<int> a(n),b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    for(int i = 0; i < m; i++){
        auto it = find(a.begin(),a.end(),b[i]);
        if(it != a.end()) a.erase(it);
    }
    for(auto it : a) cout << it << " ";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}