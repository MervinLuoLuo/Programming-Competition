#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n,0);
    for(int &x : a) cin >> x;
    
    int ans = n - 1;
    int l = 0, r = MAXN;
    int cur = 0,ft = 1;
    for(int i = 1; i < n; i++){
        cur = (a[i] - a[i - 1]) - cur;
        if(i % 2 == ft % 2){//奇数
            r = min(r,cur);
            if(i < n - 1) l = max(l,cur-(a[i + 1] - a[i]));
        }

        else{//偶数
            l = max(l ,-cur);
            if(i < n - 1) r = min(r ,(a[i + 1] - a[i]) - cur);
        }

        if(l >= r){
            // 交集首次为空 更新答案,重置区间
            ans--;
            l = 0,r = MAXN;
            cur = 0;
            ft = i + 1;
        }
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}