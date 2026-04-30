#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 3000;

void solve(){
    int n;cin >> n;
    vector<bool> p(MAXN,1);
    for(int i = 2; i < MAXN; i++){
        if(p[i]){
            for(int j = i * 2; j < MAXN; j += i) {
                p[j] = 0;
            }
        }
    }

    int d = 2;
    while(p[n + d - 1] == 0) d++;

    int cur = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << cur << " ";
            cur++;
        }
        cout << endl;
        cur += d - 1;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}