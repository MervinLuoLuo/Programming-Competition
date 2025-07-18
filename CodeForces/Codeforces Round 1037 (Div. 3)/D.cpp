#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

class node{
    public:
    int l,r;
    int val;
};

void solve(){
    int n,k;cin >> n >> k;
    vector<node> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r >> a[i].val;
    }
    sort(a.begin(),a.end(),[](const node &a,const node &b){
        return a.l < b.l;
    });

    int ans = k;
    int i = 0;
    priority_queue<int> q;
    while(1){
        while(i < n && a[i].l <= ans){q.push(a[i].val); i++;}
        while(!q.empty() && q.top() <= ans) q.pop();

        if(q.empty()) break;
        ans = q.top();q.pop();
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}