#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define vii vector<vector<int>>
const int MAXN = 1e8;
const int INF = 1e18;

void solve(){
    int n,q;cin >> n >> q;
    vector<pii> a(n + 1);
    map<int,int> mp;
    map<int,int> freq;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = mp[a[i].first];
        mp[a[i].first] = i;
        freq[a[i].first]++;
    }

    while(q--){
        int x,y;cin >> x >> y;
        if(mp[x] == 0 || mp[y] == 0) {cout << 0 << endl;continue;}
        

    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}