#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
string s;
int n;
set<string> res;
vii dp;

bool calc(string s,int &v){
    if(s.size() == 1 && isdigit(s[0])){
        v = s[0] - '0';
        return 1;
    }
    if(s.size() == 3 && isdigit(s[0]) && isdigit(s[2]) && ((s[1] == '+' || s[1] == '-' || s[1] == '*'))){
        int a = s[0] - '0',b = s[2] - '0';
        if(s[1] == '+') v = a + b;
        else if(s[1] == '-') v = a - b;
        else v = a * b;
        return 1;
    }
    return 0;
}

bool check(string s){
    vector<string> parts;
    string cur;
    for(char c : s){
        if(c == '='){
            if(cur.empty()) return 0;
            parts.push_back(cur);
            cur.clear();
        }
        else cur.push_back(c);
    }
    if(cur.empty()) return 0;
    parts.push_back(cur);
    if(parts.size() < 2) return 0;

    int val0;
    if(!calc(parts[0],val0)) return 0;
    for (size_t i = 1; i < parts.size(); i++) {
        int v;
        if (!calc(parts[i], v) || v != val0) return 0;
    }
    return 1;
}

void dfs(int l, int r, string le, string ri, int vis){
    if(l > r){
        string mid = le;
        reverse(ri.begin(),ri.end());
        res.insert(le + ri);
        return;
    }
    if(l == r){
        res.insert(le + s[l] + string(ri.rbegin(), ri.rend()));
        return;
    }
    if(s[l] == s[r] && dp[l][r] == dp[l + 1][r - 1]) dfs(l + 1, r - 1, le + s[l], ri + s[r], vis);
    else{
        if(dp[l][r] == dp[l + 1][r] + 1) dfs(l + 1,r,le + s[l],ri + s[l],vis + 1);
        if(dp[l][r] == dp[l][r - 1]  + 1) dfs(l,r - 1,le + s[r],ri + s[r],vis + 1);
    }
}

void solve(){
    cin >> s;
    n = s.size();
    res.clear();
    dp.assign(n,vector<int>(n,0));
    for(int len = 2;len <= n; len++){
        for(int i = 0; i < n + 1 - len; i++){
            int j = i + len - 1;
            if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min(dp[i + 1][j],dp[i][j - 1]) + 1;
        }
    }
    dfs(0,n - 1,"","",0);
    vector<string> ans(res.begin(),res.end());
    bool flag = 0;
    for(auto &cand : ans){
        if(check(cand)){
            flag = 1;
            break;
        }
    }
    if(flag) yes;
    else no;
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