#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int N = 100;
vector<int> f(N + 1,0);

void ini(){
    f[0] = 0,f[1] = 1;
    for(int i = 2; i <= N ; i++) f[i] = f[i - 1] + f[i - 2];
}

void SG(const vector<int> &a){
    int n = *max_element(a.begin(),a.end());
    vector<int> sg(n + 1 ,0);

    for(int i = 1; i <= n; i++){
        vector<int> vis(n + 1,0);

        for(int j = 1; j <= 11; j++){
            if(i - f[j] < 0) break;
            vis[sg[i - f[j]]] = 1;
        }

        for(int s = 0; s <= n; s++){
            if(!vis[s]){
                sg[i] = s;
                break;
            }
        }
    }

    int res = 0;
    for(int x : a) res ^= sg[x];
}

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    SG(a);
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ini();
    solve();
    // SG();
    return 0;
}