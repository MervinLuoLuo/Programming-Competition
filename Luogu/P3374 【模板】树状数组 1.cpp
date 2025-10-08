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
int n,q;
vector<int> tree,a;

int lowbit(int x) {
    return x & (-x);
}

void add(int x,int k){
    while(x <= n){
        tree[x] += k;
        x += lowbit(x);
    }
}

int getsum(int x){
    int res = 0;
    while(x > 0){
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}

int getsum(int l,int r){
    int res = getsum(r) - getsum(l - 1);
    return res;
}

void solve(){
    cin >> n >> q;
    tree.assign(n + 1,0);a.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        add(i,a[i]);
    }

    while(q--){
        int op,x,y;cin >> op >> x >> y;
        if(op == 1){
            add(x,y);
        }
        else cout << getsum(x,y) << endl;

    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}