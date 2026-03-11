/*https://www.luogu.com.cn/problem/P3370*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<ull,ull>
#define VII vector<vector<int>>
using namespace std;
using ull = unsigned long long;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr ull base = 131;
constexpr ull MOD1 = 1e9 + 7, MOD2 = 212370440130137957;

ull Hash1(const string &s){
    int len = s.size();
    ull res = 0;
    for(int i = 0; i < len; i++) res = (res * base + s[i]) % MOD1;
    return res;
}

ull Hash2(const string &s){
    int len = s.size();
    ull res = 0;
    for(int i = 0; i < len; i++) res = (res * base + s[i]) % MOD2;
    return res;
}

bool cmp(const string &s, const string &t){
    bool flag1 = Hash1(s) != Hash1(s);
    bool flag2 = Hash2(s) != Hash2(t);
    return flag1 || flag2;
}


void solve(){
    int n;cin >> n;
    vector<PII> a(n + 1);
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        int h1 = Hash1(s),h2 = Hash2(s);
        a[i] = {h1,h2};
    }

    sort(a.begin() + 1,a.end());

    int ans = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i + 1]) ans++;
    }

    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}