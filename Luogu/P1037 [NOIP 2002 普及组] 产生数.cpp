/*https://www.luogu.com.cn/problem/P1037*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
string s;
int k,l;
map<char,vector<char>> mp;
int vis[10];
vector<int> ans;

void dfs(char cur){
    vis[cur - '0'] = 1;
    for(int i = 0; i < mp[cur].size(); i++){
        if(!vis[mp[cur][i] - '0']) dfs(mp[cur][i]);
    }
}

void solve(){
    cin >> s >> k;
    int n = s.size();
    ans.resize(100);
    for(int i = 1;i <= k; i++){
        char x,y;
        cin >> x >> y;
        mp[x].push_back(y);
    }
    ans[0] = 1;
    for(int i = 0; i < n; i++){
        memset(vis,0,sizeof(vis));
        dfs(s[i]);
        int sum = 0;
        for(int i = 0;i < 10; i++) sum += vis[i];
        int x = 0;
        for(int i = 0; i < 100; i++){
            ans[i] = ans[i] * sum + x;
            x = ans[i] / 10;
            ans[i] %= 10;
        }
    }
    int i = 99;
    while(i > 0 and !ans[i]) i--;
    for(;i >= 0; i--) cout << ans[i];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}