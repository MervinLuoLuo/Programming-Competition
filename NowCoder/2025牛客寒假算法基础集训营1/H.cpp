#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

struct win{
    int l;
    int r;
    int pos;
    bool operator < (const win &a){
        return l < a.l;
    }
};

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<win> a(n + 5);
    for(int i = 1; i <= n; i++){
        int l, r;cin >> l >> r;
        a[i].l = l;a[i].r = r;
        a[i].pos = i;
    }
    sort(a.begin() + 1,a.begin() + 1 + n);
    vector<int> ans(n + 5);
    priority_queue<pii, vector<pii>,greater<pii>> q;
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        while(a[cnt].l <= i and cnt <= n){
            q.push({a[cnt].r,a[cnt].pos});
            cnt++;
        }
        if(q.empty()){cout << -1 << endl;return 0;}
        auto cur = q.top();
        q.pop();
        if(cur.first < i){
            cout << -1 << endl;
            return 0;
        }
        ans[cur.second] = i;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}