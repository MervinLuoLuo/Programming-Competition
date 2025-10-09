/*https://loj.ac/p/6280*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,len;
vector<int> a,b,id,s;

void add(int l,int r,int v){
    int lid = id[l],rid = id[r];
    if(lid == rid){
        for(int i = l; i <= r; i++) a[i] += v, s[lid] += v;
        return;
    }

    for(int i = l; id[i] == lid; i++) a[i] += v,s[lid] += v;
    for(int i = lid + 1; i < rid; i++){
        b[i] += v; s[i] += len * v;
    }
    for(int i = r; id[i] == rid; i--) a[i] += v,s[rid] += v;
}

int query(int l,int r,int c){
    int lid = id[l],rid = id[r];
    int res = 0;
    if(lid == rid){
        for(int i = l; i <= r; i++) res = (res + a[i] + b[lid]) % c;
        return res;
    }
    for(int i = l; id[i] == lid; i++) res = (res +a[i] + b[lid]) % c;
    for(int i = lid + 1; i < rid; i++) res = (res + s[i]) % c;
    for(int i = r; id[i] == rid; i--) res = (res + a[i] + b[rid]) % c;
    return res;
}

void solve(){
    cin >> n;
    len = sqrt(n);//块长
    int tot = (n - 1) / len + 1;//块数
    a.assign(n + 1, 0);//值
    b.assign(tot + 1,0);//懒标记
    id.assign(n + 1, 0);//块编号
    s.assign(tot + 1 ,0);//整块元素和
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = (i - 1) / len + 1;
        s[id[i]] += a[i];
    }
    int q = n;

    while(q--){
        int op, l, r, c;cin >> op >> l >> r >> c;
        if(op == 0) add(l,r,c);
        else cout << query(l,r,c + 1) << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}