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
    int n,q;cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    auto b = a;
    sort(b.begin() + 1,b.end(),greater<int>());
    map<int,int> sma,gre;
    int tar = n / 2;
    for(int i = 1; i <= n; i++){
        if(i <= tar) gre[b[i]]++;
        else sma[b[i]]++;
    }
    // for(auto it : gre) cout << it.first << " " << it.second << endl;
    while(q--){
        int p,v;cin >> p >> v;
        
        //在 n / 2 右边的操作没影响
        if(gre.find(a[p]) != gre.end()){
            gre[a[p]]--;
            if(gre[a[p]] == 0) gre.erase(a[p]);
            gre[a[p] + v]++;
        }
        //在 n / 2左边的操作
        else{
            sma[a[p]]--;
            if(sma[a[p]] == 0) sma.erase(a[p]);

            auto it = gre.begin();
            if(a[p] + v > (*it).first){
                gre[(*it).first]--;
                if(gre[(*it).first] == 0) gre.erase((*it).first);
                sma[(*it).first]++;
                gre[a[p] + v]++;
            }
            else sma[a[p] + v]++;
        }
        a[p] += v;
        int ans = n - (n / 2);
        if((*gre.begin()).first == (*sma.rbegin()).first) ans -= (*sma.rbegin()).second;
        cout << ans << endl;
    }
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