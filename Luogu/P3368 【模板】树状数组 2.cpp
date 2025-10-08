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
vector<int> tr1,tr2,a,diff;

int lowbit(int x){
    return x & (-x);
}

void add(int x,int k){
    int val = x * k;
    while(x <= n){
        tr1[x] += k;tr2[x] += val;
        x += lowbit(x);
    }
}

void add(int l,int r,int v){
    add(l,v);
    add(r + 1,-v);
}

int getsum(const vector<int> &tr,int x){
    int res = 0;
    while(x > 0){
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}

int getsum(int l,int r){
    int res = ((r + 1LL) * getsum(tr1,r) - getsum(tr2,r)) - 
            (l * getsum(tr1,l - 1) - getsum(tr2,l - 1));
    return res; 
}
void solve(){
    cin >> n >> q;
    tr1.assign(n + 1,0),tr2.assign(n + 1,0),a.assign(n + 1,0),diff.assign(n + 1,0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
        add(i,diff[i]);
    }

    while(q--){
        int op;cin >> op;
        if(op == 1){
            int x,y,k;cin >> x >> y >> k;
            add(x,y,k);
        }
        else {
            int x;cin >> x;
            cout << getsum(x,x) << endl;
        }
    }


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}