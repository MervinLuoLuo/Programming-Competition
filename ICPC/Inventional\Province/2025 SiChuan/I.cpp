#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 3e5+5;

struct Tire{
    int idx = 0;
    int ch[MAXN][26],cnt[MAXN];
    void insert(const string& s){
        int u = 0;
        for(int i = 0; i < s.size(); i++){
            int v = s[i] - 'a';
            if(!ch[u][v]) ch[u][v] = ++idx;
            u = ch[u][v];
            cnt[u]++;
        }
    }  
    int query(const string &s){
        int u = 0;
        for(int i = 0; i < s.size(); i++){
            int v = s[i] - 'a';
            if(!ch[u][v]) return 0;;
            u = ch[u][v];
        }
        return cnt[u];
    }
}trie;

void solve(){
    int n;cin >> n;
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        reverse(s.begin(),s.end());
        trie.insert(s);
    }

    cout << trie.idx << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}