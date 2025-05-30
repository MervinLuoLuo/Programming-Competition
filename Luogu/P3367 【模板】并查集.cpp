/*https://www.luogu.com.cn/problem/P3367*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
vector<int> dsu;

int find(int x){
    if(dsu[x] != x) dsu[x] = find(dsu[x]);
    return dsu[x];
}

void solve(){
    int n,m;cin >>n >> m;
    dsu.resize(n + 5);
    for(int i = 1; i <= n; i++) dsu[i] = i;
    while(m--){
        int op,x,y;cin >> op >> x >> y;
        int fx = find(x),fy = find(y);
        if(op == 1){
            if(fx != fy) dsu[fx] = fy;
        }
        else{
            if(fx == fy) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << i << " " << dsu[i] << endl;
    // }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}