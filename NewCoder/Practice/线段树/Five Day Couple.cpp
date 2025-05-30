/*https://ac.nowcoder.com/acm/problem/15731*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
struct Node{
    int data;
    int lazy = 0;
};

int n;
vector<Node> tree;
vector<int> a;

void build(int l, int r, int cur){
    if(l == r){
        tree[cur].data = a[l];
        return;
    }
    int mid = l + (r - l) >> 1;
    build(2 * cur, l,mid);
    build(2*cur + 1,mid + 1, r);
    
}

void solve(){
    cin >> n;
    a.resize(n + 5);
    tree.resize(4*n);
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1,n,1);//建树
    int m;cin >> m;
    while(m--){
        int b,l,r;cin >> b >> l >> r;

    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}