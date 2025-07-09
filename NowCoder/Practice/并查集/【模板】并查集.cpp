/*https://ac.nowcoder.com/acm/problem/226370*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

vector<int> fa,s;

int find(int x){
    if(fa[x] != x) fa[x] = find(fa[x]);//路径压缩
    return fa[x];
}
void solve(){
    int n,m;cin >> n >> m;
    fa.resize(n + 5);s.resize(n + 5,1);
    for(int i = 1; i <= n;i++) fa[i] = i;
    for(int i = 1; i <= m; i++){
        int u,v;cin >> u >> v;
        int x = find(u),y = find(v);
        if(x != y){
            fa[x] = y;
            s[y] += s[x];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(fa[i] == i) ans++;
    }
    cout << ans << " " << *max_element(s.begin(),s.end()) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}