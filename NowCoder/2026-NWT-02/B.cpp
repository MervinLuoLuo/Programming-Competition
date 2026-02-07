#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    int maxx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        maxx = max(maxx, a[i]);
    }

    if(mp[maxx] % 2 == 1){
        for(int i = 0; i < n; i++){
            if(a[i] == maxx) cout << 1;
            else cout << 0;
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(a[i] == maxx) cout << 0;
            else cout << 1;
        }
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}