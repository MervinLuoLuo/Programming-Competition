/*https://www.luogu.com.cn/problem/P1481*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 2e5;
int tr[MAXN][26],dp[MAXN],idx = 0;
bool isw[MAXN];
int ans = 0;

void Insert(const string &s){
    int u = 0;
    int best = 0;
    for(int i = 0; i < s.size(); i++){
        int v = s[i] - 'a';
        if(!tr[u][v]) tr[u][v] = ++idx;
        u = tr[u][v];
        if(isw[u]) best = max(best,dp[u]);
    }

    isw[u] = 1;
    dp[u] = max(dp[u],best + 1);
    ans = max(ans,dp[u]);
}

void solve(){
    int n;cin >> n;
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        Insert(s);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}