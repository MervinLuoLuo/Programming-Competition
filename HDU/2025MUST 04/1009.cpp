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
    int sum = 0;
    vector<int> a(n);
    bool flag = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) flag = 0;
        sum += a[i];
    }
    if(sum < 2 * (n - 1) || !flag) no;
    else yes;
    
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