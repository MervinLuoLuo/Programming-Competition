#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int MAXN = 1e9;
constexpr int INF = 1e18;
struct Node{
    int v;
    int x,y;
    bool operator<(const Node& other) const{
        return v < other.v;
    }
};

void solve(){
    int n,m,k;cin >> n >> m >> k;
    vector<int> col(n + 1,0),line(m + 1, 0);
    VII g(n + 1,vector<int>(m + 1,0));
    priority_queue<Node> pq;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int v;cin >> v;
            g[i][j] = v;
            pq.push({v,i,j});
        }
    }
    while(k && !pq.empty()){
        auto [v,x,y] = pq.top();
        pq.pop();
        if(col[x] == 1 || line[y] == 1) continue;
        else{
            col[x] = 1,line[y] = 1;
            k--;
        }
    }

    int fic = n;
    for(int i = n; i >= 1; i--){
        if(col[i] == 0){
            fic = i;
            break;
        }
    }
    int fil = m;
    // for(int i = 1; i <= m; i++) cerr << line[i] << " ";
    for(int i = m; i >= 1; i--){
        if(line[i] == 0){
            fil = i;
            break;
        }
    }
    // cerr << fil << endl;
    for(int i = 1; i <= fic; i++){
        if(col[i] == 1) continue;
        for(int j = 1; j <= fil; j++){
            if(line[j] == 1) continue;
            cout << g[i][j] << (j != fil ? " " : "");
        }
        if(i != fic) cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}