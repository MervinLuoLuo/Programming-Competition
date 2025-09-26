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
    int n,k;cin >> n >> k;
    map<int,int> freq;
    for(int i = 0; i < n; i++) {
        int x;cin >> x;
        freq[x]++;
    }

    int need = 0;
    for(int i = 0; i < k; i++){
        if(freq[i] == 0) need++;
    }

    cout << max(need ,freq[k]) << endl;
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