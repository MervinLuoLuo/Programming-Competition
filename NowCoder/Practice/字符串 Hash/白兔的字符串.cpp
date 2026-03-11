/*https://ac.nowcoder.com/acm/problem/15253*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using ull = unsigned long long;
constexpr int INF = 1e18;
constexpr int MAXN = 2e6 + 5; 

string T;
vector<ull> Base(MAXN);
vector<ull> THash,allHash;  

ull getHash(const vector<ull> &h, int l,int r){
    if(l == 0) return h[r];
    ull res = h[r] - h[l - 1] * Base[r - l + 1];
    return res;
}

void ini(){
    Base[0] = 1;
    for(int i = 1; i < MAXN; i++) Base[i] = Base[i - 1] * 131;
    cin >> T;
    int n = T.size();
    T = T + T;
    int len = T.size();
    THash.assign(len, 0);
    THash[0] = T[0];
    for(int i = 1; i < len; i++) THash[i] = (THash[i - 1] * 131 + T[i]);

    for(int i = 0; i < n; i++) allHash.push_back(getHash(THash,i,i + n - 1));
    sort(allHash.begin(),allHash.end());
    allHash.erase(unique(allHash.begin(),allHash.end()),allHash.end());
}

void solve(){
    string s;cin >> s;
    int n = s.size(),m = T.size() / 2;

    vector<ull> SHash(n,0);
    SHash[0] = s[0];
    for(int i = 1; i < n; i++) SHash[i] = (SHash[i - 1] * 131 + s[i]);

    int ans = 0;
    for(int i = 0; i + m - 1 < n; i++){
        ull cur = getHash(SHash,i,i + m - 1);
        if(binary_search(allHash.begin(),allHash.end(),cur)) ans++;
    }

    cout << ans << endl;
}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ini();
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}