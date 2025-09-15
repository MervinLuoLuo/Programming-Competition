#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e5;

int is_com[maxn + 1];
vector<int> prime;

void Prime(){
    for(int i = 2; i <= maxn; i++){
        if(!is_com[i]) prime.push_back(i);
        for(int p : prime){
            if (1LL * i * p > maxn) break;
            is_com[i * p] = true;
            if (i % p == 0) break;  // 保证每个合数只被最小质因子筛掉
        }
    }
}

void solve(){
    int s;cin >> s;
    if(s < 2){cout << 0 << endl;return;}
    int res = 0;
    vector<int> ans;
    for(int p : prime){
        if(res +  p <= s){
            res += p;
            ans.push_back(p);
        }
    }
    for(int i : ans) cout << i << endl;
    cout << ans.size() << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    Prime();
    solve();
    return 0;
}