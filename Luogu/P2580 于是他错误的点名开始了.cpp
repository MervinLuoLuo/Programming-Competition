/*https://www.luogu.com.cn/problem/P2580*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 5e5 + 5;

struct Trie{ 
    int tr[MAXN][26],cnt[MAXN], idx = 0;
    
    void insert(const string &s){
        int u = 0;
        for(int i = 0; i < s.size(); i++){
            int v = s[i] - 'a';
            if(!tr[u][v]) tr[u][v] = ++idx;
            u = tr[u][v];
        }
        cnt[u] = 1;
    }

    int query(const string &s){
        int u = 0;
        for(int i = 0; i < s.size(); i++){
            int v = s[i] - 'a';
            if(!tr[u][v]) return -1;
            u = tr[u][v];
        }
        return u;
    }
}trie;

void solve(){
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        string s;cin >> s;
        trie.insert(s);
    }
    int q;cin >> q;
    while(q--){
        string s;cin >> s;
        int res = trie.query(s);
        if(res == -1 || trie.cnt[res] == 0) cout << "WRONG" << endl;
        else if(trie.cnt[res] == 1) {cout << "OK" << endl;trie.cnt[res] = 2;}
        else if(trie.cnt[res] == 2) cout << "REPEAT" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}