#include<bits/stdc++.h>
// #define int int64_t
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int N = 210;
int n, m;
int rkg, rks, rkb, pg, ps, pb;
int get10(const string &ss){
    int sum = 0, res = 1;
    for(int i = ss.size() - 1; i >= 0; --i){
        if(ss[i] == '1') sum += res;
        res *= 2;
    }
    return sum;
}
string getstr(int x){
    string res = "";
    while(x){
        if(x & 1 == 1) res += "1";
        else res += "0";
        x >>= 1;
    }
    return res;
}
int team[N];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        string ss; cin >> ss;
        team[i] = get10(ss);
    }
    cin >> rkg >> rks >> rkb;
    cin >> pg >> ps >> pb;
    for(int i = 1; i < (1 << n); ++i){
        pair<int, int> a[N];
        // int a[N], c[N]; // c : win_sum
        for(int j = 1; j <= m; ++j){
            a[j].first = team[j] & i;
            // cerr << getstr(a[j].first) << endl;
            a[j].second = __builtin_popcount(a[j].first);
        }
        sort(a + 1, a + m + 1, [](const auto &a, const auto &b){return
            a.second > b.second;    
        });
        // cerr << 1 << endl;
        if(a[rkg].second != pg || a[rks].second != ps || a[rkb].second != pb){
            // cerr << 1 << endl;
            continue;
        } 
        int ans = __builtin_popcount(i);
        if(ans > 13 || ans < 10){
            cout << -1 << endl;
            return ;
        }
        cout << ans << endl;
        cerr << i << endl;
        int ccnt = 0;
        string aans = "";
        while(i){
            if(i & 1 == 1){
                aans += '1';
                ccnt ++;
            }
            i >>= 1;
        }
        if(aans.size() < n){
            reverse(aans.begin(), aans.end());
            for(int o = aans.size(); o < n; ++o){
               aans += '0';
            }
        }
        reverse(aans.begin(), aans.end());
        cerr << "aans : " << aans << endl;
        cerr << endl << "ccnt : " << ccnt << endl;
        // for(int k = n - 1; k >= 0; --k){
        //     if(i & (1 << k) == (1 << k)){
        //         cout << (n - k) << " ";
        //     }
        // }
        // cout << endl;
        for(int i = 0; i < aans.size(); ++i){
            if(aans[i] == '1') cout << i + 1 << " ";
        }
        return;
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}