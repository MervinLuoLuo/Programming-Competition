/*https://www.luogu.com.cn/problem/P3811*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 4 * 1e6;
vector<int> invs(MAXN,1);

void Inv(int n,int p){
    invs[1] = 1;
    for(int i = 2;i <= n; i++) invs[i] = (p - p / i) * invs[p % i] % p;
}

void solve(){
    int n,p;cin >> n >> p;
    Inv(n,p);
    for(int i = 1; i <= n; i++){
        cout << invs[i] << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}