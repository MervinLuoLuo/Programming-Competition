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
    vector<int> p(n + 1),vis(n + 1, 0);
    p[n] = 1;
    vis[1] = 1;

    for(int i = 2; i <= n - 1; i++){
        p[i] = i ^ 1;
        vis[p[i]] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) {p[1] = i;break;}
    }

    for(int i = 1; i <= n; i++) cout << p[i] << " ";
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