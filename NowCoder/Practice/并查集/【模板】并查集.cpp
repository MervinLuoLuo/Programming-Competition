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
vector<int> p;
vector<int> h;

int Find(int x){
    if(p[x] == x) return p[x];
    
    else return p[x] = Find(p[x]);//路径压缩
}

void Union(int x,int y){
    int rootx = Find(x);
    int rooty = Find(y);
    
    if(rootx != rooty){
        if(h[rootx] < h[rooty]) p[rootx] = rooty;
        else if(h[rootx] > h[rooty]) p[rooty] = rootx;
        else {p[rootx] = rooty;h[rooty]++;}
    }
}

void solve(){
    int n;cin >> n;
    p.assign(n + 5,0);h.assign(n + 5, 1);
    for(int i = 1; i <= n; i++) p[i] = i;

    int m;cin >> m;
    for(int i = 0; i < m; i++){
        int u,v;cin >>u >>v;
        Union(u,v);
    }    

    map<int,int> ans;
    for(int i = 1; i <= n; i++){
        ans[Find(i)]++;
    }
    int maxx = -1;
    for(auto it : ans){
        if(it.second > maxx) maxx = it.second;
    }
    cout << ans.size() << " " << maxx;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}