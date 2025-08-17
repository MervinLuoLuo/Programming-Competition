#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int MAXN = 10005; 

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<bitset<MAXN>> pal(n);
    vector<bitset<MAXN>> valid(n);
    
    for(int i = 0; i < n; i++) pal[i][i] = 1;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]) pal[i][i + 1] = 1;
    }
    for(int len = 3; len <= n; len++){
        for(int i = 0; i < n - len + 1; i++){
            int j = i + len - 1;
            if(s[i] == s[j] && pal[i + 1][j - 1]) pal[i][j] = 1;
        }
    }
    
    vector<int> clet(n + 1, 0);
    for (int i = 0; i < n; i++) clet[i + 1] = clet[i] + (islower(s[i]) ? 1 : 0);
    
    vector<int> pre(n + 1, 0);
    for(int i = 0; i < n; i++){
        int delta = 0;
        if(s[i] == '(') delta = 1;
        else if(s[i] == ')') delta = -1;
        pre[i + 1] = pre[i] + delta;
    }
    
    int logn = 0;
    while ((1 << logn) <= n + 1) logn++;
    logn--;
    
    vector<vector<int>> st(logn + 1, vector<int>(n + 1));
    for(int i = 0; i <= n; i++) st[0][i] = pre[i];
    for(int k = 1; k <= logn; k++){
        for(int i = 0; i <= n + 1 - (1 << k); i++) st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
    
    auto getmin = [&](int l, int r){
        if(l > r) return INF;  // 改为 INF，避免 maxn 未定义
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    };
    
    for(int len = 2; len <= n; len++){
        for(int i = 0; i < n - len + 1; i++){
            int j = i + len - 1;
            bool flag = 0;
            int numl = clet[j + 1] - clet[i];
            if(numl == 0){
                int delta = pre[j + 1] - pre[i];
                if(delta == 0){
                    int mini = getmin(i + 1, j + 1);
                    if(mini >= pre[i]) flag = 1;
                }
            }
            bool h = valid[i][j - 1] || valid[i + 1][j] || flag;
            valid[i][j] = h;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(pal[i][j] && valid[i][j]) ans++;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}