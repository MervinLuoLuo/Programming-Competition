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
    vector<int> ans;
    int p  = 10;
    for(int k  = 1; k <= 18;k++){
        int d = p + 1;
        if(d > n) break;
        if(n % d == 0){int x = n / d;ans.push_back(x);}
        if(p > n / 10) break;
        p *= 10; 
    }
    if(ans.empty()) cout << 0 << endl;
    else{
        sort(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(int x : ans) cout << x << " ";
        cout << endl;
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