#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m;
vector<int> a,b;

bool check(int v){
    int i = n,j = n + 1;
    i128 res = 0;
    while(i >= 1 && a[i] > v){
        res += a[i] * b[j];
        i--;j--;
    }
    res += v * b[j];
    for(; i >= 1; i--) res += a[i] * b[i];
    if(res >= m) return 1;
    else return 0;
}

void solve(){
    cin >> n >> m;
    a.assign(n + 1, 0),b.assign(n + 2, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n + 1; i++) cin >> b[i];
    sort(a.begin() + 1,a.end());
    sort(b.begin() + 1,b.end());

    int l = 0, r = m;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}