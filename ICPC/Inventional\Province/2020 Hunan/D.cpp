#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
using ull = unsigned long long;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int B = 131;
constexpr int MOD = 1e9 + 7;

int n;
vector<string> S;

int getH(const string& s){
    ull res = 0;
    for(char c : s) res = (res * B + c) % MOD;
    return res;
}

int qpow(int a,int e){
    int res = 1;
    a %= MOD;
    while(e){
        if(e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

void solve(){
    S.clear();S.resize(n);
    for(string &s : S) cin >> s;
    unordered_map<int,ull> mp;
    for(const string s : S){
        int Hash = getH(s) % MOD;
        int len = s.size();
        int Len = qpow(B,len) - 1;
        int inv = qpow(Len,MOD - 2);
        int res = Hash * inv % MOD;
        mp[res]++;
    }

    ull ans = 0;
    for(auto &[x,cnt] : mp){
        if(cnt > 1){
            int res = cnt * (cnt - 1) / 2;
            ans += res;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin >> n)
    solve();
    return 0;
}