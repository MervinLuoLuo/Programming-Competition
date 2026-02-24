#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,q,s;cin >> n >> q >> s;
    vector<int> t(n + 2,0);
    t[1] = s;
    for(int i = 1; i <= n; i++){
        int T;cin >> T;
        t[i + 1] = t[i] + T;
    }
    while(q--){
        int x,y;cin >> x >> y;
        cout << t[x] + y - 1 << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}