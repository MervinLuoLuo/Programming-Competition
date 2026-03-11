/*https://www.luogu.com.cn/problem/P8306*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 3e6 + 5;

struct Trie{
    int ch[MAXN][63],cnt[MAXN],idx = 0;
    map<char,int > mp;// 映射
    void init(){
        int id = 0;
        for(char c = 'a'; c <= 'z' ; c++) mp[c] = ++id;
        for(char c = 'A'; c <= 'Z'; c++) mp[c] = ++id;
        for(char c = '0'; c <= '9'; c++) mp[c] = ++id;
    }

    void insert(string s){
        int u = 0;
        for(int i = 0; i < s.size(); i++){
            int v = mp[s[i]];
            if(!ch[u][v]) ch[u][v] = ++idx;
            u = ch[u][v];
            cnt[u]++;
        }
    }

    int query(string s){
        int u = 0;
        for(int i = 0; i < s.size(); i++){
            int v = mp[s[i]];
            if(!ch[u][v]) return 0;
            u = ch[u][v];
        }
        return cnt[u];
    }

    void Clear(){
        for(int i = 0; i <= idx; i++){
            cnt[i] = 0;
            for(int j = 0; j <= 62; j++) ch[i][j] = 0;
        }
        idx = 0;
    }
} trie;

void solve(){
    trie.Clear();trie.init();
    int n,q;cin >> n >> q;
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        trie.insert(s);
    }
    while(q--){
        string s;cin >> s;
        cout << trie.query(s) << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}