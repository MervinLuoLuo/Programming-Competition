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
    map<int,int> freq;
    vector<int> ans(n + 1), diff(n + 2);
    for(int i = 0; i < n; i++) {
        int x;cin >> x;
        freq[x]++;
    }

    for(int i = 0; i <= n; i++){
        diff[freq[i]]++;
        diff[n - i + 1]--;
        if(freq[i] == 0) break;
    }

    for(int i = 0; i <= n; i++){
        if(i == 0) ans[i] = diff[i];
        else ans[i] = ans[i - 1] + diff[i];
    }

    for(auto it : ans) cout << it << " ";
    cout << endl;
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