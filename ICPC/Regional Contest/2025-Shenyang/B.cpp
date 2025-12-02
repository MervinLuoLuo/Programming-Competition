#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n, m, a, b;cin >> n >> m >> a >> b;
    map<int,int> freq;
    vii g(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
            freq[g[i][j]]++;
        }
    }
    vector<pii> fre(freq.begin(), freq.end());
    sort(fre.begin(), fre.end(), [&](pii &x, pii &y){
        return x.second > y.second;
    });

    int ans;
    int pos0 = -1;
    for(int i = 0; i < fre.size(); i++) {
        if(fre[i].first == 0) pos0 = i;
    }

    if(fre[0].first == 0){
        int res = 0;
        int layer = 0;
        for(int i = 1; i < fre.size(); i++){
            int tmp1 = b * fre[0].second + layer * b * fre[i].second;
            int tmp2 = a * fre[i].second;
            if(tmp1 > tmp2){
                res += tmp2;
            } else {
                res += tmp1;
                layer++;
            }
        }
        ans = res;
    }
    else{
        int res1 = 0;
        int cnt = 1;
        int zero = -1;

        for(int i = 1; i < fre.size(); i++){
            if(fre[i].first != 0){
                int tmp1 = fre[i].second * a;
                int tmp2 = fre[i].second * b * cnt;
                if(tmp1 > tmp2){
                    res1 += tmp2;
                    cnt++;
                } else {
                    res1 += tmp1;
                }
            }else zero = i;
        }
        if(zero >= 0){
            res1 += fre[zero].second * b * cnt;
        }
        ans = res1;

        if(pos0 >= 0){
            int res2 = 0;
            int layer = 0;
            for(int i = 0; i < fre.size(); i++){
                if(fre[i].first != 0){
                    int tt1 = fre[i].second * a;
                    int tt2 = b * fre[pos0].second + layer * b * fre[i].second;
                    if(tt2 > tt1){
                        res2 += tt1;
                    } else {
                        res2 += tt2;
                        layer++;
                    }
                }
            }
            ans = min(ans, res2);
        }
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