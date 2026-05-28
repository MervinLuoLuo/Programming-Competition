#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),c(n + 1);
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        c[i] = a[i] - i;
        if(a[i] < i) flag = 0;
    }

    if(flag == 0){
        cout << -1 << endl;
        return;
    }

    int cur = 1;
    vector<int> b = {-1};
    b.push_back(1);
    int diff = a[1] - b[1];

    vector<int> suf(n + 1);
    suf[n] = n;
    for(int i = n - 1; i >= 1; i--){
        if(c[i] <= c[suf[i + 1]]){
            suf[i] = i;
        }
        else suf[i] = suf[i + 1];
    }


    for(int i = 2; i <= n; i++){
        cur++;
        int tar = a[suf[i]] - suf[i] + i;

        if(tar > cur + diff){
            cur += diff;
            diff = 0;
            b.push_back(cur);
            diff += a[i] - b[i];
        }
        else{
            b.push_back(tar);
            diff -= (tar - cur);
            diff += a[i] - b[i];
            cur = tar;
        }
    }

    cout << cur + diff<< endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
