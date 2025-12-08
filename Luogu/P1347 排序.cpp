/*https://www.luogu.com.cn/problem/P1347*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;
int n,m, cnt = 0;
vector<int> ideg;
vector<int> stat, res;
vii g;

int topo(){
    res.clear();
    vector<int> tdeg = ideg;
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(stat[i] == 1 && tdeg[i] == 0) q.push(i);
    }


    bool uni = 1;
    while(!q.empty()){
        if(q.size() > 1) uni = 0;
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(int i = 0; i < g[u].size();i++){
            int v = g[u][i];
            tdeg[v]--;
            if(tdeg[v] == 0) q.push(v);
        }
    }
    
    // for(int x : res){
    //     char c = x + 'A';
    //     cerr << c;
    // }
    // cerr << " " << cnt << endl;
    if(res.size() != cnt) return 0;
    if(!uni) return 1;
    if(res.size() == n) return 2;
    return 1;
}

void solve(){
    cin >> n >> m;
    g.resize(n);
    ideg.assign(n,0),stat.assign(n, 0);
    for(int i = 1; i <= m; i++){
        string s;cin >> s;
        int u = s[0] - 'A', v = s[2] - 'A';
        if(stat[u] == 0){stat[u] = 1;cnt++;}
        if(stat[v] == 0){stat[v] = 1;cnt++;}
        ideg[v]++;
        g[u].push_back(v);

        int ans = topo();
        // cerr << 1 << endl;

        if(ans == 0){
            cout << "Inconsistency found after " << i << " relations.";
            return;
        }
        else if(ans == 2){
            cout << "Sorted sequence determined after "<< i << " relations: ";
            for(int x : res){
                char c = x + 'A';
                cout << c;
            }
            cout << "." << endl;
            return;
        }
    }

    cout << "Sorted sequence cannot be determined." << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}