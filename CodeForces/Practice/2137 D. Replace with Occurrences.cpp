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
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        freq[b[i]]++;
    }

    for(auto &[u,v] : freq){
        if(v % u){
            cout << -1 << endl;
            return;
        }
    }

    vector<int> a(n + 1);
    vector<int> cur(n + 1);
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        if(freq[b[i]] % b[i] == 0){
            cur[b[i]] = cnt++;
        }
        a[i] = cur[b[i]];
        freq[b[i]]--;
    }

    for(int i = 1; i <= n; i++ )cout << a[i] << " ";
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