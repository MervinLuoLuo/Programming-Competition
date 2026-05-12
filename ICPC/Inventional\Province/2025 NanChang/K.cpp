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
    int n;cin >> n;
    VII cnt(4);
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        int d = x % 4;
        cnt[d].push_back(i);
    }

    int c1 = cnt[1].size(),c2 = cnt[2].size(),c3 = cnt[3].size();
    int minc = min(c1,c3);
    if(c1 % 2 != c3 % 2){
        cout << -1  << endl;
        return;
    }

    auto calc = [&](int d){
        int res1 = (c1 - d) / 2;
        int res3 = (c3 - d) / 2;
        int res2 = c2 - res1 - res3;
        
        if(res2 < 0 || (res2 % 2 == 1)) return 0;
        int res = res2 / 2;

        // 把余数为 0 的输出出来
        for(int &x : cnt[0]) cout << x << " ";
        //　输出 1 + 1 + 2
        for(int i = 1; i <= res1; i++){
            // 直接从后面拿，方便操作
            cout << cnt[2].back() << " ";
            cnt[2].pop_back();
            cout << cnt[1].back() << " ";
            cnt[1].pop_back();
            cout << cnt[1].back() << " ";
            cnt[1].pop_back();
        }
        //输出 3 + 3 + 2
        for(int i = 1; i <= res3; i++){
            cout << cnt[3].back() << " ";
            cnt[3].pop_back();
            cout << cnt[3].back() << " ";
            cnt[3].pop_back();
            cout << cnt[2].back() << " ";
            cnt[2].pop_back();
        }
        
        // 输出 2 + 2
        for(int i = 1; i <= res; i++){
            cout << cnt[2].back() << " ";
            cnt[2].pop_back();
            cout << cnt[2].back() << " ";
            cnt[2].pop_back();
        }

        // 输出 1 + 3
        for(int i = 1; i <= d; i++){
            cout << cnt[3].back() << " ";
            cnt[3].pop_back();
            cout << cnt[1].back() << " ";
            cnt[1].pop_back();
        }
        cout << endl;
        return 1;
    };

    if(c1 & 1){
        for(int d = 1; d <= minc; d += 2){
            bool flag = calc(d);
            if(flag) return;
        }
    }
    else{
        for(int d = 0; d <= minc; d += 2){
            bool flag = calc(d);
            if(flag) return;
        }
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}