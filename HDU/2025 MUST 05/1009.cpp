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
    int n;cin >> n;
    vector<int> a(n),b(n),posb(n + 1);
    for(int &x : a) cin >> x;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        posb[b[i]] = i;
    }
    int k = 1;
    for(int i = 0;i < n - 1; i++){
        if(posb[a[i + 1]] != posb[a[i]] + 1) k++;
    }
    cout << k << endl;
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