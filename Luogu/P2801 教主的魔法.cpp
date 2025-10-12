/*https://www.luogu.com.cn/problem/P2801*/
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
int n, q;
int len, tot;
vector<int> a, tmp, id, L, R, lazy;

void build() {
    len = sqrt(n);//块长
    tot = (n + len - 1) / len;//块总数
    id.assign(n + 1, 0);//块编号
    L.assign(tot + 2, 0);//块左界
    R.assign(tot + 2, 0);//块右界
    lazy.assign(tot + 2, 0);//懒标记

    for (int i = 1; i <= n; i++) id[i] = (i - 1) / len + 1;
    for (int i = 1; i <= tot; i++) {
        L[i] = (i - 1) * len + 1;
        R[i] = min(i * len, n);
        //块内排序
        sort(tmp.begin() + L[i], tmp.begin() + R[i] + 1);
    }
}

//单块加
void add_part(int id, int st, int ed, int val) {
    for (int i = st; i <= ed; i++) a[i] += val;
    for (int i = L[id]; i <= R[id]; i++) tmp[i] = a[i];
    //块内排序
    sort(tmp.begin() + L[id], tmp.begin() + R[id] + 1);
}

//总加
void add(int l, int r, int val) {
    if (id[l] == id[r]) {
        add_part(id[l], l, r, val);
        return;
    }
    add_part(id[l], l, R[id[l]], val);
    add_part(id[r], L[id[r]], r, val);
    for (int i = id[l] + 1; i < id[r]; i++) lazy[i] += val;
}

//单块询问
int query_part(int bid, int st, int ed, int k) {
    int res = 0;
    for (int i = st; i <= ed; i++)
        if (a[i] + lazy[bid] >= k) res++;
    return res;
}

//总询问
int query(int l, int r, int k) {
    if (id[l] == id[r]) return query_part(id[l], l, r, k);
    int ans = 0;
    ans += query_part(id[l], l, R[id[l]], k);
    ans += query_part(id[r], L[id[r]], r, k);
    for (int i = id[l] + 1; i < id[r]; i++) {
        //二分找当前块内大于 k 的第一个数的位置
        int pos = lower_bound(tmp.begin() + L[i], tmp.begin() + R[i] + 1, k - lazy[i]) - (tmp.begin() + L[i]);
        ans += (R[i] - L[i] + 1) - pos;
    }
    return ans;
}

void solve() {
    cin >> n >> q;
    a.assign(n + 1, 0);//值
    tmp.assign(n + 1, 0);//副本(用于排序)
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    build();

    while (q--) {
        char op;int l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 'M') add(l, r, c);
        else cout << query(l, r, c) << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}