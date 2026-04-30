/*https://acm.hdu.edu.cn/contest/problem?cid=1200&pid=1007*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,s;cin >> n >> s;
    vector<int> a(n);
    bool flag = 0;
    int idx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == s) {
            flag = 1;
            idx = i;
        }
    }
    if(!flag){
        cout << "NO" << endl;
        return;
    }

    flag = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != a[idx] && a[i] != 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}